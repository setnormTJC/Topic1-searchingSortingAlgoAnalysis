#include <iostream>


#include<vector> 

#include<algorithm>

using std::vector; 
using std::cout; 
using std::endl; 
using std::string; 


class Shoe
{
private: 
    int numberOfStars; 
    string arrivalDate;
    double price; 
public:


};

template<typename T>
void print(vector<T> someList)
{
    for (auto& element : someList) //"range-based" for loop 
    {
        cout << element << " ";
    }
    cout << "\n";
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


int main()
{
    auto listOfNums = generateNRandomInts(10); 
    cout << "Initially: " << endl; 
    print(listOfNums); 


    std::sort(listOfNums.begin(), listOfNums.end());

    cout << "Initially: " << endl;
    print(listOfNums);
    //vector<Shoe> shoes; 

    //sortShoesByPrice(shoes);



    return 0;
}