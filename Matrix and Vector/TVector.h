#pragma once
#include <iostream>
#include <ostream>
#include <String>

template <class ValType>
class TVector
{
protected :
	ValType* pVector;
	size_t Size;
	size_t StartIndex;
public:
	TVector(size_t size = 3, size_t start = 0);
	TVector(const TVector& v); 
	~TVector();

	size_t GetSize() ;
	size_t GetStart() ;
	ValType& GetElem(size_t pos);

	ValType& operator[](const size_t pos) const;
	bool operator==(const TVector& v) ;
	TVector& operator= (const TVector& v); 
	TVector operator+ (const ValType& val); 
	TVector operator- (const ValType& val);
	TVector operator* (const ValType& val); 
	TVector operator+ (const TVector& v); 
	TVector operator- (const TVector& v); 
	TVector operator* (const TVector& v);
	

	friend std::istream& operator>>(std::istream& in, TVector& v) {
		for (size_t i = 0; i < v.StartIndex; i++) std::cout << "0 ";
		for (size_t i = 0; i < v.GetSize(); i++) {
			in >> v[i];

		}
		
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, TVector& v) {
		out << '{';
		std::string buf;
		for (size_t i = 0; i < v.GetStart(); i++) {
			buf += "0, ";
		}
		for (size_t i = 0; i < v.GetSize(); i++) {
			buf += std::to_string(v[i]);
			buf += ", ";
		}

		out << (!buf.empty() ? std::string(buf.begin(), buf.end() - 2) : std::string()) << '}';
		return out;
	}
};

//------------------------------------------------------------------------------

template<class ValType>
TVector<ValType>::TVector(size_t size, size_t start) : Size(size), StartIndex(start)
{
	pVector = new ValType[size];	
}

template<class ValType>
TVector<ValType>::TVector(const TVector& v)
{
	StartIndex = v.StartIndex;
	Size = v.Size;
	pVector = new ValType[Size];
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
	
	if (this != &v)
	{
		if (Size != v.Size)
		{
			
			delete[] pVector;
			this->pVector = new ValType[v.Size];
		}
		this->Size = v.Size;
		this->StartIndex = v.StartIndex;
		for (size_t i = 0; i < Size; i++)
			this->pVector[i] = v.pVector[i];
	}

	
	return *this;
}

template<class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
}

template<class ValType>
size_t TVector<ValType>::GetSize()
{
	return size_t(Size);
}

template<class ValType>
size_t TVector<ValType>::GetStart()
{
	return size_t(StartIndex);
}

template<class ValType>
ValType& TVector<ValType>::GetElem(size_t n)
{
	return (pVector[n]);
}

template<class ValType>
ValType& TVector<ValType>::operator[](const size_t i) const
{
	return (pVector[i]);
}

template<class ValType>
bool TVector<ValType>::operator==(const TVector& v)
{
	if (Size != v.Size)return false;
	if (StartIndex != v.StartIndex) return false;
	for (size_t i = 0; i < Size; i++) {
		if (pVector[i] != v.pVector[i])
			return false;
	}
	return true;
}


template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector& v)
{
	TVector<ValType> tmp(*this);
	for (size_t i = 0; i < Size; i++) {
		tmp[i] = tmp[i] + v[i];

	}
	return tmp;

}

template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector& v)
{
	TVector<ValType> tmp(*this);
	for (size_t i = 0; i < Size; i++) {
		tmp[i] = tmp[i] - v[i];

	}
	return tmp;

}

template<class ValType>
TVector<ValType> TVector<ValType>::operator*(const TVector& v)
{
	TVector<ValType> tmp(*this);
	for (size_t i = 0; i < Size; i++) {
		tmp[i] = tmp[i] * v[i];

	}
	return tmp;

}

template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
	TVector<ValType> tmp(*this);
	for (size_t i = 0; i < Size; i++) {
		tmp[i] = tmp[i] + val;
	}
	return tmp;

}

template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
	TVector<ValType> tmp(*this);
	for (size_t i = 0; i < Size; i++) {
		tmp[i] = tmp[i] - val;
	}
	return tmp;

}

template<class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
	TVector<ValType> tmp(*this);
	for (size_t i = 0; i < Size; i++) {
		tmp[i] = tmp[i] * val;
	}
	return tmp;

}

