# Объявление переменной для хранения списка файлов с исходным кодом программы Test1
set(TEST1_SOURCES
  "Test1.c"
)

# Создание исполняемого файла Test1
add_executable (Test1 ${TEST1_SOURCES})

# Указываем место с заголовочным файлом библиотеки Dictionary
include_directories("${SysProg_Lab_01_part_2_SOURCE_DIR}/Dictionary")

# Указываем, что необходимо скомпоновать Test1 с библиотекой Dictionary
target_link_libraries (Test1 LINK_PUBLIC Dictionary)
