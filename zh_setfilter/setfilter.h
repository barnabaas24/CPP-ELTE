#ifndef SETFILTER_H
#define SETFILTER_H

#include <set>

template<class T, class Pred = std::less<T>>
class set_filtering {

private:
    std::set<T, Pred> filtered_set;
    std::set<T, Pred>& orig_set;

    void restore() {
        for (typename std::set<T>::iterator it = filtered_set.begin(); it != filtered_set.end(); ++it) {
            orig_set.insert(it);
        } 
    }

    void apply_filter() {
        orig_set.clear();
        inverse();
    }

public:

    void operator~() {
        apply_filter();
    }

    template<class U>
    void operator +=(U functor) {
        for (typename std::set<T>::iterator it = orig_set.begin(); it != orig_set.end();) {
            if (functor(it)) {
                filtered_set.insert(it);
                it = orig_set.erase(it);
            } else {
                ++it;
            }
        }
    }

    template<class U>
    void operator -=(U functor) {
          for (typename std::set<T>::iterator it = filtered_set.begin(); it != filtered_set.end();) {
            if (functor(it)) {
                orig_set.insert(*it);
                it = filtered_set.erase(it);
            } else {
                ++it;
            }
        }
    }

    set_filtering(std::set<T, Pred> &s): orig_set(s) {};

    ~set_filtering() {
        restore();
    }

    void filter(T value) {
        if (orig_set.find(value) != orig_set.end()) {
            orig_set.erase(value);
            filtered_set.insert(value);
        }
    }

    void unfilter(T value) {
        if (filtered_set.find(value) != filtered_set.end()) {
            orig_set.insert(value);
            filtered_set.erase(value);
        }
    }

    void inverse() {
        orig_set.swap(filtered_set);
    }

};

#endif