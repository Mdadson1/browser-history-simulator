# Browser History Simulator

A browser history simulator implemented in C++ using two linked lists implemented as stacks.

## Overview

This project models browser navigation using:

- A Back Stack
- A Forward Stack

The simulator supports:

- Visiting new pages
- Moving backward through history
- Moving forward through history
- Displaying current history

## Data Structures

### Stack

Custom stack implementation using a linked list.

### Page

Represents a webpage and stores:

- URL
- Page title

### Browser

Manages navigation using two stacks.

## Key Concept

When a new page is visited after navigating backward, the forward history must be cleared.

Example:

Google → YouTube → Stack Overflow

Back

Google → YouTube

Forward stack:
Stack Overflow

Visit Anthropic

Google → YouTube → Anthropic

Forward stack becomes empty.

This matches real browser behavior.

## Learning Outcomes

- Linked Lists
- Stack ADT
- Dynamic Memory Management
- Friend Classes
- Destructor Design
- Memory Leak Prevention
- Browser Navigation Logic

## Notes for Improvement
- integrate <ctime> to add timestamps

## Author

Mensima Dadson
