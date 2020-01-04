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
nmake /f data.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data1.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data2.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data3.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data_pkg.win.mak
if %errorlevel% neq 0 goto failure
nmake /f class_file_struct.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data4.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data5.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data6.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data7.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data8.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data9.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data10.win.mak
if %errorlevel% neq 0 goto failure
nmake /f data11.win.mak
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

