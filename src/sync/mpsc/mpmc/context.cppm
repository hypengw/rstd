module;
#include <atomic>
#include <memory>
#include <concepts>
#include <optional>
#include <variant>
#include <thread>
export module mpmc:context;

namespace mpmc
{
auto current_thread_id() -> std::size_t {
    // `u8` is not drop so this variable will be available during thread destruction,
    // whereas `thread::current()` would not be
    thread_local char DUMMY { 0 };
    return reinterpret_cast<std::size_t>(&DUMMY);
}

enum class Operation
{
    Resume = 0,
    Drop,
};
struct EnumSelected {
    /// Still waiting for an operation.
    struct Waiting {
        constexpr operator int() { return 0; }
    };
    /// The attempt to block the current thread has been aborted.
    struct Aborted {
        constexpr operator int() { return 1; }
    };
    /// An operation became ready because a channel is disconnected.
    struct Disconnected {
        constexpr operator int() { return 2; }
    };

    /// An operation became ready because a message can be sent or received.
    struct Operation {
        constexpr       operator int() { return 3; }
        mpmc::Operation oper;
    };

    using type = std::variant<Waiting, Aborted, Disconnected, Operation>;
};

using Selected = EnumSelected::type;

struct Inner {
    /// Selected operation.
    std::atomic_size_t select;

    /// A slot into which another thread may store a pointer to its `Packet`.
    std::atomic<void*> packet;

    /// Thread handle.
    std::thread thread;

    /// Thread id.
    std::size_t thread_id;
};
export struct Context {
    std::shared_ptr<Inner> inner;

    Context()
        : inner(std::make_shared<Inner>((int)EnumSelected::Waiting {}, nullptr, std::thread {},
                                        current_thread_id())) {}

    template<typename F, typename R>
        requires requires(F t, Context& c) {
            { F(c) } -> std::same_as<R>;
        }
    auto with(F&& f) -> R {
        thread_local std::optional<Context> CONTEXT { Context {} };
        //        CONTEXT
        //            .try_with(|cell| match cell.take() {
        //                None => f(&Context::new()),
        //                Some(cx) => {
        //                    cx.reset();
        //                    let res = f(&cx);
        //                    cell.set(Some(cx));
        //                    res
        //    }
        //            })
        //            .unwrap_or_else(|_| f(&Context::new()))
    } // namespace mpmc
};

} // namespace mpmc