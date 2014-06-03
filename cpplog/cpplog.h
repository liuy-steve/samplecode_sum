#include <iostream>
#include <sstream>
template <int nlevel = 0>
class CppLog
{
public:
	CppLog(const char* i_sfile, const int i_nline)
		: m_sfile_(i_sfile)
		, m_nline_(i_nline)
	{

	};
	~CppLog(){};
public:
	template <typename T>
	std::ostream & operator << (const T& i_val)
	{
		m_ss_ << i_val;
		cout << m_ss_.str();
		m_ss_.clear();
		return m_ss_;
	}

public:
	const char* const GetFile() const {return m_sfile_;}
	const int GetLine() const {return m_nline_;}

	
private:
	const char* m_sfile_;
	const int m_nline_;
	std::stringstream m_ss_;
};

template <int nlevel>
std::ostream& operator << (std::ostream & io, const CppLog<nlevel> & log)
{
	io << "错误日志等级 " << nlevel << std::endl;
	io << "错误文件名 " << log.GetLine() << std::endl;
	io << "错误行号 " << log.GetFile() << std::endl;
	return io;
}