#ifndef VECTORCLASE_VECTORPEL_H
#define VECTORCLASE_VECTORPEL_H
#include "iostream"
using namespace std;

template<typename T> class VectorPEL
        {
private:
            T * v_; //Puntero al inicio
            T * space_; //Puntero que apunta al siguiente del ultimo elemento almacenado
            T * last_; // Puntero que apunta al siguiente bloque del ultimo elemento del vector
public:
            //Constructores
            VectorPEL(): v_{new T[0]}, space_{v_}, last_{v_}{ //Constructor vacio
            }
            VectorPEL(VectorPEL<T> const& v):v_{new T[v.capacity()]}, space_{v_+ v.size()}, last_{v_ + v.capacity()}{
                try {
                    for (auto i = size_t{0}; i < v.size(); ++i) {
                        v_[i] = v[i];
                    }
                }catch (...){
                    delete[] v_;
                    throw;
                }
            } // Constructor copia
            ~VectorPEL(){delete[] v_;}

            //Metodos de capacidad:
            auto size() const -> size_t  {return  space_ - v_;}
            auto capacity() const -> size_t {return  last_ - v_;}
            auto empty() const -> bool {return  v_ == space_;}

            //Metodos de acceso:
            auto begin() const -> T const* {return v_;}
            auto end() const -> T const* {return  space_;}

            //Metodo Push_back:
            auto push_back(T const& valor) -> void {
                if (space_ == last_){
                    size_t cap = capacity(), new_cap = (cap == 0)? 2 : 2*cap;
                    T * new_block = new T[new_cap];
                    try{
                        for (auto i = size_t{0}; i < cap; ++i) {
                            new_block[i]=v_[i];
                        }
                        new_block[cap] = valor;
                    }catch (...){
                        delete[] new_block;
                        throw;
                    }
                    delete[] v_;
                    v_ = new_block;
                    space_ = new_block + cap + 1;
                    last_ = new_block + new_cap;
                } else {
                    *space_ = valor;
                    ++space_;
                }
            }

            auto at(size_t __n) const
            {
            return (v_)[__n];
            }
};
#endif //VECTORCLASE_VECTORPEL_H