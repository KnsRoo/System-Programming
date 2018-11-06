/**
 * \file
 * \brief Заголовочный файл, создаваемой библиотеки Dictioanry
 * \warning Этот файл менять нельзя!
 */

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

/**
 * \brief Перечисление кодов ошибок, возвращаемых функций библиотеки Dictionary.
 *
 * Функций, выполняющие действия над "Словарём" и не возвращающие результат
 * должны вернуть код ошибки выполнения.
 * Если всё прошло без ошибок, то они возвращают код DICT_RESULT_OK.
 */
typedef enum DictionaryResult_e {
    DICT_RESULT_OK              = 0, ///< Поцедура отработала без ошибок.
    DICT_RESULT_NO_KEY_EXIST    = 1, ///< Записи с заданным ключём не существует.
    DICT_RESULT_KEY_EXIST       = 2, ///< Запись с заданным ключём уже существует
    DICT_RESULT_UNDEFINE_ERROR  = -1 ///< Произошла не документированная ошибка.
} DictionaryResult;

/**
 * \brief Структура описывающая класс "Словарь".
 * \warning Элементы этой структуры вы определяете самостоятельно в `Dictioanry.c`.
 */
struct Dictionary_s;

typedef struct Dictionary_s Dictionary;

/**
 * \brief Создание объекта "Словарь".
 * \return Ссылка на новый объект "Словарь".
 * \warning Удаление созданного объекта производится через вызов функции `dictionary_destroy`.
 */
Dictionary *dictionary_create(void);


/**
 * \brief Деструктор объекта "Словарь".
 * \param self ссылка на структуру, которую надо подготовить к удалению.
 */
void dictionary_destroy(Dictionary *dictionary);

/**
 * \brief Добавление записи в "Словарь".
 * \param self ссылка на "Словарь".
 * \param key ключевая строка добавляемой записи.
 * \param value значение добавляемой записи.
 * \return Если добавление произошло успешно то возвращается DICT_RESULT_OK.
 *         Если запись с таким ключём уже существует, то возвращается DICT_RESULT_KEY_EXIST.
 */
int dictionary_add(Dictionary *dictionary, const char *key, const char *value);

/**
 * \brief Удаление записи из "Словаря".
 * \param self ссылка на "Словарь".
 * \param key ключевая строка удаляемой записи.
 * \return Если удаление произошло успешно то возвращается DICT_RESULT_OK.
 *         Если записи с таким ключём не существует, то возвращается DICT_RESULT_NO_KEY_EXIST.
 */
int dictionary_remove(Dictionary *dictionary, const char *key);

/**
 * \brief Получение записи из "Словаря" по ключу.
 * \param self ссылка на "Словарь".
 * \param key ключевая строка для поиска записи.
 * \return Ссылка на константную строку, соответстующая ключу в "Словаре".
 *         Если запись с таким ключём не существует, то возвращается NULL.
 */
const char *dictionary_get(Dictionary *dictionary, const char *key);

#endif//__DICTIONARY_H__
