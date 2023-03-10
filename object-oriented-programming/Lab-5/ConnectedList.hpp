

template <typename Type>
class CList
{
public:
    CList(unsigned double maxvalue) : maxvalue(maxvalue){

                                      };

    unsigned int getLength() const;
    unsigned int isExist(Type elem);
    void insert(Type elem, unsigned int n);
    void remove(Type elem, unsigned int n);
    void operator+();
    void operator-(Type elem);
    void operator--();
    void operator[]();

private:
    struct Node
    {
        Type val;
        Node *next;

        Node(Type _val) : val(_val), next(nullptr) {}
    };
    unsigned long int Length = 0;
};

#include <iostream>
using namespace std;

struct Node
{
    string val;
    Node *next;

    Node(string _val) : val(_val), next(nullptr) {}
};

struct list
{
    Node *first;
    Node *last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty()
    {
        return first == nullptr;
    }

    void push_back(string _val)
    {
        Node *p = new Node(_val);
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print()
    {
        if (is_empty())
            return;
        Node *p = first;
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node *find(string _val)
    {
        Node *p = first;
        while (p && p->val != _val)
            p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first()
    {
        if (is_empty())
            return;
        Node *p = first;
        first = p->next;
        delete p;
    }

    void remove_last()
    {
        if (is_empty())
            return;
        if (first == last)
        {
            remove_first();
            return;
        }
        Node *p = first;
        while (p->next != last)
            p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(string _val)
    {
        if (is_empty())
            return;
        if (first->val == _val)
        {
            remove_first();
            return;
        }
        else if (last->val == _val)
        {
            remove_last();
            return;
        }
        Node *slow = first;
        Node *fast = first->next;
        while (fast && fast->val != _val)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast)
        {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node *operator[](const int index)
    {
        if (is_empty())
            return nullptr;
        Node *p = first;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
            if (!p)
                return nullptr;
        }
        return p;
    }
};
