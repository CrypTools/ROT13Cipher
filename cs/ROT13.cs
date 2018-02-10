/****************************************************/
//
//          Usage: ROT13.Use(String);
//
/****************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class ROT13
{
    private readonly static char[] charSet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    public static string encrypt(string input)
    {
        input = input.ToUpper();

        foreach(char c in input)
            if (!charSet.Contains(c))
                return null;

        string output = "";

        foreach(char c in input)
        {
            int newPos = (charSet.ToList().IndexOf(c) + 13) % 26;
            output += charSet[newPos];
        }

        return output;
    }
}
