#include <iostream>
#include <cstring>

class event{
protected:
    std::string subject_;
    int year_, month_, day_;
public:
    event(std::string s, int year, int month, int day): subject_(s), year_(year), month_(month), day_(day){};
    virtual void change_date(int new_tear, int new_month, int new_day);
    virtual void print_res(){std::cout << subject_ << ' ' << year_ << ' ' << month_ << ' ' << day_ << std::endl;}
    virtual void change_grade(bool new_mark) = 0;
    virtual void change_grade(int new_mark) = 0;
    virtual ~event(){};
};

void event::change_date(int new_year, int new_month, int new_day){
    year_ = new_year;
    month_ = new_month;
    day_ = new_day;
}

class test: public event{
    bool mark_;
public:
    void change_grade(int new_mark){};
    test(std::string s, int year, int month, int day, bool mark): event(s, year, month, day), mark_(mark){};
    void print_res(){
        std::cout << subject_ << ' ' << year_ << ' ' <<  month_ << ' ' << day_;
        if(mark_) std::cout << " true\n";
        else std::cout << " false\n";
    }
    void change_grade(bool new_mark){mark_ = new_mark;}
};

class exam: public event{
    int mark_;
public:
    void change_grade(bool new_mark){};
    exam(std::string s, int year, int month, int day, int mark): event(s, year, month, day), mark_(mark){};
    void print_res(){std::cout << subject_ << ' ' << year_ << ' ' <<  month_ << ' ' << day_ << " Grade " << mark_ << std::endl;}
    void change_grade(int new_mark){mark_ = new_mark;}
};


int main(){
    enum {NUM = 7};
    event *session[NUM];

    session[0]=new test("Mathematical analysis",2022,12,23,true);
    session[1]=new exam("Operation System",2023,1,15,2);
    session[2]=new test("Practicum",2022,12,25,false);
    session[3]=new exam("Differential equation",2023,1,20,3);
    session[4]=new test("Theory of probability",2022,12,29,true);
    session[5]=new exam("Philosophy",2022,1,24,5);
    session[6]=new exam("Numerical methods",2023,1,11,4);

    for (int i=0;i<NUM;i++)
        session[i]->print_res();

    session[2]->change_date(2023,2,25);
    session[2]->change_grade(true);

    session[1]->change_date(2023,3,3);
    session[1]->change_grade(3);

    std::cout<<std::endl;
    for (int i=0;i<NUM;i++)
        session[i]->print_res();

    session[0]->event::print_res();
    for (int i=0;i<NUM;i++)
        delete session[i];

    return 0;
}