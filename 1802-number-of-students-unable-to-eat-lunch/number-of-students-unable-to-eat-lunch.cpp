class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();

        for(int i=0; i<n; ++i){
            if(students[i]==sandwiches[0]){
                students.erase(students.begin()+i);
                sandwiches.erase(sandwiches.begin());
                return countStudents(students, sandwiches);
            }
            
        }
        return students.size();
    }
};