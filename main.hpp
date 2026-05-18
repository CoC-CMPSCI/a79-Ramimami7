#ifndef MAIN_HPP
#define MAIN_HPP



#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void makeVector(vector<int> &);
void insertVector(vector<int> &, int);
int deleteVector(vector<int> &, int);
int randnum(void);
int getInput(void);
void printVector(vector<int>);

void makeVector(vector<int> &number)
{
    number.clear();
    srand(time(0));              
    for (int i = 0; i < 10; i++) {
        number.push_back(rand() % 20);  
    }
    sort(number.begin(), number.end()); 
}

void insertVector(vector<int> &number, int usernum)
{
   
    auto pos = lower_bound(number.begin(), number.end(), usernum);
    number.insert(pos, usernum);
}

int deleteVector(vector<int> &number, int usernum)
{
    int count = 0;

    for (auto iter = number.begin(); iter != number.end(); ) {
        if (*iter == usernum) {
            iter = number.erase(iter);  
            count++;
        } else {
            iter++;  
        }
    }

    if (count == 0) {
        return -1; 
    }
    return count;   
}

int getInput(void)
{
    int num;
    cout << "Enter your input\n";
    cin >> num;
    return num;
}

int randnum(void)
{
    return rand() % 100;
}

void printVector(vector<int> number)
{
    for (auto iter = number.begin(); iter != number.end(); iter++)
        cout << setw(5) << *iter;
    cout << endl;
}

#endif