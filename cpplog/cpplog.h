#include <iostream>
#include <sstream>
#include <iosfwd>

template <int nlevel = 0>
class CppLog:public std::stringstream
{
public:
	CppLog(const char* i_sfile, const int i_nline)
		: std::stringstream()
		, m_sfile_(i_sfile)
		, m_nline_(i_nline)
	{
// 		*this << "module output£ºerror level " << nlevel;
// 		*this << " module output£ºerror line " << GetLine();
// 		*this << " module output£ºerror file " << GetFile();
	};
	virtual ~CppLog()
	{
		using std::cout;
		cout << str();
	};
	
// 	CppLog & operator << (const char *_Val)
// 	{
// 		return ::operator << <char, std::char_traits<char> >(*this, _Val);
// 	}

public:
	const char* const GetFile() const {return m_sfile_;}
	const int GetLine() const {return m_nline_;}

	
private:
	const char* m_sfile_;
	const int m_nline_;

	//std::stringstream m_ss_;
};

// template <int nlevel>
//CppLog<nlevel> & operator << (CppLog<nlevel> & os, const char *_Val)
//{
//	return ::operator << <char, std::char_traits<char> >(os, _Val);
//}