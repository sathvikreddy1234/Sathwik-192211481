#include <stdio.h>

#define MAX_PARTITIONS 5

void worst_fit(int partitions[], int num_partitions, int processes[], int num_processes) 

{

    int i, j;

    int allocated[MAX_PARTITIONS];

    for (i = 0; i < num_processes; i++)

        allocated[i] = -1;

    for (i = 0; i < num_processes; i++) 

    {

        int worst_fit_index = -1;

        int worst_fit_size = -1;

        for (j = 0; j < num_partitions; j++) 

        {

            if (partitions[j] >= processes[i] && partitions[j] > worst_fit_size) 

            {

                worst_fit_index = j;

                worst_fit_size = partitions[j];

            }

        }

        if (worst_fit_index != -1) 

        {

            allocated[i] = worst_fit_index;

            partitions[worst_fit_index] -= processes[i];

        }

    }

    printf("Process\tProcess Size\tPartition\n");

    for (i = 0; i < num_processes; i++) {

        printf("%d\t%d KB\t\t", i+1, processes[i]);

        if (allocated[i] != -1)

            printf("%d\n", allocated[i] + 1);

        else

            printf("Not Allocated\n");

    }

}

int main() 

{

    int partitions[] = {40, 10, 30, 60};

    int processes[] = {100, 50, 30, 120, 35};

    int num_partitions = sizeof(partitions) / sizeof(partitions[0]);

    int num_processes = sizeof(processes) / sizeof(processes[0]);

    worst_fit(partitions, num_partitions, processes, num_processes);

    return 0;

}
