class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // 1. Meetings ko unke start time ke basis par sort karein
        sort(meetings.begin(), meetings.end());

        // Room usage count track karne ke liye array
        vector<int> roomCount(n, 0);

        // Min-heap khali rooms ke liye: holds room_number
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        // Min-heap chal rahi meetings ke liye: holds pair<end_time,
        // room_number> Pair use karne se jo meeting pehle khatam hogi wo top
        // par aayegi
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busyRooms;

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            // Jo meetings is current meeting ke start hone se pehle khatam ho
            // chuki hain, unke rooms ko freeRooms heap mein daal dein
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            // CASE 1: Agar koi room free available hai
            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();

                roomCount[room]++;
                busyRooms.push(
                    {end,
                     room}); // Ye meeting schedule end time par khatam hogi
            }
            // CASE 2: Agar koi room free nahi hai (Meeting delay hogi)
            else {
                // Jo room sabse pehle free hone wala hai use pick karein
                auto top = busyRooms.top();
                busyRooms.pop();

                long long earliestFreeTime = top.first;
                int room = top.second;

                roomCount[room]++;
                // Naya end time = jab room free hua + meeting ki actual
                // duration
                busyRooms.push({earliestFreeTime + duration, room});
            }
        }

        // Sabse zyada use hone wala room dhundein
        int ansRoom = 0;
        for (int i = 1; i < n; i++) {
            if (roomCount[i] > roomCount[ansRoom]) {
                ansRoom = i;
            }
        }

        return ansRoom;
    }
};