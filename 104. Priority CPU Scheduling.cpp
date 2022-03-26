// Problem: https://www.codingninjas.com/codestudio/guided-paths/operating-system-track/content/119091/offering/1404629

/*
    Time Complexity : O(N * log(N))
    Space Complexity : O(N)
    
    where 'N' is the number of processes.  
*/

#include <algorithm>

/*
    Sort according to arrival time.
    If arrival time is same, check priority.
    If priority is same, check process number.
*/
bool compare(vector < int > & firstProcess, vector < int > & secondProcess) {

    // If arrival time is same of both processes.
    if (firstProcess[1] == secondProcess[1]) {

        // If priority of processes is same.
        if (firstProcess[3] == secondProcess[3]) {

            // Sort according to process number.
            return firstProcess[0] < secondProcess[0];
        }

        // Otherwise sort according to priority.
        else {
            return firstProcess[3] > secondProcess[3];
        }
    }

    // Otherwise sort according to arrival time.
    else {
        return firstProcess[1] < secondProcess[1];
    }
}

// Function to find order of scheduled process.
vector < int > findOrder(vector < vector < int >> & processDetails) {
    int n = processDetails.size();

    vector < int > order;

    for (int i = 0; i < n; i++) {
        order.push_back(processDetails[i][0]);
    }

    return order;
}

// Function to find waiting time.
vector < int > findWaitingTime(vector < vector < int >> & processDetails) {

    int n = processDetails.size();

    // Initialize array to store start and wait time of each process.
    vector < int > startTime(n);
    vector < int > waitTime(n);

    // Start and time of first process.
    startTime[0] = (processDetails[0][1]);
    waitTime[0] = 0;

    // Waiting time of a process is difference of its start time and arrival time.
    for (int i = 1; i < n; i++) {
        startTime[i] = startTime[i - 1] + processDetails[i - 1][2];
        waitTime[i] = startTime[i] - processDetails[i][1];

        // If waiting time is less than 0.
        if (waitTime[i] < 0) {
            waitTime[i] = 0;
        }
    }

    return waitTime;
}

// Function to find turnaround time.
vector < int > findTurnTime(vector < vector < int >> & processDetails, vector < int > & waitTime) {
    int n = processDetails.size();

    vector < int > turnTime(n);

    // Turnaround time is addition of waiting and burst time.
    for (int i = 0; i < n; i++) {
        turnTime[i] = waitTime[i] + processDetails[i][2];
    }

    return turnTime;
}

vector < vector < int >> priorityScheduling(vector < int > & arrivalTime, 
    vector < int > & burstTime, vector < int > & priority) {

    // Variable to store number of processes.
    int n = arrivalTime.size();

    // Initializing array to store details of processes.
    vector < vector < int >> processDetails(n, vector < int > (4));

    for (int i = 0; i < n; i++) {

        // Inserting all details of 'i-th' process.
        processDetails[i][0] = i + 1;
        processDetails[i][1] = arrivalTime[i];
        processDetails[i][2] = burstTime[i];
        processDetails[i][3] = priority[i];
    }

    // Sort processes.
    sort(processDetails.begin(), processDetails.end(), compare);

    // Array to store result.
    vector < vector < int >> res;

    // Finding order.
    vector < int > order = findOrder(processDetails);
    res.push_back(order);

    // Finding waiting time of each process.
    vector < int > waitTime = findWaitingTime(processDetails);
    res.push_back(waitTime);

    // Finding turnaround time of each process.
    vector < int > turnTime = findTurnTime(processDetails, waitTime);
    res.push_back(turnTime);

    return res;
}
