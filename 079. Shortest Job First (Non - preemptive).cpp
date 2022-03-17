// Problem: https://www.codingninjas.com/codestudio/guided-paths/operating-system-track/content/119091/offering/1404616

/*
    Time Complexity  : O(N ^ 2)
    Space Complexity : O(N)

	Where 'N' denotes the number of processes.
*/

#include <algorithm>

/*
	This comparator funtion is used to sort 'processDetails' in increasing order of arrival time.
	If arrival time is the same, sort it in increasing order of burst time. If both arrival time and
	burst time are the same, sort it in increasing process id.
*/
bool comp (const vector<int> &process1, const vector<int> &process2) {

	// If arrival time of 'process1' is not equal to the arrival time of 'process2'.
	if (process1[1] != process2[1]) {

		// Sort it in increasing order of arrival time.
		return process1[1] < process2[1];
	}

	// Else if burst time of 'process1' is not equal to the burst time of 'process2'.
	else if (process1[2] != process2[2]) {

		// Sort it in increasing order of burst time.
		return process1[2] < process2[2];
	}

	// Else sort it in increasing order of process id.
	else {
		return process1[0] < process2[0];
	}
}

vector<vector<int>> shortestJobFirst(int n, vector<int> &processId, 
	vector<int> &arrivalTime, vector<int> &burstTime) {

	/*
		To store the process id, arrival time, burst time, completion time, 
		waiting time, and turnaround time, respectively, for each process.
	*/
	vector<vector<int>> processDetails(n, vector<int>(6));

	// Run a loop for 'i' from 0 to 'N' - 1.
	for (int i = 0; i < n; i++) {

		// Insert 'processId', 'arrivalTime', and 'burstTime' of the i-th process into 'processDetails'.
		processDetails[i][0] = processId[i];
		processDetails[i][1] = arrivalTime[i];
		processDetails[i][2] = burstTime[i];
	}

	/*
		Sort 'processDetails' in increasing order of arrival time. If arrival time is the same,
		sort it in increasing order of burst time. If both arrival time and burst time are the same,
		sort it in increasing process id.
	*/
	sort(processDetails.begin(), processDetails.end(), comp);

	// Assign completion time, turnaround time, and waiting time for the first process in 'processDetails'.
	processDetails[0][3] = processDetails[0][1] + processDetails[0][2];
	processDetails[0][5] = processDetails[0][3] - processDetails[0][1];
	processDetails[0][4] = processDetails[0][5] - processDetails[0][2];

	// Run a loop for 'i' from 1 to 'N' - 1.
	for (int i = 1; i < n; i++) {

		// To store the completion time of the previous process.
		int prevCompTime = processDetails[i - 1][3];

		/*
			To store the minimum burst time of any process whose arrival time 
			is less than or equal to 'prevCompTime'.
		*/
		int currBurstTime = processDetails[i][2];

		/* 
			To store the process id of any process whose arrival time is less than 
			or equal to 'prevCompTime' and has minimum burst time and process id.
		*/
		int currId = processDetails[i][0];

		// To store the index of the process with minimum burst time.
		int index = i;

		// Run a loop for 'j' from 'i' to 'N' - 1.
		for (int j = i; j < n; j++) {

			// If the arrival time of j-th process if less than or equal to (i-1)-th process.
			if (processDetails[j][1] <= prevCompTime) {

				// Take the process with minimum burst time.
				if (processDetails[j][2] < currBurstTime) {
					currBurstTime = processDetails[j][2];
					currId = processDetails[j][0];
					index = j;
				}

				// If burst time is same, take the process with minimum process id.
				else if (processDetails[j][2] == currBurstTime && processDetails[j][0] < currId) {
					currId = processDetails[j][0];
					index = j;
				}
			}
		}

		/*
			Assign completion time, turnaround time, and waiting time for the process 
			in 'processDetails' at 'index'.
		*/
		processDetails[index][3] = prevCompTime + processDetails[index][2];

		// Since waiting time and turnaround time cannot be negative, we will take max of it with 0.
		processDetails[index][5] = max(processDetails[index][3] - processDetails[index][1], 0);
		processDetails[index][4] = max(processDetails[index][5] - processDetails[index][2], 0);
		swap(processDetails[index], processDetails[i]);
	}

	/*
		To store the process id, arrival time, burst time, waiting time, 
		and turnaround time, respectively, for each process.
	*/
	vector<vector<int>> answer(n, vector<int>(5));

	// Run a loop for 'i' from 0 to 'N' - 1.
	for (int i = 0; i < n; i++) {

		/*
			Insert 'processDetails[i][0]', 'processDetails[i][1]', 'processDetails[i][2]', 
			'processDetails[i][4]', and 'processDetails[i][5]' into 'answer', as we don't 
			need to return completion time of any process.
		*/
		int index = 0;
		for (int j = 0; j < 6; j++) {
			if (j != 3) {
				answer[i][index] = processDetails[i][j];
				index++;
			}
		}
	}

	return answer;
}
