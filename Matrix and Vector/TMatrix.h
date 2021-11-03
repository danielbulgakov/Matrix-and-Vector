#pragma once
#include "TVector.h"
#include <iostream>
#include <cassert>

template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& mt); 
	TMatrix(const TVector<TVector<ValType> >& mt); 

	TMatrix& operator==(const TMatrix& mt); 
	TMatrix& operator= (const TMatrix& mt); 
	TMatrix operator+ (const TMatrix& mt); 
	TMatrix operator- (const TMatrix& mt); 
	TMatrix operator* (const TMatrix& mt); 

	friend std::istream& operator>>(std::istream& in, TMatrix& mt) {
		for (size_t i = 0; i < mt.Size; i++) {
			in >> mt.pVector[i];
		}
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const TMatrix& mt) {
		for (size_t i = 0; i < mt.Size; i++) {
			out << mt.pVector[i] << std::endl;
		}
		return out;
	}
};

template<class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType>>(s) {

	for (size_t i = 0; i < s; i++) {
		this->pVector[i] = TVector<ValType>(s-i, i);
		
	}

}

template<class ValType>
TMatrix<ValType>::TMatrix(const TMatrix& mt) : TVector<TVector<ValType>>(mt) {

}

template<class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>>& mt) : TVector<TVector<ValType>>(mt) {

}


template<class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (this != &mt) {

		if (this->Size != mt.Size) {
			delete[] this->pVector;
			this->pVector = new TVector<ValType>[mt.Size];
		}
		this->Size = mt.Size;
		for (size_t i = 0; i < this->Size; i++)
			this->pVector[i] = mt.pVector[i];
	}
	return *this;

}

template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	return (TVector<TVector<ValType>>(mt) + TVector<TVector<ValType>>(*this));
}

template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	return (TVector<TVector<ValType>>(*this) - TVector<TVector<ValType>>(mt));
}

template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix<ValType>& mt)
{
	TMatrix<ValType> tmp = TMatrix<ValType>(*this);
	ValType NUll = tmp[0][0] - tmp[0][0];
	for (size_t i = 0; i < this->Size; i++) {
		for (size_t j = 0; j < this->Size - i; j++) {
			tmp[i][j] = NUll;
			for (size_t k = 0; k <= j ; k ++) {
				tmp[i][j] = (tmp[i][j]) + ((*this)[i][k] * mt[k + i][j - k]);
			}
		}
	}

	return tmp;
}