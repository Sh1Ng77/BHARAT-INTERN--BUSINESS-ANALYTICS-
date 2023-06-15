/*TASK [2]:
Success of an upcoming movie :
For this project, you need to predict the success upcoming movie so that whether or not a company should go for,
buying it based on ROL. To do this, you need to come up with a model and use the historical data of each*/

/*The algorithm for this code to understand and use it:
To create an algorithm for predicting the success of an upcoming movie, we need to follow these steps:
1} Collect historical data of movies, including their name, audience, and success rate.
2} Preprocess the data by cleaning and transforming it into a suitable format for machine learning.
3} Train a logistic regression model using the historical data.
4} Use the trained model to predict the success of the upcoming movie based on its name and current audience.
5} Output the predicted success rate of the movie, and the company can decide whether or not to buy it based on the predicted ROI.*/

/*Description:
The model using the ML algorithm for the predection of the upcoming movie success rate and the current auidence for the movie
it collect the prevoius movie data that are success and use them as a reference for the predection */




/*CODE IN C++ FORMAT*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

// Structure to represent a movie name
struct Movie
{
 string name;
 double audience;
 bool success;
};

// Function to train a Logistic Regression model for the predection
void trainLogisticRegression(const vector<Movie>& movies,map<string, double>& weights, double& bias,
int numIterations, double learningRate)
{
    // Initialize weights and bias
    for (const Movie& movie : movies)
    {
        weights[movie.name] = 0.0;
    }
    bias = 0.0;
    for (int iteration = 0; iteration < numIterations; iteration++)
    {
        double errorSum = 0.0;
        double biasGradient = 0.0;

        for (const Movie& movie : movies)
        {
            double prediction = 1.0 / (1.0 + exp(-1.0 * (weights[movie.name] * movie.audience + bias)));
            double error = movie.success - prediction;

            weights[movie.name] += learningRate * error * movie.audience;
            bias += learningRate * error;

            errorSum += error;
            biasGradient += error;
        }

        double meanError = errorSum / movies.size();
        double meanBiasGradient = biasGradient / movies.size();

        cout << "Iteration: " << iteration + 1 << ", Mean Error: " << meanError << endl;

        // Stop training if the mean error is below a certain threshold
        if (fabs(meanError) < 01)
        {
            break;
        }
    }
}

// For prediction the success rate of an upcoming movie
bool predictMovieSuccess(const map<string, double>& weights, double bias, const string& movieName, double audience)
{
    double prediction = 1.0 / (1.0 + exp(-1.0 * (weights.at(movieName) * audience + bias)));
    return prediction >= 0.5;
}

int main()
{
    // Historical movie data
    vector<Movie> movies =
    {
        { "Movie A", 50000, true },
        { "Movie B", 60000, true },
        { "Movie C", 70000, true },
        { "Movie D", 80000, false },
        // by giving proper order you can add multiple movie data
    };
    map<string, double> weights;
    double bias;
    int numIterations = 1000;
    double learningRate = 0001;
    trainLogisticRegression(movies, weights, bias, numIterations, learningRate);

    // Predict of upcoming movie is high or low
    string upcomingMovieName;
    double upcomingMovieAudience;
    cout << "Enter the name of the upcoming movie: ";
    cin >> upcomingMovieName;
    cout << "Enter the current audience of the upcoming movie: ";
    cin >> upcomingMovieAudience;

    bool isSuccessful = predictMovieSuccess(weights, bias, upcomingMovieName, upcomingMovieAudience);
    cout << "Predicted success of the upcoming movie: " << (isSuccessful ? "Yes" : "No") << endl;

    return 0;
}
