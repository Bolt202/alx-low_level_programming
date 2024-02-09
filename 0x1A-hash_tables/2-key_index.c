#include "hash_tables.h"

/**
 * key_index - Retrieve the index for storing a key/value
 *      pair in the array of a hash table.
 * @key: The key for which to determine the index.
 * @size: The size of the array of the hash table.
 *
 * Return: The index corresponding to the key.
 * Description: Implements the djb2 hashing algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    return (hash_djb2(key) % size);
}
