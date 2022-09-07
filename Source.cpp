#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mut1;
std::mutex mut2;
std::mutex mut3;
std::mutex mut4;
std::mutex mut5;

class Threads
{
public:
	void ManyThread1()
	{
		std::unique_lock<std::mutex>slk{ mut1 };
		while (true)
		{
			std::cout << "useful information 1 ";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
	    }
        slk.unlock();
	}
	void ManyThread2()
	{
		std::unique_lock<std::mutex> slk1(mut2);
		while (true)
		{
			std::cout << "useful information 2 ";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		slk1.unlock();
	}
	void ManyThread3()
	{
		std::unique_lock<std::mutex> slk2(mut3);
		while (true)
		{
			std::cout << "useful information 3 ";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
;     slk2.unlock();
	}
	void ManyThread4()
	{
		std::unique_lock<std::mutex> slk3(mut4);
		while (true)
		{
			std::cout << "useful information 4 ";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		slk3.unlock();
	}
	void ManyThread5()
	{
		std::unique_lock<std::mutex> slk4(mut5);
		while (true)
		{
			std::cout << "useful information 5 ";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		slk4.unlock();
	}
};
int main()
{
    Threads thred1;
	Threads thred2;
	Threads thred3;
	Threads thred4;
	Threads thred5;
    std::thread r1(&Threads::ManyThread1, &thred1);
	std::thread r2(&Threads::ManyThread2, &thred2);
	std::thread r3(&Threads::ManyThread3, &thred3);
	std::thread r4(&Threads::ManyThread4, &thred4);
	std::thread r5(&Threads::ManyThread5, &thred5);
    r1.join();
	r2.join();
	r3.join();
	r4.join();
	r5.join();
}
