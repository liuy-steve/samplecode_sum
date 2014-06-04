#include <iostream>
#include <sstream>

template <int nlevel = 0>
class CppLog:public std::stringstream
{
public:
	CppLog(const char* i_sfile, const int i_nline)
		: std::stringstream()
		, m_sfile_(i_sfile)
		, m_nline_(i_nline)
	{

	};
	virtual ~CppLog()
	{
		using std::cout;
		cout << "ģ����־�����������־�ȼ� " << nlevel << std::endl;
		cout << "ģ����־����������к�		" << GetLine() << std::endl;
		cout << "ģ����־����������ļ�		" << GetFile() << std::endl;
		cout << this->str();
	};
public:
//	template <typename T>
// 	CppLog & operator << (const T& i_val)
// 	{
// 		m_ss_ << i_val;
// 		cout << m_ss_.str();
// 		m_ss_.clear();
// 		return *this;
// 	}

public:
	const char* const GetFile() const {return m_sfile_;}
	const int GetLine() const {return m_nline_;}

	
private:
	const char* m_sfile_;
	const int m_nline_;
	std::stringstream m_ss_;
};

template <int nlevel>
std::ostream& operator << (std::ostream & os, const CppLog<nlevel> & log)
{
	os << "������־�ȼ� " << nlevel << std::endl;
	os << "�����ļ��� " << log.GetLine() << std::endl;
	os << "�����к� " << log.GetFile() << std::endl;
	return os;
}