int main()
{
    int i = 3;
    if (i == 0) {
        if (i < 1) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        if (i == 1) {
            return 1;
        }
        else {
            if (i == 2) {
                return 2;
            }
            else {
                if (i == 3) {
                    return 3;
                }
                else {
                    if (i == 4) {
                        return 4;
                    }
                    else {
                        return 5;
                    }
                }
            }
        }
    }
    return i;
}