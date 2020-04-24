#include "Array.h"
template <typename T> 
class GrowableArray : public Array<T>
{
	public:
		GrowableArray<T>(int size2) : Array<T>(size2){}
		virtual T& operator[](int i);
		virtual T operator[](int i) const;

};
template<typename T>
T& GrowableArray<T>::operator[](int i) 
{
	static T tmp;
	int k,tmplen = this->len;
	if(i>=this->len)
	{
		this->len = 2*i;
		this->data = (T *)realloc(this->data,(this->len)*sizeof(T));
		for(k=tmplen;k<this->len;k++)
		{
			(this->data)[k] = 0;
		}

	}
	if(i>=0 && i<this->len)
		return (this->data)[i];
	else
	{
		cout << "Array bound error!" << endl;
		return tmp;
	}
}
template<typename T>
T GrowableArray<T>::operator[](int i) const
{
	if(i>=0 && i<this->len)
		return (this->data)[i];
	else
		return 0;
}

