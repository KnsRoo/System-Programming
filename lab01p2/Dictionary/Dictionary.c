/*
 * ru: Этот файл вы можете модифицировать
 */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "Dictionary.h"

/*
 * ru: Эту структуру можно определить так, как вам удобно.
 */
struct Dictionary_s {
	int key;
	int value;
	Dictionary *next;
};

/*
 * ru: Конструктор словаря
 */
Dictionary*
dictionary_create(void) {
	return calloc(1,sizeof(Dictionary));
}

/*
 * ru: Деструктор словаря
 */
void
dictionary_destroy(Dictionary *self)
{
	if (self == NULL) return;
	if (self->next != NULL) dictionary_destroy(self->next);
	free(self);
}

/*
 * ru: Добавление элемента в словарь
 */
int
dictionary_add(Dictionary *self, const char *key, const char *value)
{
	int ret = 0;
	int k = (int)key;
	if (self->key){
		while (self->next != 0){
			int id = (int)self->key;
			if (id == k) { ret = 1; }
			self = self->next;
		}
		Dictionary *w;
		w = dictionary_create();
		w->key = (int)key;
		w->value = (int)value;
		w->next = 0;
		self->next = w;
	} else {
		self->key = (int)key;
		self->value = (int)value;
		self->next = 0;
	}
    return ret;
}

/*
 * ru: Удаление элемнта из словаря
 */
int
dictionary_remove(Dictionary *self, const char *key)
{
	int k = (int)key;
	while (1){
		int id = (int)self->key;
		if (id == k){
			Dictionary *l = NULL;
			l = self->next;
			self->next = l->next;
			dictionary_destroy(l);
			break;
		}
		self = self->next;
	}
	return 0;
}

/*
 * ru: Получение элемента из словаря
 */
const char *
dictionary_get(Dictionary *self, const char *key)
{
	while (self->next != 0){
		int id = (int)self->key;
		int k = (int)key;
		if (k == id) {
			char *ret = (char *)self->value;
			return ret;
		}
		self = self->next;
	}
    return NULL;
}
