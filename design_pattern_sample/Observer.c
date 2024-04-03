#define MAX_OBSERVERS    10

typedef struct 
{
	void (*update)(void* observer);
}Observer;

typedef struct 
{
	Observer* observer[MAX_OBSERVERS];
	uint8_t counts;
	void (*attach)(void* subject, Observer* observer);
	void (*detach)(void* subject, Observer* observer);
	void (*notify)(void* subject);
}Subject;

void attach(void* subject, Observer* observer) 
{
    Subject* s = (Subject*)subject;
    if (s->count < MAX_OBSERVERS) 
	{
        s->observers[s->count++] = observer;
    }
}

void detach(void* subject, Observer* observer) {
    Subject* s = (Subject*)subject;
    for (int i = 0; i < s->count; ++i) 
	{
        if (s->observers[i] == observer) 
		{
            for (int j = i; j < s->count - 1; ++j) {
                s->observers[j] = s->observers[j + 1];
            }
            s->count--;
            break;
        }
    }
}

void notify(void* subject) 
{
    Subject* s = (Subject*)subject;
    for (int i = 0; i < s->count; ++i) 
	{
        s->observers[i]->update(s->observers[i]);
    }
}



