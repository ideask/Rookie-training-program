#ifndef __SELECTION_SORT__
#define __SELECTION_SORT__
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Student
{
    public:
        Student(){}
        Student(string n, double s)
        {
            name = n;
            score = s;
        }
        Student& operator = (const Student& s)
        {
            if(this == &s)
            {
                return *this;
            }
            else
            {
                name = s.name;
                score = s.score;
            }
        }
        bool operator > (const Student& r)
        {
            return score != r.score ? score > r.score : name > r.name;
        }
        string whos() const {return name;}
        double get_score() const {return score;}
    private:
        string name;
        double score;
};

ostream& operator << (ostream& os, const Student& stu)
{
    os << stu.whos() << ' ' << stu.get_score() << endl;
}
#endif