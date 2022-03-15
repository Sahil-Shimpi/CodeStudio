// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382162

/*
    Time complexity: O(1)
    Space complexity: O(1)

    We are using constant time and space. 
*/

bool isValidIPv4(string ipAddress) {
    int dots = 0;            // To store total number of dots
    int currentNumber = -1;  // Integer form of every single part

    for (int i = 0; i < ipAddress.size(); i++) {
        // If current character is '.' then check 'currentNumber' is valid or not.
        if (ipAddress[i] == '.') {
            // If 'currentNumer' is valid then its must be, from '0' to '255'
            if (currentNumber < 0 or currentNumber > 255) {
                return false;
            }

            currentNumber = -1;
            dots += 1;
        } else {
            // First check given character is valid number or not.
            if (!isdigit(ipAddress[i])) {
                return false;
            }
            if (currentNumber == -1) {
                currentNumber = ipAddress[i] - '0';
            } else {
                currentNumber = currentNumber * 10 + (ipAddress[i] - '0');
            }
            /*
                If any substring is '00' then it can't be valid.
                According to 'currentNumber' it is '0' and valid, so we need to check it extra.

            */
            if (i > 0) {
                if (ipAddress[i - 1] == '0') {
                    if (i > 1) {
                        if (!isdigit(ipAddress[i - 2]) || ipAddress[i -2] == '0') {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
            }
        }
    }
    // If number of dots are '3' and every part is valid only then return 'True'
    if (currentNumber < 0 or currentNumber > 255 or dots != 3) {
        return false;
    }
    return true;
}
