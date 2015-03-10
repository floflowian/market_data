#include "md_publisher.h"

md_publisher::md_publisher(){
    
}

md_publisher::md_publisher(Forecaster * m_forecaster):forecaster(m_forecaster){
    
}

md_publisher::offer(dynamic_order_book book){
    md_tick tick(book);
    
    forecaster->handle_market_data_tick(tick);
}
