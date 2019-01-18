#pragma once
template <typename T>
class shared_ptr
{
public:
	shared_ptr();
	shared_ptr(T* ptr);
	shared_ptr(shared_ptr<T>& shPtr);
	~shared_ptr();
	shared_ptr<T> operator=(shared_ptr<T>& shPtr);
	T& operator* ()const;
	T* operator-> () const;
	int use_count() const;
	bool unique();
	
private:
	T* m_ptr;
	int* m_count;
};
template <typename T>
shared_ptr<T>::shared_ptr()
{
	this->m_ptr = nullptr;
	this->m_count = nullptr;
}
template <typename T>
shared_ptr<T>::shared_ptr(T* ptr)
{
	this->m_ptr = ptr;
	this->m_count = new int(1);
}
template <typename T>
shared_ptr<T>::shared_ptr(shared_ptr<T>& shPtr)
{
	this->m_ptr = shPtr.m_ptr;
	this->m_count = shPtr.m_count;
	++(*m_count);
}
template <typename T>
shared_ptr<T>::~shared_ptr()
{
	if (m_count)
	{
		if (*m_count == 1)
		{
			delete m_count;
			delete m_ptr;
		}
		else
		{
			--(*m_count);
		}
	}
}
template <typename T>
shared_ptr<T> shared_ptr<T>::operator=(shared_ptr<T>& shPtr)
{
	if (this != &shPtr)
	{
		if (m_count)
		{
			if ((*m_count) == 1)
			{
				delete m_count;
				delete m_ptr;
			}
			else
			{
				(*m_count)--;
			}
		}
		m_ptr = shPtr.m_ptr;
		m_count = shPtr.m_count;
		++(*m_count);
	}
	return *this;
}
template <typename T>
T& shared_ptr<T>::operator* ()const
{
	return (*m_ptr);
}
template <typename T>
T* shared_ptr<T>::operator-> () const
{
	return m_ptr;
}
template <typename T>
int shared_ptr<T>::use_count() const
{
	return (*m_count);
}
template <typename T>
bool shared_ptr<T>::unique()
{
    return ((*m_count) == 1);
}