#include <iostream>
#include "book.h"

using namespace std;

void BookSide::insert(price_t m_price, uint32_t m_quantity, uint32_t m_nbOrders) {
    uint32_t indexLevelToInsert = 0;
    if (depth == maxDepth) {
        cout << "Cannot insert level with price " << m_price.getDecimalString() << "because maxDepth reached" << endl;
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < depth; ++i) {
        price_t priceLevel = levels[i].GetPrice();
        if (m_price == priceLevel) {
            cout << "Cannot insert level with price " << m_price.getDecimalString() << "because it already exists" << endl;
            exit (EXIT_FAILURE);
        }
        if (side == ASK && m_price < priceLevel)
            break;
        else if (side == BID && m_price > priceLevel)
            break;
        ++indexLevelToInsert;
    }

    ++depth;
    for (int i = indexLevelToInsert + 1; i < depth; ++i) {
        levels[i] = levels[i - 1];
    }
    BookLevel levelToInsert(m_price, m_quantity, m_nbOrders);
    levels[indexLevelToInsert] = levelToInsert;

}

void BookSide::change(uint32_t levelIndex, uint32_t m_quantity, uint32_t m_nbOrders) {
    if(levelIndex>=depth){
        cout<< "Cannot change level "<<levelIndex<<" because level>depth"<<endl;
        exit (EXIT_FAILURE);
    }
    levels[levelIndex].SetQuantity(m_quantity);
    levels[levelIndex].SetNbOrders(m_nbOrders);
}

void BookSide::overlay(uint32_t levelIndex, price_t m_price, uint32_t m_quantity, uint32_t m_nbOrders) {
if(levelIndex>=depth){
        cout<< "Cannot overlay level "<<levelIndex<<" because level>depth"<<endl;
        exit (EXIT_FAILURE);
    }
    levels[levelIndex].SetPrice(m_price);
    levels[levelIndex].SetQuantity(m_quantity);
    levels[levelIndex].SetNbOrders(m_nbOrders);
}

void BookSide::remove(uint32_t levelIndex) {

}

void BookSide::removeAll() {
    for(int i=0;i<depth;++i){
        levels[i].SetNbOrders(0);
        levels[i].SetQuantity(0);
        price_t price;
        levels[i].SetPrice(price);
    }
    depth=0;
}

void BookSide::display() {
    cout << "---------------------------------------------------" << endl;
    cout << "|                       " << this->getSideString() << "                      |" << endl;
    cout << "|       Price        Quantity           NbOrders  |" << endl;
    cout << "---------------------------------------------------" << endl;
    for (int i = 0; i < maxDepth; ++i) {
        cout << "|       " << levels[i].GetPrice().getDecimalString() << "        " << levels[i].GetQuantity() << "                    " << levels[i].GetNbOrders() << "   |" << endl;
    }
    cout << "---------------------------------------------------" << endl;

}