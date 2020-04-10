//Определоение операций.

#include "MyVector.h"

/*
MyVector::MyVector()
{
	
}
*/
//+
MyVector::MyVector(size_t size, ResizeStrategy ResizeStrategyK, float coef)//+  Конструктор (c 3 параметрами)(по умолчанию).
{
	this->_size = size;
	
	this->_ResizeStrategy = ResizeStrategyK;
	
	this->_coef = coef;
	
	if (this->_ResizeStrategy == ResizeStrategy::Multiplicative)
    {
        if (this->_size == 0)
        {
			this-> _capacity = 2;
        }
        else
        {
          this-> _capacity = this->_size * this->_coef;
        }
       
	   this->_data = new ValueType[this->_capacity];
    }
    else
    {
        this->_capacity = this->_size + 2;
    }

    this->_data = new ValueType[this->_capacity];
}
//+
MyVector::MyVector(size_t size, ValueType value, ResizeStrategy ResizeStrategyK, float coef)//+
{
	this->_size = size;
	
	this->_ResizeStrategy = ResizeStrategyK;
	
	this->_coef = coef;
	
	if (this->_ResizeStrategy == ResizeStrategy::Multiplicative)
    {
        if (this->_size == 0)
        {
			this-> _capacity = 2;
        }
        else
        {
          this-> _capacity = this->_size * this->_coef;
        }
       
	   this->_data = new ValueType[this->_capacity]();//массив занулен.
    }
    else
    {
        this->_capacity = this->_size + 2;
    }

    this->_data = new ValueType[this->_capacity]();//массив занулен.
	
	for(size_t i=0; i < this->_size; i++ )
	{
		this->_data[i] = value;
	}
}
//+
MyVector::MyVector(const MyVector& copy)//+
{
	this->_size = copy._size;
	
	this->_capacity = copy._capacity;
	
	this->_ResizeStrategy = copy._ResizeStrategy;
	
	this->_data = new ValueType[this->_capacity];//массив не занулен.
	
	
	for(size_t i = 0; i < this->_size; i++)
	{
		this->_data[i] = copy._data[i];//+
	}
}

MyVector& MyVector::operator=(const MyVector& copy)//-
{
	
	if(this->_size == copy._size)
	{
		if(this->_capacity == copy._capacity)
		{
			this->_size = 2 * copy._size;
			
		}
		
		
		
	}
	
	
	
	
	
	
	
	this->_size = copy._size;
	
	
	
	this->_data = new ValueType[this->_capacity];
	
	this->_capacity = copy._capacity;
	
	this->_ResizeStrategy = copy._ResizeStrategy;
	
	
	
	
	
	
	
	for(size_t i = 0; i < this->_size; i++)
	{
		this->_data[i] = copy._data[i];//+
	}
	
	this->_capacity =copy._capacity;
}

MyVector::~MyVector()//+
{
	delete[] this->_data;
}

size_t MyVector::capacity() const //+
{
	return (this->_capacity);
}

size_t MyVector::size() const //+
{
	return (this->_size);
}

float MyVector::loadFactor()//+
{
	return ( static_cast <float> ((this->_size) / (this->_capacity)));
}

ValueType MyVector::operator[](const size_t i) const //+-
{
	if((i > _size) ||( i < 0))
    {
        return 666; //
    }
    else
    {
        return ( this->_data[i] );
    }
	
	return ( this->_data[i] );
}

void MyVector::pushBack(const ValueType& value)//+
{
	reserve(this->_size + 1);
	
	this->_data[this->_size] = value;
	
	//this->_size++;
}

void MyVector::insert(const size_t i, const ValueType& value)//+-
{
	if (i >= this->_size)
	{
        this-> pushBack(value);
	}
	
    reserve(_size+1);

    for(int j = _size; j >= i; --j)
	{
        this->_data[j] = this-> _data[j-1];
	}
   
	this->_data[i] = value;
	this->_size++;
	
}

void MyVector::insert(const size_t i, const MyVector& value)//+-
{
    for(int j = 0; j < value._size; ++j)
	{
		insert(i+j, value._data[j]);
	}
	
}

void MyVector::popBack()//+-
{
	this->_size--;
    shrink_fit();
}

void MyVector::erase(const size_t i)//+-
{
	for (int j = i; j < this->_size; ++j)
	{
        this->_data[j] = this->_data[j+1];
	}

    this->_size--;
    
	shrink_fit();
}

void MyVector::erase(const size_t i, const size_t len)//+
{
	for (int j = 0; j < len; j++)
	{
        erase(i);
	}
}

long long int MyVector::find(const ValueType& value, bool isBegin = true) const//+//метод поиска
{
    if (isBegin == true)
    {
        for (int i = 0; i < this->_size; ++i)
		{
            if (this->_data[i] == value)
			{
                return i;
			}
		}

		return -1;
    }

    if (isBegin == false)
    {
        for (int i = this->_size - 1; i >= 0; --i)
		{
            if (this->_data[i] == value)
			{
                return ( this->_size - (this->_size - i) );
			}
		}

		return -1;
    }
}

void MyVector::reserve(const size_t capacity)//+
{
	if (capacity <= this->_capacity)
	{
		cout << "";
	}

    if (this->_ResizeStrategy == ResizeStrategy::Additive)
    {
        this->_capacity = (this->_capacity == 0) ? 1 : this->_capacity;
           
			while (this->_capacity < capacity )
			{
                this->_capacity <<= 1;
			}
		   
            if (_data == nullptr)
			{
               this-> _data = new ValueType[this->_capacity];
			}
            else
            {
				ValueType *temp = this->_data;
				this->_data = new ValueType[this->_capacity];
				memcpy(this->_data, temp, _size * sizeof(ValueType));
				delete[] temp;
            }
    }
    else
    {
        this->_capacity = this->_capacity * this->_coef;

        if (this->_data == nullptr)
		{
        this->_data = new ValueType[this->_capacity];
		}
        else
        {
            ValueType *temp = this->_data;
            this->_data = new ValueType[this->_capacity];
            memcpy(this->_data, temp, this->_size * sizeof(ValueType));
            delete[] temp;
        }
    }
}

void MyVector::resize(const size_t size, const ValueType value)//+
{
    if (size > this->_size)
    {
        for (int i = this->_size; i < size; ++i)
		{
            pushBack(value);
		}
    }
    else
    {
        this->_size = size;

        if(this->_ResizeStrategy == ResizeStrategy::Multiplicative)
		{
            this->_capacity = this->_size * this->_coef;
		}
        else
        {
            this->_capacity = this->_size + 2;
        }
    }
}

void MyVector::clear()//+
{
   for (int i = 0; i < this->_size; i++)
   {
        this->_data[i] = 0;
   }

   this->_size = 0;
}

void MyVector::shrink_fit()//+
{
    float load_factor = this->loadFactor();

    if ( load_factor < 0.5f)
    {
        this->_capacity = this->_size;

        ValueType *temp = this->_data;
        this->_data = new ValueType[this->_capacity];
        memcpy(this->_data, temp, this->_size * sizeof(ValueType));
        delete[] temp;
    }
}

void MyVector::Show_ResizeStrategy() const//+
{
    if(_ResizeStrategy == ResizeStrategy::Additive)
	{
        cout << "Additive - " << static_cast <int> (_ResizeStrategy);
    } 
	else 
	{
        cout << "Multiplicative - " << static_cast <int> (_ResizeStrategy);
    }
}