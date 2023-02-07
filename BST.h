//
// Created by 21595 on 2023/1/30.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <iostream>

template<class T>
class BST {
private:
    class Tec {
    public:
        T key;
        Tec *left;
        Tec *right;

        Tec(const T& i_key = 0) {
            key = i_key;
            left = nullptr;
            right = nullptr;
        }
    };

private:
    Tec *m_bst;

public:
    BST(){
        m_bst = nullptr;
    }
    BST(const T& in) {
        m_bst = new Tec(in);
    }

    bool insert(const T& i) {
        if(m_bst == nullptr){
            m_bst = new Tec(i);
            return true;
        }
        Tec *parent = nullptr;
        Tec *temp = m_bst;
        while (temp) {
            if( i < temp->key){
                parent = temp;
                temp = temp->left;
            } else if (i > temp->key){
                parent = temp;
                temp = temp->right;
            } else{//已存在该节点
                return false;
            }
        }
        temp = new Tec(i);
        if(i < parent->key){
            parent->left = temp;
        }else{
            parent->right = temp;
        }
        return true;
    }

    void InTravel(){
        in(m_bst);
    }

    void in(Tec* t){
        if (t == nullptr)return;
        in(t->left);
        std::cout << t->key << " ";
        in(t->right);
    }

    bool deleate(const T& i){
        if(m_bst== nullptr)return false;
        Tec *parent = nullptr;
        Tec *bst = m_bst;
        while (bst){
            if(i < bst->key){
                parent = bst;
                bst = bst->left;
            } else if(i > bst->key){
                parent = bst;
                bst = bst->right;
            } else{
                if(bst->left == nullptr){
                    if(bst == m_bst){
                        bst = bst ->right;
                    } else{
                        if(parent->right == bst) {
                            parent->right = bst->right;
                        } else{
                            parent->left = bst->right;
                        }
                    }
                    delete bst;
                    return true;
                }else if(bst->right == nullptr){
                    if(bst == m_bst){
                        bst = bst ->left;
                    } else{
                        if(parent->right == bst) {
                            parent->right = bst->left;
                        } else{
                            parent->left = bst->left;
                        }
                    }
                    delete bst;
                    return true;
                }else{
                    Tec *minright = bst->right;//找到当前节点右子树的最小值，设为节点
                    Tec *minparent = bst;
                    while (minright->left){
                        minparent = minright;
                        minright = minright->left;
                    }
                    bst->key = minright->key;
                    if(minparent->right == bst){//判断是否为初始位置
                        minparent->left = minright->right;
                    } else{
                        minparent->right = minright->right;
                    }
                    delete minright;
                    return true;
                }
            }
        }
        return false;
    }



};


#endif //BST_BST_H
