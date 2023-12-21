#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: -1 if the function fails or filename is NULL,
 *         -1 if the file does not exist or the user lacks write permissions,
 *         otherwise 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[content_length])
			content_length++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	bytes_written = write(file_descriptor, text_content, content_length);

	if (file_descriptor == -1 || bytes_written == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}

