//
//  book.cpp
//  
//
//  Created by Jiahui Wang on 11/7/16.
//
//


#include "book.h"


Book::Book(){
    m_isbn = "empty";
    m_title = "empty";
    m_author = "empty";
    m_year = 0;
    m_rating = 0.0;
}

Book::Book(std::string isbn, std::string title, std::string author, int year, float rating){
    m_isbn = isbn;
    m_title = title;
    m_author = author;
    m_year = year;
    m_rating = rating;
}

Book::~Book(){}

int Book::year() const{

    return m_year;
}

std::string Book::isbn() const{

    return m_isbn;
}

std::string Book::author() const{

    return m_author;
}

std::string Book::title() const{

    return m_title;
}

float Book::rating() const{

    return m_rating;
}

//bool Book::operator==(const Book & b) const{}

//friend function
//std::ostream & operator<<(std::ostream & os, const Book & b){}
