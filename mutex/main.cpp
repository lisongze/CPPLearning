#include <iostream>
#include <mutex>
#include <thread>

int        g_i = 0;
std::mutex g_i_mutex;  // protects g_i

void safe_increment()
{
    for (size_t i = 0; i < 100; i++)
    {
        std::lock_guard<std::mutex> lock(g_i_mutex);
        ++g_i;

        std::cout << std::this_thread::get_id() << ", iter: " << i << " " << g_i << '\n';

        // g_i_mutex is automatically released when lock
        // goes out of scope
    }
}

int main()
{
    std::cout << "main: " << g_i << '\n';

    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    t1.join();
    std::cout << "t1 join..." << std::endl;
    t2.join();
    std::cout << "t2 join..." << std::endl;

    std::cout << "main: " << g_i << '\n';

    return 0;
}