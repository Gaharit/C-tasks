#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 6
enum color_eyes
{
	green,
	blue,
	brown,
	grey,
	unknown_color,
};

char eyes_name[][10] = { "green","blue","brown","grey","unknown" };

enum Season
{
	winter,
	spring,
	summer,
	autumn,
	unknown_season
};

char season_name[][10] = { "winter","spring","summer","autumn","unknown" };

enum local {
	yes,
	no,
	unknown,
};

char local_name[][10] = { "yes","no","unknown" };

enum color_hair {
	light,
	dark,
	unknown_hair,
};

char hair_name[][10] = { "light","dark","unknown" };

typedef struct STUDENT
{
	char Name[20];
	char LastName[30];
	enum Season season;
	enum color_eyes eyes;
	enum color_hair hair;
	enum local from;
} Student;

Student group[] = {
	{ "Ivan", "Potapov", winter, grey, light, no },
	{ "Dinar", "Abdeev",winter,green,light, no },
	{ "Arina","Kopanova", autumn, brown, dark, no },
	{ "Vlad", "Solozhonkin", summer, blue, dark, no },
	{ "Alexey", "Onoshkin", summer, green, dark, no },
	{ "Nikita", "Paklin", summer, grey, light, no },
};

void show(Student *student)
{
	printf(" %s %s - %s %s %s %s \n", student->Name, student->LastName, season_name[student->season], eyes_name[student->eyes], hair_name[student->hair], local_name[student->from]);
}

int Search(Student* temp)
{
	int i, flag = 0;

	for (i = 0; i < SIZE; i++) {
		if (group[i].season == temp->season || temp->season == unknown_season)
			if (group[i].eyes == temp->eyes || temp->eyes == unknown_color)
				if (group[i].hair == temp->hair || temp->hair == unknown_hair)
					if (group[i].from == temp->from || temp->from == unknown)
					{
						show(group + i);
						++flag;
					}
	}

	return flag;
}
void main()
{
	struct STUDENT search_template = { "", "" };
	printf("When was he/she born?\n 0 - winter, 1 - spring, 2 - summer, 3 - autumn, 4 - unknown\n");
	scanf("%d", &search_template.season);

	printf("Eye color?\n 0 - green, 1 - blue, 2 - brown, 3 - grey, 4 - unknown\n");
	scanf("%d", &search_template.eyes);

	printf("Hair color?\n 0 - light, 1 - dark, 2 - unknown\n");
	scanf("%d", &search_template.hair);

	printf("Is he/she a local?\n 0 - yes, 1 - no, 2 - unknown\n");
	scanf("%d", &search_template.from);

	if (Search(&search_template) == 0)
	{
		printf("I can't find anyone\n");
	}
}





/*pStudent = group;
printf("%s %s %d\n", group[0].Name, group[0].LastName, group[0].season);
pStudent->season = spring;
strcpy(pStudent->Name, "Vasya");

printf("%s %s %d\n", (*pStudent).Name, pStudent->LastName, pStudent->season);
*/