#include <iostream>
#include <vector>
#include <cmath>

class LinearRegression {
private:
    double slope;
    double intercept;

public:
    LinearRegression() : slope(0), intercept(0) {}

    void train(const std::vector<double>& x, const std::vector<double>& y) {
        double x_mean = mean(x);
        double y_mean = mean(y);
        double numerator = 0;
        double denominator = 0;

        for (size_t i = 0; i < x.size(); ++i) {
            numerator += (x[i] - x_mean) * (y[i] - y_mean);
            denominator += std::pow((x[i] - x_mean), 2);
        }

        slope = numerator / denominator;
        intercept = y_mean - (slope * x_mean);
    }

    double predict(double x) const {
        return slope * x + intercept;
    }

    double mean(const std::vector<double>& v) const {
        double sum = 0;
        for (double val : v) {
            sum += val;
        }
        return sum / v.size();
    }
};

int main() {
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 5, 4, 5};

    LinearRegression model;
    model.train(x, y);

    std::cout << "Predicted value for x = 6: " << model.predict(6) << std::endl;

    return 0;
}
