#include <iostream>

#include <vector>

#include"C:/Users/Work/Downloads/Timing.h"

using namespace std;

template<typename T> //templates enable "generic programming" (not as strict wrt data type)
void print(vector<T> someList)
{
    for (auto& element : someList) //"range-based" for loop 
    {
        cout << element << " ";
    }
    cout << "\n";

    //for (int i = 0; i < someList.size(); i++)
    //{
    //    cout << someList.at(i) << " ";
    //    //cout << someList[i] << " ";
    //}

    cout << "\n";
}

template<typename T>
int sequential_search(vector<T> someList, T targetValue)
{
    for (int i = 0; i < someList.size(); i++)
    {
        if (someList[i] == targetValue)
        {
            return i;
        }
    }

    return -9999; //not possible for an array (conventionally) 
}

vector<int> generateNRandomInts(int N)
{
    vector<int> randomNums;
    for (int i = 0; i < N; i++)
    {
        randomNums.push_back(rand() % N);
    }

    return randomNums;
}

void timeSequentialSearchForN(int N)
{
    auto vecN = generateNRandomInts(N);
    int randValue = rand() % (N + 1);
    Timer* tN = new Timer;
    sequential_search(vecN, randValue);//ignoring returned index value
    delete tN;
}

int binarySearch(std::vector<int> sortedNums, int searchValue)
{
    bool found = false;
    int first = 0;
    int last = sortedNums.size() - 1;
    int middle;


    int comparisonCount = 0; 

    while (first <= last and !found)
    {

        middle = (first + last) / 2; //use ceil() or floor() for odd lengths … be cautious
        if (sortedNums[middle] == searchValue)
        {
            found = true;
        }

        else if (sortedNums[middle] > searchValue) //remmber the similarity to the HI-LO game
        {
            comparisonCount++; 
            last = middle - 1;//shift last one to the "left" of middle
        }
        else
        {
            comparisonCount++;
            first = middle + 1;
        }

    }//end while 

    cout << "Number of comparisons: " << comparisonCount << endl; 


    if (found)
    {
        return middle;
    }
    else
    {
        return -1;//element is not in array
    }
} //end func. def.


int main()
{
    //use binary search in a bad-case scenario (the targetValue is the last element) 
    vector<int> nums8 = { 1, 2, 3, 4, 5, 6, 7, 8 };

    cout << "For 8 elements - comparisons equals: ";
    binarySearch(nums8, 8);

    vector<int> nums64; 
    for (int i = 1; i < 65; i++)
    {
        nums64.push_back(i); 
    }

    cout << "For 64 elements - comparisons equals: ";
    binarySearch(nums64, 64);

    cout << "Log base 2 of 64: " << log2(64) << endl; 

    return 0;
}