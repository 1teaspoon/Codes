//
//  list.cpp
//  
//
//  Created by Jiahui Wang on 11/7/16.
//
//
#include <iostream>
#include "list.h"
#include <string>

List::List(){
    m_size = 0;
    std::string * ListArrayPointer = new std::string [m_size];
    
}
List::~List(){
    delete [] ListArrayPointer;
}

void List::append(Book item){
        std::string * ListArrayPointerUpdate = new std::string [m_size+5];
        for (int i=0; i<m_size; i++){
            ListArrayPointerUpdate[i] = ListArrayPointer[i];
        }
        ListArrayPointerUpdate[m_size] = item.isbn();
        ListArrayPointerUpdate[m_size+1] = item.title();
        ListArrayPointerUpdate[m_size+2] = item.author();
        ListArrayPointerUpdate[m_size+3] = std::to_string(item.year());
        ListArrayPointerUpdate[m_size+4] = std::to_string(item.rating());
        delete [] ListArrayPointer;
        ListArrayPointer = ListArrayPointerUpdate;
        m_size = m_size+5;
        //for (int i=0; i<m_size; i=i+5){
        //    std::cout<<ListArrayPointer[i]<<ListArrayPointer[i+1]<<ListArrayPointer[i+2]<<ListArrayPointer[i+3]<<ListArrayPointer[i+4]<<std::endl;

        //}
}

bool List::remove(Book item){
    
    
    std::string * ListArrayPointerUpdate = new std::string [m_size-5];
    int i = 0;
    while (ListArrayPointer[i] != item.isbn()){
        ListArrayPointerUpdate[i] = ListArrayPointer[i];
        i++;
    }
    
    for (int k = i+5; k<m_size; k++){
        ListArrayPointerUpdate[i] = ListArrayPointer[k];
        i++;
    }
        delete [] ListArrayPointer;
    ListArrayPointer = ListArrayPointerUpdate;
    m_size = m_size-5;
    //for (int i=0; i<m_size; i=i+5){
    //    std::cout<<ListArrayPointer[i]<<ListArrayPointer[i+1]<<ListArrayPointer[i+2]<<ListArrayPointer[i+3]<<ListArrayPointer[i+4]<<std::endl;
        
    //}
    return true;
    

}

bool List::contains(Book item) const{
    for (int i=0; i<m_size; i=i+5){
        if (ListArrayPointer[i] == item.isbn()){
        
            break;
            return true;
            
        }
        
    }
    return false;



}

int List::size() const{

    return m_size;
}


void List::sort(){
    std::string * ListArrayPointerSort = new std::string [m_size];
    for (int i=0; i<m_size; i = i+5){
        if (i ==0 ){
            ListArrayPointerSort[i] = ListArrayPointer[i];
            ListArrayPointerSort[i+1] = ListArrayPointer[i+1];
            ListArrayPointerSort[i+2] = ListArrayPointer[i+2];
            ListArrayPointerSort[i+3] = ListArrayPointer[i+3];
            ListArrayPointerSort[i+4] = ListArrayPointer[i+4];
            //for (int i=0; i<m_size; i=i+5){
            //    std::cout<<ListArrayPointerSort[i]<<ListArrayPointerSort[i+1]<<ListArrayPointerSort[i+2]<<ListArrayPointerSort[i+3]<<ListArrayPointerSort[i+4]<<std::endl;
                
            //}
            
        }
        else{
            if (ListArrayPointer[i+4]<=ListArrayPointerSort[i-1]){
                //std::cout<<"now index is "<<i<<std::endl;
                ListArrayPointerSort[i] = ListArrayPointer[i];
                ListArrayPointerSort[i+1] = ListArrayPointer[i+1];
                ListArrayPointerSort[i+2] = ListArrayPointer[i+2];
                ListArrayPointerSort[i+3] = ListArrayPointer[i+3];
                ListArrayPointerSort[i+4] = ListArrayPointer[i+4];
                
               // for (int i=0; i<m_size; i=i+5){
               //     std::cout<<ListArrayPointerSort[i]<<ListArrayPointerSort[i+1]<<ListArrayPointerSort[i+2]<<ListArrayPointerSort[i+3]<<ListArrayPointerSort[i+4]<<std::endl;
                    
               // }
            
            }
            else{
                int j=i;
                //std::cout<<"j is "<<j<<std::endl;
                
                while (j>0){
                    if (ListArrayPointer[i+4]<=ListArrayPointerSort[j-1]){
                        break;
                    }
                    j = j-5;
                }
                //std::cout<<"j is "<<j<<std::endl;
                
                for (int k=i; k>=j; k = k-5){
                    //std::cout<<"k is "<<k<<std::endl;
                    ListArrayPointerSort[k] = ListArrayPointerSort[k-5];
                    ListArrayPointerSort[k+1] = ListArrayPointerSort[k-4];
                    ListArrayPointerSort[k+2] = ListArrayPointerSort[k-3];
                    ListArrayPointerSort[k+3] = ListArrayPointerSort[k-2];
                    ListArrayPointerSort[k+4] = ListArrayPointerSort[k-1];
                }
                ListArrayPointerSort[j] = ListArrayPointer[i];
                ListArrayPointerSort[j+1] = ListArrayPointer[i+1];
                ListArrayPointerSort[j+2] = ListArrayPointer[i+2];
                ListArrayPointerSort[j+3] = ListArrayPointer[i+3];
                ListArrayPointerSort[j+4] = ListArrayPointer[i+4];
            }
        }
    }

    delete [] ListArrayPointer;
    ListArrayPointer = ListArrayPointerSort;
    for (int i=0; i<m_size; i=i+5){
        std::cout<<ListArrayPointer[i]<<ListArrayPointer[i+1]<<ListArrayPointer[i+2]<<ListArrayPointer[i+3]<<" "<<ListArrayPointer[i+4]<<std::endl;
        
    }
    
}

//Book&operator[](int idx) const{
    

//}
