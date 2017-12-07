#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include <vector>
#include "OrderRepository.h"
#include "Order.h"

class OrderService
{
    public:
        bool isValidOrder(const Order& order);
        void addOrder(const Order& order);
        vector<Order> getOrders();
        void setOrderState(Order order);
        Order getOrder(int ID);

    protected:

    private:
        OrderRepository orderRepository;
};

#endif // ORDERSERVICE_H
