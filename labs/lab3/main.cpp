#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>
#include <list>
#include <limits>

class queue_is_empty
{};

unsigned short c_SpecialItem = std::numeric_limits<unsigned short>::max();

class queue
{
	std::list<unsigned short> events;
public:
	void AcceptItem(unsigned short item)
	{
		events.push_back(item);
	}
	unsigned short HandLastItem()
	{
		if (events.empty()) return 0;
			//throw queue_is_empty();
		unsigned short item = events.front();
		if (item != c_SpecialItem)
			events.pop_front();
		return item;
	}
};

queue g_queue;
std::mutex g_FirstMutex;

int main()
{
	auto suplier1 = []()
	{
		for (unsigned short i = 0; i < 10 ;)
		{
			if (i < 100 && g_FirstMutex.try_lock())
			{
				g_queue.AcceptItem(i);
				i++;
				g_FirstMutex.unlock();
			}
			std::this_thread::yield();
		}
		std::cout << "suplier[1] I have filled queue!!!" << std::endl;
		g_FirstMutex.lock();
		g_queue.AcceptItem(c_SpecialItem);
		g_FirstMutex.unlock();
	};
	auto suplier2 = []()
	{
		for (unsigned short i = 10; i < 20;)
		{
			if (i < 100 && g_FirstMutex.try_lock())
			{
				g_queue.AcceptItem(i);
				i++;
				g_FirstMutex.unlock();
			}
			
			std::this_thread::yield();
		}
		std::cout << "suplier[2] I have filled queue!!!" << std::endl;
		g_FirstMutex.lock();
		g_queue.AcceptItem(c_SpecialItem);
		g_FirstMutex.unlock();
	};
	auto consumer1 = []()
	{
		while (true)
		{
			g_FirstMutex.lock();
			unsigned short item = 0;
			try
			{
				item = g_queue.HandLastItem();
			}
			catch (queue)
			{
				std::cout << "consumer[1]: queue is empty!" << std::endl;
			}
			g_FirstMutex.unlock();
			if (item == c_SpecialItem)
				break;
			std::cout << "consumer[1]: Got new item: " << item << "!" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(4));
		}
	};
	auto consumer2 = []()
	{
		while (true)
		{
			g_FirstMutex.lock();
			unsigned short item = 0;
			try
			{
				item = g_queue.HandLastItem();
			}
			catch (queue)
			{
				std::cout << "consumer[2]: queue is empty!" << std::endl;
			}
			g_FirstMutex.unlock();
			if (item == c_SpecialItem)
				break;
			std::cout << "consumer[2]: Got new item: " << item << "!" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(4));
		}
	};
	auto consumer3 = []()
	{
		while (true)
		{
			g_FirstMutex.lock();
			unsigned short item = 0;
			try
			{
				item = g_queue.HandLastItem();
			}
			catch (queue)
			{
				std::cout << "consumer[3]: queue is empty!" << std::endl;
			}
			g_FirstMutex.unlock();
			if (item == c_SpecialItem)
				break;
			std::cout << "consumer[3]: Got new item: " << item << "!" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(4));
		}
	};

	std::thread supplier1Thread(suplier1);
	std::thread supplier2Thread(suplier2);

	std::thread consumer1Thread(consumer1);
	std::thread consumer2Thread(consumer2);
	std::thread consumer3Thread(consumer3);

	supplier1Thread.join();
	supplier2Thread.join();

	consumer1Thread.join();
	consumer2Thread.join();
	consumer3Thread.join();
	return 0;
}