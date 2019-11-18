#include <functional>
#include <iostream>

namespace struktury
{
    template <class T,class Compare>
    class bst;

    template<class T,class Compare>
    std::ostream& operator<<(std::ostream &wy, const typename bst<T,Compare>::node &tree);

    template <class T,class Compare = std::less_equal<T>>
    class bst
    {
    private:

        static Compare comp;
        class node
        {
        private:
            node *left;
            node *right;
            T val;
        public:
            node():left(nullptr),right(nullptr){}
            ~node(){
                delete this->left;
                delete this->right;
                //delete this;
            }

            node* glewo(){return this->left;};
            void slewo(node lewo){this->left = lewo;};
            node* gprawo(){return this->right;};
            void sprawo(node prawo){this->right = prawo;};
            void sval(T val){this->val = val;};
            T gval(){return this->val;};

            void insert(T val,node* here);
            T remove(T val);
            bool find(T val);
        };
        node* min(node* root);
    public:
        node *root;
        node* groot(){return root;};
        void sroot(node* val){root = val;};
        bst();
        //bst(initializer list<T>);
        bst(bst &&);
        bst(const bst &);
        bst &operator=(bst &&);
        bst &operator=(const bst &);
        ~bst(){delete root;};

        void insert(T val);
        T remove(T val);
        bool find(T val);

        //template<class T,class Compare> friend
        friend std::ostream& operator<< <T,Compare>(std::ostream &wy, const typename bst<T,Compare>::node &tree);
    };

    //dla wielu modolow sie psuje
    template<class T,class Compare>
    Compare bst<T,Compare>::comp;

    template<class T> struct moje
    {
        bool operator()(T *a, T *b) const{
            return *a <= *b;
        }
    };
    template <class T>
    class bst<T*,moje<T>>;


    template <class T,class Compare>
typename bst<T,Compare>::node* bst<T,Compare>::min(typename bst<T,Compare>::node* root){
    if(root->left==nullptr)
        return root;
    else
        return min(root->left);
}

template <class T,class Compare>bst<T,Compare>::bst():root(nullptr){}
template <class T,class Compare>bst<T,Compare>::bst(bst &&){}
template <class T,class Compare>bst<T,Compare>::bst(const bst &){}
template <class T,class Compare> bst<T,Compare> & bst<T,Compare>::operator=(bst<T,Compare> &&){
}
template <class T,class Compare> bst<T,Compare> & bst<T,Compare>::operator=(const bst<T,Compare> &){}

//insert
template <class T,class Compare>
void bst<T,Compare>::insert(T val)
{
    if (root==nullptr)
    {
        node* temp = new node();
        temp->sval(val);
        root = temp;
    }
    else
        root->insert(val,root);
}

template <class T,class Compare>
void bst<T,Compare>::node::insert(T val,node* here)
{
    if(here==nullptr)
    {
        here = new node();
        here->sval(val);
    }
    else if (comp(val,this->gval()))
        here->insert(val,here->glewo());
    else
        here->insert(val,here->gprawo());
}

//remove
template <class T,class Compare>
T bst<T,Compare>::remove(T val){return root->remove(val);}

template <class T,class Compare>
T bst<T,Compare>::node::remove(T val)
{
    if(this==nullptr)
        return false;

    else if (comp(this->gval(),val) && comp(val,this->gval()))
    {
        T temp = this.gval();
        if((this->glewo()==nullptr)&&(this->gprawo()==nullptr))
        {
            delete this;
        }
        else if (this->glewo()==nullptr)
        {
            this = this->gprawo();
        }
        //////////////////////////////////////
        else
        {
            node* tmp = this;
            node* tmp2 = min(this);
            this = tmp2;
            delete tmp;
            delete tmp2;
        }
        //////////////////////////////////////
        return temp;
    }
    else if (comp(val,this->gval()))
        return this->left->remove(val);
    else
        return this->right->remove(val);
}

//find
template <class T,class Compare>
bool bst<T,Compare>::find(T val){return root->find(val);}

template <class T,class Compare>
bool bst<T,Compare>::node::find(T val)
{
    if(this==nullptr)
        return false;
    else if (comp(this->gval(),val) && comp(val,this->gval()))
        return true;
    else if (comp(val,this->gval()))
        return this->left->find(val);
    else
        return this->right->find(val);
}
//wyjscie
template <class T,class Compare>
std::ostream& operator<< (std::ostream &wy, const typename struktury::bst<T,Compare>::node &tree)
{
    if(tree==nullptr)
        return wy;
    wy << tree.glewo();
    wy << " ";
    wy << tree.gval();
    wy << " ";
    wy << tree.gprawo();
    return wy;
  }

}
