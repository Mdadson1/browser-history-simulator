#include "BrowserHistory.h"

int main(){

    BrowserHistory chrome;

    //empty tests
    chrome.display(); //should say no pages
    chrome.back();
    chrome.forward();
    //test w one page
    chrome.visit("https://claude.ai/chat/77888d39-9375-4e2c-ae46-a0a2b2d5af08","claude.ai");
    chrome.back();
    chrome.forward();

    // multiple pages and back/forward flow
    chrome.visit("https://google.com", "Google");
    chrome.visit("https://github.com", "GitHub");
    chrome.visit("https://stackoverflow.com", "Stack Overflow");
    chrome.display(); // should show all 3 in order

    chrome.back();    // should go to GitHub
    chrome.back();    // should go to Google
    chrome.forward(); // should go back to GitHub

    // critical test: visit new page while forward stack has something
    // this should clear Stack Overflow from the forward stack
    chrome.visit("https://anthropic.com", "Anthropic");
    chrome.forward(); // should say "No next page" — forward was cleared
    chrome.display(); // should show Google, GitHub, Anthropic in order

    // back all the way to the oldest page
    chrome.back();
    chrome.back();
    chrome.back(); // should say "Already at the oldest page"

    return 0;
}