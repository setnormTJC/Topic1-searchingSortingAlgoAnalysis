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


    while (first <= last and !found)
    {
        middle = (first + last) / 2; //use ceil() or floor() for odd lengths … be cautious
        if (sortedNums[middle] == searchValue)
        {
            found = true;
        }
        else if (sortedNums[middle] > searchValue)
        {
            last = middle - 1;//shift last one to the "left" of middle
        }
        else
        {
            first = middle + 1;
        }

    }//end while 


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
 



    return 0;
}