cl 2>cl.version.txt

cl /E ../../preprocess_only.c /W4
pause

cl /E ../../preprocess_only.c /W4 >stdout.txt
cl /P ../../preprocess_only.c /W4

cl /EP ../../preprocess_only.c /W4
pause
cl /EP ../../preprocess_only.c /W4 >stdout_noline.txt

cl /u ../../preprocess_only.c >u.txt
cl /U_MSC_VER ../../preprocess_only.c >U_MSC_VER.txt
cl /E /D__GNUC__ ../../preprocess_only.c >stdout_D.txt
pause