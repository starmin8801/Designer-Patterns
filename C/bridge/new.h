#ifndef NEW_H
#define NEW_H

void *New(const void *_class, ...);
void Delete(void *_class);
void InstallOS(const void *_computer, const void *_os);

#endif
