#include <MK/Core/File.h>

char*mk_getFileContents(const char* filePath)
{
  FILE* file = fopen(filePath, "r");
  if (file == NULL)
  {
    fprintf(stderr, "Failed to open file (%s)!\n", filePath);
    return "";
  }

  int fileLength = 0;
  fseek(file, 0, SEEK_END);
  fileLength = ftell(file);
  rewind(file);

  char* buffer = (char*)malloc((fileLength + 1) * sizeof(char));
  if (buffer == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for file (%s)!\n", filePath);
    free(buffer);
    fclose(file);
    return "";
  }

  size_t readSize = fread(buffer, 1, fileLength, file);
  if (readSize != fileLength)
  {
    fprintf(stderr, "Failed to read contents of file (%s)!\n", filePath);
    free(buffer);
    fclose(file);
    return "";
  }

  buffer[fileLength] = '\0';
  fclose(file);
  return buffer;
}
