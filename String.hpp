#include <iostream>

class String {
public:
	String() = default;
	String(const char* string) {
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String& other) {
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept { 
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	String& operator=(String&& other) noexcept {
		printf("Moved\n");

		if (this != &other) {
			delete[] m_Data;

			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		return *this;
	}

	~String() {
		printf("Destroyed!\n");
		delete[] m_Data;
	}

	uint32_t Size() {
		return m_Size;
	}

	char get(int index) {
		return m_Data[index];
	}

	void Print() {
		for (uint32_t i = 0; i < Size(); ++i)
			printf("%c", get(i));

		printf("\n");
	}

private:
	char* m_Data;
	uint32_t m_Size;
};
