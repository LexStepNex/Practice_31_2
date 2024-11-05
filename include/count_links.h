#pragma once

class Count_links {
    int count_links = 0;

public:
    int count_result() {
        return count_links;
    }

    void add() {
        count_links++;
    }

    void subtract() {
        if (count_links > 0) {
            count_links--;
        } else {
            count_links = 0;
        }
    }

    Count_links() {
        add();
    }

    ~Count_links() {}
};