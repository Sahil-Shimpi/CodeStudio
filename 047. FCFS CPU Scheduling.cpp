// Problem: https://www.codingninjas.com/codestudio/guided-paths/operating-system-track/content/119091/offering/1404612

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the number of processes.
*/

// This function is used to find the waiting time of each process.
void findWaitingTime(int n, vector < int > & burstTime, vector < int > & waitingTime) {
    // The Waiting time of the first process is 0.
    waitingTime[0] = 0;

    // Fill the waiting time of the remaining processes.
    for (int i = 1; i < n; i++) {
        /*
            The waiting time of a process is equal to the sum of the
            waiting time and burst time of the previous process.
        */
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
    }

}

// This function is used to find the turn around time of each process.
void findTurnAroundTime(int n, vector < int > & burstTime, vector < int > & waitingTime,
    vector < int > & turnAroundTime) {

    // Turn around time is the summation of the waiting time and the burst time.
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }

}

vector < vector < int >> findScheduling(int n, vector < int > & burstTime) {
    // Create two new vectors for the Waiting time and the Trun Around time of each process.
    vector < int > waitingTime(n), turnAroundTime(n);

    // Find the waiting time.
    findWaitingTime(n, burstTime, waitingTime);
    
    // Find the turn around time.
    findTurnAroundTime(n, burstTime, waitingTime, turnAroundTime);

    vector < vector < int >> result;
    result.push_back(waitingTime);
    result.push_back(turnAroundTime);
    return result;
}
