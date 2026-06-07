#ifndef BROWSER_HISTORY_H
#define BROWSER_HISTORY_H

#include <iostream>
#include <string>
using namespace std;

//forward declarations
class Page; //encapsulated node class
class Stack; //linked list implemented as a stack
class BrowserHistory; //abstarct the stack implementation

class Page{
    friend class Stack;
    friend class BrowserHistory;
    private:
    string m_URL;
    string m_title;
    Page* m_next; //address of next node

    public:
    Page(){
        m_URL = "";
        m_title = "";
        m_next = nullptr;
    }
    Page(string url, string title){
        m_URL = url;
        m_title = title;
        m_next = nullptr;
    }
    //accessor
    string getURL(){return m_URL;}
    string getTitle(){return m_title;}
    //mutator
    void setURL(string url){m_URL = url;}
    void setTitle(string title){m_title = title;}    
};

class Stack{
    private:
    Page* m_top; //stack ptr to top
    int m_pages;
    
    public:
    Stack(); //constructor
    ~Stack(); //destructor
    int getPages(){return m_pages;}

    //methods
    /*
    Name: visit()
    Description: takes in strings
    dynamically allocates the page
     and push to the stack
    push to the top*/
    void push(const string& url, const string& title);
    bool isEmpty();

    /*
    Name: pop()
    Description: save copy of current top
    delete top and return the copy*/
    Page pop(); //remove the current page
    Page* peek() const; //shows the current top/current page, return ptr to it
    void display(); //lists all the pages with their urls
    void clear();
   
    
};

class BrowserHistory{
    private:
    Stack m_back;
    Stack m_forward;

    public:
    BrowserHistory();
    /*
    Description: takes in a url and title
    ,uses push method to create and push to the back stack
    clear forward stack
    mark this page as current page
    */
    void visit(const string& url, const string& title);
    void forward();
    void back();
    void current();
    void display();
};

#endif