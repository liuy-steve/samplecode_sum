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
		cout << "模块日志输出：错误日志等级 " << nlevel << std::endl;
		cout << "模块日志输出：错误行号		" << GetLine() << std::endl;
		cout << "模块日志输出：错误文件		" << GetFile() << std::endl;
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
	os << "错误日志等级 " << nlevel << std::endl;
	os << "错误文件名 " << log.GetLine() << std::endl;
	os << "错误行号 " << log.GetFile() << std::endl;
	return os;
}