

#include "String.h"

void String::Resize()
{
	this->capacity *= 2;
	char* temp = new char[this->capacity];
	strncpy(temp, this->string, this->count);
	delete[] this->string;
	this->string = temp;
}
const char* String::GetString() const
{
	return this->string;
}
String::String()
{
	this->count = 0;
	this->capacity = 8;
	this->string = new char[capacity];
	strcpy(this->string, "");
}
String::String(char* string)
{
	this->count = 0;
	this->capacity = 4;
	int len = strlen(string) + 1;
	this->count = len;
	this->capacity = 2 * len;
	this->string = new char[this->capacity];
	strncpy(this->string, string, count);
	this->count--;
}
void String::copyFunc(const String& string)
{
	this->count = string.count;
	this->capacity = string.capacity;
	this->string = new char[capacity];
	strcpy(this->string, string.GetString());
}
String::~String()
{
	delete[] this->string;
}
String::String(const String& string)
{
	this->copyFunc(string);
}
String& String::operator=(const String& string)
{
	if (this != &string)
	{
		delete[] this->string;
		this->copyFunc(string);
	}
	return *this;
}
bool String::operator==(const char* string)
{
	if (strcmp(this->string,string) == 0)
	{
		return true;
	}
	return false;
}
String String::operator+(const String& string)
{
	String temp = *this;
	temp.Append(string);
	return temp;
}

void String::Append(const char* string)
{
	int len = strlen(string) + 1;
	while (this->count + len > this->capacity)
	{
		this->Resize();
	}
	for (size_t i = 0; i < len; i++)
	{
		this->string[this->count++] = string[i];
	}
	count--;
}
void String::Append(const char c)
{
	if ((this->count + 2) > this->capacity)
	{
		this->Resize();
	}
	this->string[count++] = c;
	this->string[count] = '\0';
}
void String::Append(const String& string)
{
	this->Append(string.GetString());
}

void String::Insert(const int index, const char c)
{
	if (index < this->count)
	{
		if (this->count > this->capacity)
		{
			this->Resize();
		}
		String temp;
		for (size_t i = index; i < this->count; i++)
		{
			temp.Append(this->GetString()[i]);
		}
		this->string[index] = c;
		this->count = index + 1;
		this->Append(temp);

	}
	else
	{
		//When I learn exeptions will add a suitable error!
	}
}
void String::Insert(const int index, const char* string)
{
	if (index <= this->count)
	{
		while (this->count > this->capacity)
		{
			this->Resize();
		}
		String temp;
		for (size_t i = index; i < this->count; i++)
		{
			temp.Append(this->GetString()[i]);
		}
		this->count = index;
		this->Append(string);
		this->Append(temp);
	}
	else
	{
		//When I learn exeptions will add a suitable error!
	}
}
void String::Insert(const int index, const String& string)
{
	this->Insert(index, string.GetString());
}

void String::Remove(const int index)
{
	if (index < this->count)
	{
		String temp;
		for (size_t i = index + 1; i < this->count; i++)
		{
			temp.Append(this->GetString()[i]);
		}
		this->count = index;
		this->Append(temp);
	}
	else
	{
		//When I learn exeptions will add a suitable error!
	}
}
void String::Remove(const int fromIndex, const int toIndex)
{
	if ((fromIndex <= toIndex) && (toIndex < this->count))
	{
		String temp;
		for (size_t i = toIndex + 1; i < this->count; i++)
		{
			temp.Append(this->GetString()[i]);
		}
		this->count = fromIndex;
		this->Append(temp);
	}
	else
	{
		//When I learn exeptions will add a suitable error!
	}
}

void String::Replace(const char replaceME, const char pasteME)
{
	int len = this->count;
	for (size_t i = 0; i < len; i++)
	{
		if (this->GetString()[i] == replaceME)
		{
			this->Remove(i);
			this->Insert(i, pasteME);
		}
	}
}
void String::Replace(const char replaceME, const char pasteME, const int fromIndex, const int toIndex)
{
	if ((fromIndex <= toIndex) && (toIndex < this->count))
	{
		for (size_t i = fromIndex; i <= toIndex; i++)
		{
			if (this->GetString()[i] == replaceME)
			{
				this->Remove(i);
				this->Insert(i, pasteME);
			}
		}
	}
	else
	{
		//When I learn exeptions will add a suitable error!
	}

}

void String::Clear()
{
	delete[] string;
	this->count = 0;
	this->capacity = 4;
	string = new char[capacity];
	strcpy(this->string, "");
}
int String::Length()
{
	return this->count;
}
void String::Print()
{
	std::cout << this->string << "\n";
}
char String::operator[](const int index)
{
	return this->GetString()[index];
}
std::ostream& operator<<(std::ostream& stream, const String& string)
{
	return  stream << string.GetString();

}
std::istream& operator >> (std::istream& stream, String& string)
{
	char buffer[1024];
	stream.getline(buffer, 1024);
	string.Append(buffer);
	return stream;
}