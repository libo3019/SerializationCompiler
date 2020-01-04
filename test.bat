SerializationCompiler.exe -i data.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data1.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data2.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data3.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data_pkg.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i class_file_struct.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data4.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data5.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data6.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data7.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data8.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data9.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data10.idf
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data11.idf
if %errorlevel% neq 0 goto failure
cl /EHsc /c data.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data1.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data2.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data3.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data_pkg.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c class_file_struct.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data4.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data5.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data6.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data7.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data8.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data9.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data10.cc
if %errorlevel% neq 0 goto failure
cl /EHsc /c data11.cc
if %errorlevel% neq 0 goto failure
goto success
:failure
cd ..
cd SerializationCompiler
@echo failure!
goto end
:success
@echo success!
goto end
:end

