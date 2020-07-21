#include <stdlib.h>

int* climbingLeaderboard(int scores_count, int* scores, int alice_count, int* alice)
{
	int *alice_position = NULL;
	int i, j, tmp = 0, pos_result = alice_count - 1, count_rank = 1;

	alice_position = malloc(sizeof(int) * alice_count);

	for (j = alice_count - 1; j >= 0; j--)
	{
		while (scores[i] && scores[i] > alice[j])
		{
			i++;
			if (scores[i] < scores[i - 1])
				count_rank++;
		}
		alice_position[pos_result] = count_rank;
		pos_result--;
	}

	return (alice_position);
}

int main()
{
	int size_array_scores, size_array_alice, i;
	int score_number, alice_number;
	int *scores = NULL, *alice = NULL, *result_array = NULL;

	scanf("%d", &size_array_scores);
	scores = malloc(sizeof(int) * size_array_scores);

	for (i = 0; i < size_array_scores; i++)
	{
		scanf("%d", &score_number);
		scores[i] = score_number;
	}

	scanf("%d", &size_array_alice);
	alice = malloc(sizeof(int) * size_array_alice);

	for (i = 0; i < size_array_alice; i++)
	{
		scanf("%d", &alice_number);
		alice[i] = alice_number;
	}

	result_array = climbingLeaderboard(size_array_scores, scores, size_array_alice, alice);

	for (i = 0; i < size_array_alice; i++)
		printf("%d\n", result_array[i]);

	free(scores);
	free(alice);
	free(result_array);
}
