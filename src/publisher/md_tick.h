/* 
 * File:   md_tick.h
 * Author: Florian
 *
 * Created on 9 mars 2015, 22:33
 */

#ifndef MD_TICK_H
#define	MD_TICK_H
#include "../util/price.h"
#include "../book/book.h"

class md_tick {

    uint32_t levelsBid;
    uint32_t levelsAsk;
    price_t * bidPrice;
    price_t * askPrice;
    uint32_t * bidQuantity;
    uint32_t * askQuantity;
    uint32_t * bidNbOrders;
    uint32_t * askNbOrders;
    
public:
    md_tick(uint32_t m_levelsBid, uint32_t m_levelsAsk) : levelsBid(m_levelsBid), levelsAsk(m_levelsAsk) {
        bidPrice = new price_t[levelsBid];
        askPrice = new price_t[levelsAsk];
        bidQuantity = new uint32_t[levelsBid];
        askQuantity = new uint32_t[levelsAsk];
        bidNbOrders = new uint32_t[levelsBid];
        askNbOrders = new uint32_t[levelsAsk];
    }

    md_tick(dynamic_order_book book) {
        levelsBid = book.GetBidSide().GetMaxDepth();
        levelsAsk = book.GetAskSide().GetMaxDepth();
        bidPrice = new price_t[levelsBid];
        askPrice = new price_t[levelsAsk];
        bidQuantity = new uint32_t[levelsBid];
        askQuantity = new uint32_t[levelsAsk];
        bidNbOrders = new uint32_t[levelsBid];
        askNbOrders = new uint32_t[levelsAsk];

        for (int i = 0; i < levelsBid; ++i) {
            bidPrice[i] = book.GetBidSide().GetLevel(i).GetPrice();
            bidQuantity[i] = book.GetBidSide().GetLevel(i).GetQuantity();
            bidNbOrders[i] = book.GetBidSide().GetLevel(i).GetNbOrders();
        }
        for (int i = 0; i < levelsAsk; ++i) {
            askPrice[i] = book.GetAskSide().GetLevel(i).GetPrice();
            askQuantity[i] = book.GetAskSide().GetLevel(i).GetQuantity();
            askNbOrders[i] = book.GetAskSide().GetLevel(i).GetNbOrders();
        }
    }

    void setBidPrice(uint32_t level, price_t price) {
        if (level >= levelsBid) {
            std::cout << "Cannot add level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        bidPrice[level] = price;
    }

    void setAskPrice(uint32_t level, price_t price) {
        if (level >= levelsAsk) {
            std::cout << "Cannot add level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        askPrice[level] = price;
    }

    void setBidQuantity(uint32_t level, uint32_t quantity) {
        if (level >= levelsBid) {
            std::cout << "Cannot add level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        bidQuantity[level] = quantity;
    }

    void setAskQuantity(uint32_t level, uint32_t quantity) {
        if (level >= levelsAsk) {
            std::cout << "Cannot add level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        askQuantity[level] = quantity;
    }

    void setBidNbOrders(uint32_t level, uint32_t nbOrders) {
        if (level >= levelsBid) {
            std::cout << "Cannot add level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        bidNbOrders[level] = nbOrders;
    }

    void setAskNbOrders(uint32_t level, uint32_t nbOrders) {
        if (level >= levelsAsk) {
            std::cout << "Cannot add level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        askNbOrders[level] = nbOrders;
    }
    
    price_t getBidPrice(uint32_t level) {
        if (level >= levelsBid) {
            std::cout << "Cannot get level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        return bidPrice[level];
    }
    
    price_t getAskPrice(uint32_t level) {
        if (level >= levelsAsk) {
            std::cout << "Cannot get level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        return askPrice[level];
    }
    
    uint32_t getBidQuantity(uint32_t level) {
        if (level >= levelsBid) {
            std::cout << "Cannot get level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        return bidQuantity[level];
    }
    
    uint32_t getAskQuantity(uint32_t level) {
        if (level >= levelsAsk) {
            std::cout << "Cannot get level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        return askQuantity[level];
    }
  
    uint32_t getBidNbOrders(uint32_t level) {
        if (level >= levelsBid) {
            std::cout << "Cannot get level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        return bidNbOrders[level];
    }
    
    uint32_t getAskNbOrders(uint32_t level) {
        if (level >= levelsAsk) {
            std::cout << "Cannot get level " << level << " because level>depth" << std::endl;
            exit (EXIT_FAILURE);
        }
        return askNbOrders[level];
    }
};


#endif	/* MD_TICK_H */

