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
        class node
        {
        private:
            T val;
            node* left;
            node* right;
        public:
            node() : left(nullptr), right(nullptr) {}

            node* get_l()
            {   return this->left;};
            void set_l(node lewo)
            {   this->left = lewo;};
            node* get_p()
            {   return this->right;};
            void set_p(node prawo)
            {   this->right = prawo;};
            void set_val(T val)
            {   this->val = val;};
            T get_val()
            {   return this->val;};

            void insert_(T val,node* n);
            bool find_(T val);
            T remove_(T val);


            ~node()
            {
                delete this->left;
                delete this->right;
            }
        };

        static Compare cmp;
        node* min_(node* root);
    public:
        node* root;

        node* get_root()
        {   return root;};
        void set_root(node* val)
        {   root = val;};

        bst();
        bst(bst &&);
        bst(const bst &);
        bst &operator=(bst &&);
        bst &operator=(const bst &);
        ~bst()
        {   delete root;};

        void insert_(T val);
        bool find_(T val);
        T remove_(T val);

        friend std::ostream& operator<< <T,Compare>(std::ostream &wy, const typename bst<T,Compare>::node &tree);

    };

    template<class T,class Compare>
    Compare bst<T,Compare>::cmp;
/*
    template<class T> struct moje
    {
        bool operator()(T *a, T *b) const
        {
            return *a <= *b;
        }
    };

    template <class T>
    class bst<T*,moje<T>>; */

    template <class T,class Compare>
//typename bo node* jest typem zwracanym
typename bst<T,Compare>::node* bst<T,Compare>::min_(typename bst<T,Compare>::node* root)
// bst<T,Compare>::node* bst<T,Compare>::min_(bst<T,Compare>::node* root)
{
    if(root->left==nullptr)
        return root;
    else
        return min_(root->left);
}

// po co?
template <class T,class Compare>
bst<T,Compare>::bst():root(nullptr){}
template <class T,class Compare>
bst<T,Compare>::bst(bst &&n)
{

}

template <class T,class Compare>
bst<T,Compare>::bst(const bst &)
{

}

template <class T,class Compare>
bst<T,Compare> & bst<T,Compare>::operator=(bst<T,Compare> &&)
{

}

template <class T,class Compare>
bst<T,Compare> & bst<T,Compare>::operator=(const bst<T,Compare> &)
{

}

//insert dla bst
template <class T,class Compare>
void bst<T,Compare>::insert_(T val)
{
    if (root==nullptr)
    {
         std::cout<<"\n bst insert in";
        node* temp = new node();
        temp->set_val(val);
         std::cout<<"\n bst val= "<<val;
        root = temp;
    }
    else
        root->insert_(val,root);
}

//insert dla node
template <class T,class Compare>
void bst<T,Compare>::node::insert_(T val,node* n)
{
    if(n==nullptr)
    {
        n = new node();
        n->set_val(val);
        std::cout<<"\n node val= "<<val;
    }
    else if (cmp(val,this->get_val()))
        {   std::cout<<"\n node left ";
            n->insert_(val,n->get_l()); }
    else
       {
           std::cout<<"\n node right ";
           n->insert_(val,n->get_p());
       }
}

//find dla bst
template <class T,class Compare>
bool bst<T,Compare>::find_(T val)
{   return root->find_(val);}

//find dla node
template <class T,class Compare>
bool bst<T,Compare>::node::find_(T val)
{
    if(this==nullptr)
        return false;
    else if (comp(this->get_val(),val) && comp(val,this->get_val()))
        return true;
    else if (comp(val,this->get_val()))
        return this->left->find_(val);
    else
        return this->right->find_(val);
}

//remove dla bst
template <class T,class Compare>
T bst<T,Compare>::remove_(T val)
    {return root->remove_(val);}

//remove dla node
template <class T,class Compare>
T bst<T,Compare>::node::remove_(T val)
{
    if(this==nullptr)
        return false;

    else if (comp(this->get_val(),val) && comp(val,this->get_val()))
    {
        T temp = this.get_val();
        if((this->get_l()==nullptr)&&(this->get_p()==nullptr))
        {
            delete this;
        }
        else if (this->get_l()==nullptr)
        {
            this = this->get_p();
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
    else if (comp(val,this->get_val()))
        return this->left->remove_(val);
    else
        return this->right->remove_(val);
}


//wyjscie
template <class T,class Compare>
std::ostream& operator<<(std::ostream &wy, const typename struktury::bst<T,Compare>::node *tree)
{
    show(wy, tree);
    if(tree==nullptr)
        return wy;
    wy << tree.get_l();
    wy << " ";
    wy << tree.get_val();
    wy << " ";
    wy << tree.get_p();
    return wy;
  }

template<typename T, class C>
    void bst<T, C>::inOrder(ostream &out, bst::node *root)
     {
        if (root != nullptr) {
            inOrder(out, root->left);
            out << root->key << " ";
            inOrder(out, root->right);
        }
    }

}
