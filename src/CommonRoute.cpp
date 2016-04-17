/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit 
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any 
number of times.
Output :
Return a Common Route String which covers maxiumum Islands 

Example 1 : 
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ" 
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation : 
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs 
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before 
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB 
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost ) 
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

void test(char *hacklist, char *codelist, int *a, int i, int j)
{
	int count = 1, initial = i - 1, p, q,cost = 0;
	while (codelist[i] != '\0'&& codelist[j] != '\0' && hacklist[i] == codelist[j])
	{
		count++;
		i++;
		j++;
	}
	if (count != 1 && count > a[2])
	{
		
		
		a[0] = initial;
		a[1] = i;
		a[2] = count;
		for (p = initial; p <= i; p++)
			cost += hacklist[p] - 65;
		a[4] = cost;
	}
	else if (count != 1 && count == a[2])
	{
		int tempCost = 0;
		for (p = initial; p <= i; p++)
			tempCost += hacklist[p] - 65;
		
		if (tempCost < a[4])
		{
			a[0] = initial;
			a[1] = i;
			for (p = initial; p <= i; p++)
				cost += hacklist[p] - 65;
			a[4] = cost;
		}
		else if (tempCost == cost)
		{
			p = initial;
			q = a[0];
			while (p <= i)
			{
				if (hacklist[p++] < codelist[q++])
					break;
			}
			if (p > i)
			{
				a[0] = initial;
				a[1] = i;
						
			}
		}
	}


}
char * find_common_route(char * hacklist, char *codelist, int *cost){
	if (hacklist==NULL || codelist== NULL )
		return NULL;
	else
	{
		int *a,i,j=0,k=0;
		char *result;
	
			a = (int *)malloc(4 * sizeof(int));
			a[0] = a[1] = a[2] = a[4]=-1;
		i = 0;
		while (hacklist[i] != '\0')
		{
			while (codelist[j] != '\0')
			{
				if (hacklist[i] == codelist[j])
					test(hacklist, codelist, a, i + 1, j + 1);
				j++;
			}
			i++;
		}
		result = (char *)malloc((a[1] - a[0] + 2)*sizeof(char));
		*cost = a[4];
		for (i = a[0]; i <= a[i]; i++)
			result[i - a[0]] = hacklist[i];
		result[i] = '\0';
		return result;
	}
}

