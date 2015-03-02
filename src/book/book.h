/* 
 * File:   book.h
 * Author: Florian
 *
 * Created on 1 mars 2015, 20:33
 */

#ifndef BOOK_H
#define	BOOK_H
#include "../util/price.h"
#include <stdint.h>
#include <stdlib.h>

enum Side{
        BID,ASK
    };
class BookLevel{
    price_t price;
    uint32_t quantity;
    uint32_t nbOrders;
    
public:
    
    BookLevel():quantity(0),nbOrders(0){
        price.setExponent(0);
        price.setMantissa(0);
        
    }
    BookLevel(price_t m_price,uint32_t m_quantity,uint32_t m_nbOrders){
        price=m_price;
        quantity=m_quantity;
        nbOrders = m_nbOrders;
        
    }
    uint32_t GetNbOrders() const {
        return nbOrders;
    }

    void SetNbOrders(uint32_t nbOrders) {
        this->nbOrders = nbOrders;
    }

    price_t GetPrice() const {
        return price;
    }

    void SetPrice(price_t price) {
        this->price = price;
    }

    uint32_t GetQuantity() const {
        return quantity;
    }

    void SetQuantity(uint32_t quantity) {
        this->quantity = quantity;
    }
};

class BookSide{
    
    BookLevel * levels;
    uint32_t maxDepth;
    uint32_t depth;
    Side side;
    
    
    
public:
    BookSide(uint32_t m_maxDepth,Side m_side):depth(0),maxDepth(m_maxDepth){
        side=m_side;
        levels = (BookLevel*) malloc(maxDepth*sizeof(BookLevel));
        for(int i=0;i<maxDepth;++i){
            BookLevel level;
            levels[i]=level;
        }
    }
    ~BookSide(){
        free(levels);
    }
    uint32_t GetDepth() const {
        return depth;
    }

    void SetDepth(uint32_t depth) {
        this->depth = depth;
    }

    BookLevel* GetLevels() const {
        return levels;
    }

    void SetLevels(BookLevel* levels) {
        this->levels = levels;
    }

    uint32_t GetMaxDepth() const {
        return maxDepth;
    }

    void SetMaxDepth(uint32_t maxDepth) {
        this->maxDepth = maxDepth;
    }
    
    BookLevel getTopLevel(){
        return this->levels[0];
    }
    
    BookLevel getBottomLevel(){
        return this->levels[depth];
    }
    Side getSide(){
        return this->side;
    }
    std::string getSideString(){
        std::string ask="ASK";
        std::string bid="BID";
        if(this->side == ASK)
            return ask;
        else
            return bid;
    }
    void display();
    void insert(price_t m_price, uint32_t m_quantity,uint32_t m_nbOrders);
    void change( uint32_t m_quantity, uint32_t m_nbOrders);
    void overlay( price_t m_price,uint32_t m_quantity, uint32_t m_nbOrders);
    void remove(uint32_t levelIndex);
    void removeAll();
    
};



#endif	/* BOOK_H */

