#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>
#include <exception>

using namespace std;

//increase data by n of numbers, data is generic means any data type is acceptable
template<typename T>
void increase(T& data, int n)
{
	for (int &element : data)
	{
		element = element + n;
	}
}

//copy function to copy values from a data to another
//Iterator from, to is an iterator that goes through range of first array and copies them into Iterator2
//Iterator2 is the data that stores all values of Iterator1
template<typename Iterator, typename Iterator2>
Iterator2 myCopy(Iterator from, Iterator to, Iterator2 result)
{
	for (Iterator it = from; it != to; it++) //for(int i = 0; i != 10; i++)
	{
		*result++ = *it;

	}

	return result;
}

int main()
{

	try {

		//arrays
		int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		increase(arr, 2);
		increase(arr,3);
		increase(arr, 5);

		int arr2[10];
		copy(arr, arr + 10, arr2);
		myCopy(arr, arr + 10, arr2);

		//vectors
		vector<int> nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		increase(nums, 3);

		vector<int> nums2(10);
		copy(nums.begin(), nums.end(), nums2.begin()); //standard library - built-in function of copy
		myCopy(nums.begin(), nums.end(), nums2.begin()); //my own function of copy

		vector<int>::iterator it = find(nums.begin(), nums.end(), 3);

		//searching for "it" which is an iterator that storeed the found number
		for (int i = 0; i < 10; i++)
		{
			if (*it == nums[i])
				cout << *it << " is at index " << i << endl;
		}

		//lists
		list<int> myList = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		increase(myList, 20);

		list<int>myList2(10);
		copy(myList.begin(), myList.end(), myList2.begin());
		myCopy(myList.begin(), myList.end(), myList2.begin());

		myCopy(arr.begin(), arr.end(), nums.begin());
		myCopy(myList.begin(), myList.end(), arr.begin());


		//an iterator to find the number and stores it
		list<int>::iterator itFindNumber = find(myList.begin(), myList.end(), 27);

		//another iterator to go through all elements of list
		list<int>::iterator itList = myList.begin();

		//while loop that checks if found number is among the elements of list
		while (itList != myList.end())
		{
			if (*itList == *itFindNumber)
			{
				//distance function is a built-in function, it helps calculating the distance between the beginning of list until the found number, helps find index of found number
				cout << *itFindNumber << " is at index " << std::distance(myList.begin(), itFindNumber);
			}
			//incrementing the iterator so it accesses the next element of the list
			itList++;
		}


	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cerr << "Unknown exception\n";
		return 2;
	}


}
