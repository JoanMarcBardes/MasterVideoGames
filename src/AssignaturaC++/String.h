#pragma once
class String
{
public:

	String();
	String(const char* c);
	String(const String& s);
	String(String&& s);
	~String();

	void operator=(const String& s);
	bool operator==(const String& s);
	String operator+(const String& s);

	int lenght() const;
	void clear();
	String GetMeAString() const;
	
	char* str;
};

