#include<stdio.h>

typedef struct activity_selection
{
    int Activity_Number;
    int Starting_Time;
    int Finishing_Time;

}Activities;

Activities InputActivities(int slNo, int starting_time, int ending_time){
    Activities activity;
    activity.Activity_Number = slNo;
    activity.Starting_Time = starting_time;
    activity.Finishing_Time = ending_time;
    return activity;
}

Activities SortFinTime(Activities activity[], int Numbers_of_activity){
    int i, j;
    for (i = 0; i < Numbers_of_activity - 1; i++){
        for (j = 0; j < Numbers_of_activity - i - 1; j++){
            if (activity[j].Finishing_Time > activity[j + 1].Finishing_Time){
                int temp = activity[j].Finishing_Time;
                activity[j].Finishing_Time = activity[j+1].Finishing_Time;
                activity[j+1].Finishing_Time = temp;

                temp = activity[j].Starting_Time;
                activity[j].Starting_Time = activity[j+1].Starting_Time;
                activity[j+1].Starting_Time = temp;

                temp = activity[j].Activity_Number;
                activity[j].Activity_Number = activity[j+1].Activity_Number;
                activity[j+1].Activity_Number = temp;
            }
        }
    }
    
    return *activity;
}


void Selection(Activities activity[], int Numbers_of_activity){


    int temp = activity[0].Finishing_Time;
    printf("A%d ", activity[0].Activity_Number);
    for (int i = 0; i < Numbers_of_activity-1; i++)
    {
        if (temp<=activity[i+1].Starting_Time)
        {
            temp = activity[i+1].Finishing_Time;
            printf("A%d ", activity[i+1].Activity_Number);
            // printf("%d\n",temp);
        }
        // else{
        //     // activitySlNo[i][j] = 0;
        //     // temp = activity[i].Finishing_Time;
        //     // printf("%d\n",temp);
        //     continue;
        // }

    }
    
}


int main(){
    int Number_of_Activities;
    // int Activities_Of_each_Position[Number_of_Activities][Number_of_Activities];
    // int *pointer = &Activities_Of_each_Position;
    // int Max_Activities[Number_of_Activities];

    printf("number of activities: ");
    scanf("%d", &Number_of_Activities);

    Activities Activity[Number_of_Activities];

    for (int i = 0; i < Number_of_Activities; i++)
    {
        int Str_time, End_time;
        printf("Starting Time of the activity: ");
        scanf("%d", &Str_time);
        printf("Ending Time of the activity: ");
        scanf("%d", &End_time);
        Activity[i] = InputActivities(i+1, Str_time, End_time);
    }

    *Activity = SortFinTime(Activity, Number_of_Activities);

    Selection(Activity, Number_of_Activities);

    printf("\n");

    // for (int i = 0; i < Number_of_Activities; i++)
    // {
    //     printf("A%d ", Activity[i].Activity_Number);
    // }
    
    return 0;
}