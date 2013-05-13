/*
// lcs.h
// Copyright (C) Aliaksei Plashchanski
*/

#include <string>
#include <vector>

#ifndef CPPALGO_LCS_H
#define CPPALGO_LCS_H

/*
// Find the length of the longest common subsequence
// of sequences x and y.
// Complexity: O(x.length() * y.length())
// Memory: O(x.length() * y.length())
*/
std::size_t lcs_length(const std::string& x, const std::string& y)
{
    std::size_t m = x.length(), n = y.length();
    std::vector<std::vector<std::size_t> > c(m + 1, std::vector<std::size_t>(n + 1, 0));

    for (std::size_t i = 1; i <= m; ++i)
    {
        for (std::size_t j = 1; j <= n; ++j)
        {
            if (x[i-1] == y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else if (c[i-1][j] >= c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
        }
    }

    return c[m][n];
}

#endif