class ProductOfNumbers {
public:
    vector<int> res;

    ProductOfNumbers() {
        res.clear(); 
    }

    void add(int num) {
        res.push_back(num); 
    }

    int getProduct(int k) {
        if (k > res.size())
            return 0;
        int product = 1;
        for (int i = res.size() - k; i < res.size(); i++) {
            product *= res[i];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */