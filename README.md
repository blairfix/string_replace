# string_replace

`string_replace` is an R function for finding and replacing strings. Unlike native R functions like `sub` and `gsub`, `string_replace` is fully vectorized, meaning all it's arguments accept vectors.


### Inputs

The `string_replace` function has three inputs:


* `pattern` = a vector of string patterns you wish to find 
* `replacement` =  a vector of replacement strings you wish to replace the original pattern with. The `replacement` vector must be the same length as the `pattern` vector
* `x` = the string vector in which you want to search/replace

Note: `string_replace` does not accept regular expressions.


### Output
`string_replace` returns the vector `x` with the appropriate substitutions. 


### Example

I use `string_replace` to manage my bibtex database. To keep proper nouns capitalized in bibtex, you wrap them in curly brackets. So we'd want the title "A History of the United States" 
to be stored in bibtex as "A History of the {United States}".

Here's example code that finds proper nouns and wraps them in brackets.


```R
library(Rcpp)
library(BH)

sourceCpp("string_replace.cpp")

proper_noun = c("United States", "Bob", "Paris")
proper_noun_bibtex = c("{United States}", "{Bob}", "{Paris}")

title = c("A History of the United States", 
      "This is Bob's Big Article",
      "April in Paris"
      )

string_replace(pattern = proper_noun,
               replacement = proper_noun_bibtex,
               x = title)

[1] "A History of the {United States}" "This is {Bob}'s Big Article"      "April in {Paris}"   

```



### Installation
To use `string_replace`, install the following R packages:
 * [Rcpp](https://cran.r-string_replace.org/web/packages/Rcpp/index.html) 
 * [BH](https://cran.r-project.org/web/packages/BH/index.html)

Put the source code (`string_replace.cpp`) in the directory of your R script. Then source it with the command `sourceCpp('string_replace.cpp')`.




