/*
Copyright (c) 2009,Roc King

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/*
http://www.cppblog.com/ownwaterloo/archive/2009/04/16/get_result_of_preprocessing.html

http://www.cppblog.com/ownwaterloo/archive/2009/04/15/predefined_macro__MSC_VER.html
http://www.cppblog.com/ownwaterloo/archive/2009/04/16/predefined_macro___GNUC__.html

http://www.cppblog.com/ownwaterloo/archive/2009/04/15/environment_for_using_cl_from_command_line.html
http://www.cppblog.com/ownwaterloo/archive/2009/04/16/write_compile_script_for_msvc.html

following these links above for more information.
*/



int main() {
    int result = 
#if defined(__GNUC__)
__GNUC__
#elif defined(_MSC_VER)
_MSC_VER
#else
#error unknown compiler
#endif
;
    return result;
}
