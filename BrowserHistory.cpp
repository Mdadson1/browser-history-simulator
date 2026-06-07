#include "BrowserHistory.h"

/*Stack Implementations*/

Stack::Stack(){
    m_top = nullptr;
    m_pages = 0;
}

Stack::~Stack(){
   Page* curr = m_top;
   while(curr != nullptr){
    curr = curr->m_next;
    delete m_top;
    m_top = curr;
   }
   m_top = nullptr;
   m_pages = 0;
}

void Stack::push(const string& url, const string& title){
    /* empty stack - top is null so make 
    the next of new node point to it
    non-empty stack, we push to top
    new nodes's next points to current top
     and the new node becomes current top */
    
    Page* ptr = new Page(url, title);
    ptr->m_next = m_top;
    m_top = ptr;
    m_pages++;
}

bool Stack::isEmpty(){
    return (m_top == nullptr);
}

Page Stack::pop(){
    if(!isEmpty()){
        //make copy of current top ptr, update top, make copy
        Page* temp = m_top;
        m_top = m_top->m_next;
        Page top(*temp);//the copy
        delete temp;
        m_pages--;
        return top;
    }else{
        cout << "No pages to display" << endl;
        return Page();
    }
}

Page* Stack::peek() const{
    return m_top;
}

void Stack::display(){
    if(!isEmpty()){
        Page* runner = m_top;
        cout << "History Info: \n" << m_pages << " pages visited" << endl;
        while(runner != nullptr){
            cout << "URL: " << runner->getURL() << "\nTitle: " <<
            runner->getTitle() << endl;
            runner = runner->m_next;
        }
    }else{
        cout << "No pages to display" << endl;
    }
}

void Stack::clear(){
    if(!isEmpty()){
        Page* now = m_top;
        while(now != nullptr){
            now = now->m_next;
            delete m_top;
            m_top = now;
            m_pages--;
        }
        m_top = nullptr;
        m_pages = 0;
    }
}
/*BrowserHistory Implementation*/
BrowserHistory::BrowserHistory(){
    //stacks are automatically created by theri constructor
}

void BrowserHistory::visit(const string& url, const string& title){
    m_forward.clear();
    m_back.push(url,title);
    current();
}

void BrowserHistory::forward(){
    /*pop off forward stck, push to back, call current on back, display forward*/
    if(!m_forward.isEmpty()){
        Page top = m_forward.pop();
        m_back.push(top.getURL(), top.getTitle());
        current();
    }else{
        cout << "No next page." << endl;
    }
}   

void BrowserHistory::back(){
    /*pop page off the back stack, push to forward, call current on back*/
    if(m_back.getPages() > 1){
        Page top = m_back.pop();
        m_forward.push(top.getURL(), top.getTitle());
        current();
    }else if(m_back.getPages() == 1){
        cout << "Already at the oldest page." << endl;
        //nothing to go back to
    }
    else{
        cout << "No more previous pages." << endl;
    }
}

void BrowserHistory::current(){
    Page* top = m_back.peek();
    if(top != nullptr){
        cout << "Current page\nURL: " << top->getURL() << "\nTitle: "
        << top->getTitle() << endl;
    }else{
        cout << "No pages visited yet." << endl;
    }
}

void BrowserHistory::display(){
    //print main history
    m_back.display();
}