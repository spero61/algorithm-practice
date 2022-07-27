// Doubly Linked List

#include <iostream>
#include <string>

using namespace std;

class Link {
   public:
    string value;
    Link(const string& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} {}
    Link* insert(Link* n);                    // insert n before this object
    Link* add(Link* n);                       // insert n after this object
    Link* erase();                            // remove this object from list; return this object's successor
    Link* find(const string& s);              // find s in list; return nullptr for "not found"
    const Link* find(const string& s) const;  // find s in const list; return nullptr for "not found"
    const Link* advance(int n) const;         // move n positions in list; return nullptr for "not found"
    Link* next() const { return succ; }
    Link* previous() const { return prev; }

   private:
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n) {   // insert n before this object; return n
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->succ = this;            // this object comes after n
    if (prev) prev->succ = n;  // n comes after what used to be this object's predecessor
    n->prev = prev;            // this object's predecessor becomes n's predecessor
    prev = n;                  // n becomes this object's predecessor
    return n;
}

Link* Link::add(Link* n)  // insert n after this object; return n
{
    if (n == nullptr) return this;
    if (this == nullptr) return n;
    n->prev = this;            // this object comes before n
    if (succ) succ->prev = n;  // n comes before what used to be this object's successor
    n->succ = succ;            // this object's successor becomes n's successor
    succ = n;                  // n becomes this object's successor
    return n;
}

Link* Link::erase() {
    if (this == nullptr) return nullptr;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

// find Link node by value (string)
Link* Link::find(const string& s) {
    Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return nullptr; // not found
}

// find Link node by value (const string)
const Link* Link::find(const string& s) const {
    const Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return nullptr; // not found
}

const Link* Link::advance(int n) const {  // this operation does not change the state of a Link
    const Link* p = this;
    if (p == nullptr) return nullptr;
    if (0 < n) {  // positive n moves forward
        while (n--) {
            if (p->succ == nullptr) return nullptr;
            p = p->succ;
        }
    } else if (n < 0) {  // negative n moves backward
        while (n++) {
            if (p->prev == nullptr) return nullptr;
            p = p->prev;
        }
    }
    return p;
}

void print_all(Link* p) {
    cout << "{";
    while (p) {
        cout << p->value;
        if (p = p->next()) cout << ", ";
    }
    cout << "}\n";
}

int main() {
    try {
        Link* japanese_era = new Link{"Edo"};
        japanese_era = japanese_era->insert(new Link{"Sengoku"});
        japanese_era = japanese_era->insert(new Link{"Muromachi"});
        japanese_era = japanese_era->insert(new Link{"Nanboku-cho"});
        japanese_era = japanese_era->insert(new Link{"Kamakura"});
        japanese_era = japanese_era->insert(new Link{"Heian"});
        japanese_era = japanese_era->insert(new Link{"Asuka"});

        Link* modern_era = new Link{"Heisei"};
        modern_era = modern_era->insert(new Link{"Showa"});
        modern_era = modern_era->insert(new Link{"Daisho"});
        modern_era = modern_era->insert(new Link{"Meiji"});

        cout << "\n~ before ~\n";
        print_all(japanese_era);
        print_all(modern_era);


        // -- modify nodes --

        // // check current pointers
        // cout << japanese_era -> value << '\n'; // Asuka
        // cout << modern_era -> value << '\n'; // Meiji

        // delete Nanboku-cho node
        Link* p1 = japanese_era->find("Nanboku-cho");
        if (p1) {
            p1 -> erase();
        }

        // insert Nara after Asuka
        Link* p2 = japanese_era->next();
        if (p2) {
            p2 -> insert(new Link{"Nara"});
        }

        // Add Reiwa to the end (next to Heisei)
        Link* p3 = modern_era;
        while (p3->next()) {
            p3 = p3->next();
        }
        p3-> add(new Link{"Reiwa"});

        // update node value: Daisho to Taisho
        Link* p4 = modern_era->find("Daisho");
        if (p4) {
            p4->value = "Taisho";
        }

        cout << "\n~ after ~\n";
        print_all(japanese_era);
        print_all(modern_era);

        // test other operations (immutable search)
        // cout << modern_era->advance(3)->advance(-2)->previous()->advance(2)->next()->value << '\n'; // Heisei

        return 0;
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "...Exception Occurred\n";
        return 2;
    }
}