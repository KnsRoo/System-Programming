# Объявление переменной для хранения списка файлов с исходным кодом библиотеки
set(DICTIONARY_SOURCES
  "Dictionary.c"
)

# Объявление переменной для кранения списка заголовочных файлов библиотеки
set(DICTIONARY_HEADERS
  "Dictionary.h"
)

# Создание библиотеки
add_library(Dictionary
  ${DICTIONARY_SOURCES}
  ${DICTIONARY_HEADERS}
)
