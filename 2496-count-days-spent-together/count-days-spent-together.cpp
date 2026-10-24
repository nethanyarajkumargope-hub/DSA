
class Solution {
private:
    const vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dateToDayOfYear(const string& date) {
        int month = (date[0] - '0') * 10 + (date[1] - '0');
        int day = (date[3] - '0') * 10 + (date[4] - '0');
        
        int dayCount = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayCount += months[i];
        }
        return dayCount + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice = dateToDayOfYear(arriveAlice);
        int endAlice = dateToDayOfYear(leaveAlice);
        int startBob = dateToDayOfYear(arriveBob);
        int endBob = dateToDayOfYear(leaveBob);
        int overlapStart = max(startAlice, startBob);
        int overlapEnd = min(endAlice, endBob);
        return max(0, overlapEnd - overlapStart + 1);
    }
};
