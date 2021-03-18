typedef struct map
{
	unsigned int LinkID;
	int flag;
	int branch;
	int roadclass;
	char name[22];
	struct map *next;
}MAP,*MAPLINK;