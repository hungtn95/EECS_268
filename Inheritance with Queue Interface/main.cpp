/**
*	@file : main.cpp
*	@author : Hung Nguyen
*	@date : 2014.10.09
*	Purpose: Implementation of main function
*/

#include <iostream> //cout cin
#include "Queue.h" //Template box class
#include <string>

void printMenu()
{
    std::cout << "\n\nSelect and action:" << '\n';
    std::cout << "1) Add to check out lane 1" << '\n';
    std::cout << "2) Add to check out lane 2" << '\n';
    std::cout << "3) See who is at the front of lane 1" << '\n';
    std::cout << "4) See who is at the front of lane 2" << '\n';
    std::cout << "5) Print all names in lane 1" << '\n';
    std::cout << "6) Print all names in lane 2" << '\n';
    std::cout << "7) Check out a customer in lane 1" << '\n';
    std::cout << "8) Check out a customer in lane 2" << '\n';
    std::cout << "9) Compare Queues" << '\n';
    std::cout << "10) Quit" << '\n';
    std::cout << "Enter choice:" << '\n';
}

template <typename T>
void compareQueues(const QueueInterface<T>& q1, const QueueInterface<T>& q2)
{
    std::cout 	<< "\nComparison of queues:\n"
            << "lane 1 < lane 2: " <<  (q1 <  q2) 	<< "\n"
            << "lane 1 > lane 2: " <<  (q1 >  q2) 	<< "\n"
            << "lane 1 >= lane 2: " << (q1 >= q2) 	<< "\n"
            << "lane 1 <= lane 2: " << (q1 <= q2) 	<< "\n"
            << "lane 1 == lane 2: " << (q1 == q2) 	<< "\n"
            << "lane 1 != lane 2: " << (q1 != q2) 	<< "\n";
}

int main()
{
    QueueInterface<std::string>* lane1 = new Queue<std::string>();
    QueueInterface<std::string>* lane2 = new Queue<std::string>();
    int choice = 0;
    std::string input;
    while (choice != 10)
    {
        printMenu();
        std::cin >> choice;
        std::cout << "You chose: " << choice << '\n';
        switch (choice)
        {

        case 1:
            std::cout << "Who is going in lane 1?:" << '\n';
			std::cin >> input;
            lane1->enqueue(input);
            std::cout << input << " successfully added to the lane 1" << '\n';
            break;

        case 2:
            std::cout << "Who is going in lane 2?:" << '\n';
			std::cin >> input;
			lane2->enqueue(input);
            std::cout << input << " successfully added to the lane 2" << '\n';
            break;

        case 3:
            try
            {
              std::cout << lane1->peekFront() << " is at the front of the lane 1" << '\n';
            }
            catch(PreconditionViolationException e)
            {
                std::cout << e.what() << '\n';
            }
            break;

        case 4:
            try
            {
                std::cout << lane2->peekFront() << " is at the front of the lane 2" << '\n';
            }
            catch(PreconditionViolationException e)
            {
                std::cout << e.what() << '\n';
            }
            break;

        case 5:
            lane1->print();
            std::cout << '\n';
            break;

        case 6:
            lane2->print();
            std::cout << '\n';
            break;

        case 7:
            try
            {
                std::cout << lane1->dequeue() << " checked out from lane 1" << '\n';
            }
            catch(PreconditionViolationException e)
            {
                std::cout << e.what() << '\n';
            }
            break;

        case 8:
            try
            {
                std::cout << lane2->dequeue() << " checked out from lane 2" << '\n';
            }
            catch(PreconditionViolationException e)
            {
                std::cout << e.what() << '\n';
            }
            break;

        case 9:
            compareQueues(*lane1, *lane2);
            break;

        }
    }
	delete lane1;
	delete lane2;
    std::cout << "Program ending";
    return(0);
}
