#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char data;
	struct Node *next;

}my_struct;

char* readline();
void evaluator(char *s);
void push(my_struct **head, char c);
void pop(my_struct **head);
int check_pair (char s2, char s1);
void free_list(my_struct **head);

void push(my_struct **head, char c)
{
	my_struct *new_node = NULL;

	new_node = malloc(sizeof(my_struct));
	new_node->data = c;
	new_node->next = NULL;

	if(*head == NULL)
	{
		*head = new_node;
		return;
	}

	new_node->next = *head;
	*head = new_node;
}

void pop(my_struct **head)
{
	my_struct *tmp = *head;

	if (*head == NULL)
		return;

	*head = (*head)->next;

	free(tmp);
}

int check_pair(char s2, char s1)
{
	if (s2 == ')' && (s2 - 1) == s1)
		return (1);
	else if ((s2 - 2) == s1)
		return (1);
	else
		return (0);
}

void evaluator(char *s)
{
	my_struct *head = NULL;
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
			push(&head, s[i]);
		else if (s[i] == '}' || s[i] == ']' || s[i] == ')')
		{
			if (head == NULL || check_pair(s[i], head->data) == 0)
			{
				printf("NO\n");
				free_list(&head);
				return;
			}
			pop(&head);
		}
	}
	if (head != NULL)
	{
		printf("NO\n");
		free_list(&head);
		return;
	}
	printf("YES\n");
	free_list(&head);
}

void free_list(my_struct **head)
{
	while (*head)
	{
		pop(head);
	}
}

int main()
{
	int number_lines = 0;
	char *brackets;
	int i;

	scanf("%d", &number_lines);

	for (i = 0; i < number_lines; i++)
	{
		brackets = malloc(sizeof(char) * 1000);
		scanf("%s", brackets);
		evaluator(brackets);
		free(brackets);
	}
}
