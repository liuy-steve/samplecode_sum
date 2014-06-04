#include <iostream>
#include <sstream>
#include <iosfwd>
#include <string>

template <int nlevel = 0>
class CppLog
{
public:
	CppLog(const char* i_sfile, const int i_nline)
		: m_sfile_(i_sfile)
		, m_nline_(i_nline)
	{
		m_ss_ << "module output£ºerror level " << nlevel;
		m_ss_ << " module output£ºerror line " << GetLine();
		m_ss_ << " module output£ºerror file " << GetFile();
	};
	~CppLog()
	{
		cout << m_ss_.str();
// 		std::string sdest ;
// 		m_ss_ >> sdest;
// 		printf("%s", sdest.c_str());
	};

	std::ostream& OutPut()
	{ 
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
