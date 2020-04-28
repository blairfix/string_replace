#include <Rcpp.h>
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string/replace.hpp>


using namespace Rcpp;


// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

std::vector<std::string> string_replace (   std::vector<std::string> pattern,
                        					std::vector<std::string> replacement,
                        					std::vector<std::string> x
                    )
{

    // input string size
    int n_input = x.size();

    // output string
    std::vector<std::string> return_string(n_input);

    // replacement string size
    int n_replace = replacement.size();
    int n_pattern = pattern.size();

    if( n_pattern != n_replace){

        std::cout << "pattern and replacement vectors not the same size!";

    } else{

        #pragma omp parallel for firstprivate(x, pattern, replacement)
        for(int input_iterator = 0; input_iterator < n_input; input_iterator++){

            std::string new_string = x[input_iterator];


            // loop over replacement string
            for(int replace_iterator = 0; replace_iterator < n_pattern; replace_iterator++){

                std::string temp_pattern = pattern[replace_iterator];
                std::string temp_replace = replacement[replace_iterator];

                // replace in place
                boost::replace_all(new_string, temp_pattern, temp_replace);

            }

            return_string[input_iterator] = new_string;
        }

    }


return(return_string);

}

