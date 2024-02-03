#include <string.h>
#include "hash_tables.h"
#include <string.h> /* Add this line to include the header file for strdup */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_table->size = size;
	hash_table->array = calloc(size, sizeof(hash_node_t *));
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;

	return (hash_table);
}

void hash_table_destroy(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *current, *next;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current != NULL)
        {
            next = current->next;
            free(current->key);
            free(current->value);
            free(current);
            current = next;
        }
    }

    free(ht->array);
    free(ht);
}

hash_node_t *new_hash_node(const char *key, const char *value)
{
	hash_node_t *hash_node;

	hash_node = malloc(sizeof(hash_node_t));
	if (hash_node == NULL)
		return (NULL);

	hash_node->key = strdup(key);
	if (hash_node->key == NULL)
	{
		free(hash_node);
		return (NULL);
	}

	hash_node->value = strdup(value);
	if (hash_node->value == NULL)
	{
		free(hash_node->key);
		free(hash_node);
		return (NULL);
	}

	hash_node->next = NULL;

	return (hash_node);
}
