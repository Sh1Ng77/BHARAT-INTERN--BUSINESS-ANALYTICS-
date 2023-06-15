/*TASK [1]:
Forecasting the sales of a supermarket :
A supermarket has various departments, and it must stock up items that will be in demand in each of these departments.
However, while stocking up, it must make sure that it does not have excessive stock.
*/
/*This code represent the supermarket sales predication of years by takeing the user input data for the per departement
sales according to the avilable stock and how much want to order more in the market slotes,by using the simplicity in the 
code and easy to undrstand the format, the algorithm and comments(in code) also provide for better visulation. */

/*The algorithm for this code to understand and use it:
1} Create an array of Department structures to store department data.
2} user to enter the predicted sales data for each department and store it in data format.
3} Checks the Available stock levels for each department and order more items if necessary.
4} Display the sales data and stock levels for each department in the table format. */


/*CODE IN C++ FORMAT*/
#include <iostream>
#include <string>
using namespace std;

struct Department
{
  string name;
  int current_stock;
  int predicted_sales;
  int ordered_items;
};

int main()
// Create an slotes of 4 main department to justify 
 {
  const int kNumDepartments = 4;
  Department departments[kNumDepartments] =
  {
    {"Grocery", 100, 0, 0},
    {"Produce", 50, 0, 0},
    {"Meat", 75, 0, 0},
    {"Dairy", 80, 0, 0}
  };
 // Takeing sales data for the depetments "Grocery","Produce","Meat","Dairy"
  for (int i = 0; i < kNumDepartments; i++)
  {
    cout << "Enter sales data for " << departments[i].name << " department:\n";
    cout << "Predicted sales: ";
    cin >> departments[i].predicted_sales;
  }

  // Forecast future sales for each department
  // Display of available stock and how much to ordered 
  for (int i = 0; i < kNumDepartments; i++)
  {
    if (departments[i].predicted_sales > departments[i].current_stock)
    {
      departments[i].ordered_items = departments[i].predicted_sales - departments[i].current_stock;
    }
  }
  cout << "Department\tAvailable Stock\tPredicted Sales\tOrdered Items\n";

  // Display of data in table format and valulation of stock
  for (int i = 0; i < kNumDepartments; i++)
  {
    cout << departments[i].name << "\t\t";
    cout << departments[i].current_stock << "\t\t";
    cout << departments[i].predicted_sales << "\t\t";
    cout << departments[i].ordered_items << endl;
  }

  return 0;
}
