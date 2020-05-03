#pragma once

// TODO: move into string util file
char* clone_string(const char* src);

// returned string doesnt get free'd
char* concat_string(const char* str1, const char* str2);

// Requires: string to by dynamically allocated from global Allocator
void free_string(char* str);