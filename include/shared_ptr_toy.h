#pragma once

#include <string>

#include "toy.h"
#include "count_links.h"

class shared_ptr_toy {
    Toy *ptr_toy = nullptr;

    Count_links *count_links = nullptr;

public:
    int use_count() const {
        if (count_links == nullptr) return 0;

        return count_links->count_result();
    }

    std::string getToyName() {
        if (ptr_toy == nullptr) return "Nothing";

        return ptr_toy->get_name();
    }

    Toy *get() const {
        return ptr_toy;
    }

    void reset() {
        count_links->subtract();

        ptr_toy = nullptr;
        count_links = nullptr;
    }

    shared_ptr_toy() {
        ptr_toy = nullptr;
        count_links = nullptr;
    }

    shared_ptr_toy(std::string name_toy) {
        ptr_toy = new Toy(name_toy);
        count_links = new Count_links();
    }

    shared_ptr_toy(const shared_ptr_toy &other_toy) {

        ptr_toy = other_toy.ptr_toy;
        count_links = other_toy.count_links;

        if (this->ptr_toy != nullptr) {
            count_links->add();
        }
    }

    shared_ptr_toy &operator=(const shared_ptr_toy &other_toy) {
        if (this == &other_toy) return *this;

        if (ptr_toy != nullptr && count_links != nullptr && count_links->count_result() == 1) {
            count_links->subtract();

            delete ptr_toy;
            ptr_toy = nullptr;

            delete count_links;
            count_links = nullptr;
        } else if (ptr_toy != nullptr && count_links != nullptr) {
            count_links->subtract();

            ptr_toy = nullptr;
            count_links = nullptr;
        }

        ptr_toy = other_toy.ptr_toy;
        count_links = other_toy.count_links;

        if (ptr_toy != nullptr && count_links != nullptr) {
            count_links->add();
        }

        return *this;
    }

    ~shared_ptr_toy() {
        if (count_links != nullptr) {
            if (count_links->count_result() == 1) {
                delete ptr_toy;
                delete count_links;
            } else {
                count_links->subtract();
            }
        }
    }
};

shared_ptr_toy make_shared_toy(std::string name_toy) {
    shared_ptr_toy toy(name_toy);

    return toy;
}