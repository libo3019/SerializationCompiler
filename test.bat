SerializationCompiler.exe -i data.def
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data1.def
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data2.def
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data3.def
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data_pkg.def
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i class_file_struct.def
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data4.def
if %errorlevel% neq 0 goto failure
SerializationCompiler.exe -i data5.def
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

