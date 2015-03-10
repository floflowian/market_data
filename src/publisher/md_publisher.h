/* 
 * File:   md_publisher.h
 * Author: Florian
 *
 * Created on 9 mars 2015, 23:36
 */

#ifndef MD_PUBLISHER_H
#define	MD_PUBLISHER_H

#include "md_tick.h"

template <class Forecaster>
class md_publisher{
    Forecaster * forecaster;
    
    md_publisher();
    md_publisher(Forecaster m_forecaster);
    
    void offer(dynamic_order_book book);
    
};

#endif	/* MD_PUBLISHER_H */

