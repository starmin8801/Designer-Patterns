#ifndef NEW_H
#define NEW_H

void *New(const void *_class, ...);
void Delete(void *_class);
void SetJanpa(void *_self, void *_Janpa);
void SetChina(void *_self, void *_China);
void SetMediator(void *_country, void *_mediator);
void SendMessage(void *_country, char *_message);

#endif
