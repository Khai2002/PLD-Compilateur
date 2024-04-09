int doubleValue(int x) {
    return 2 * x;
}

int square(int x) {
    return x * x;
}

int main() {
    int result = doubleValue(square(3));
    return result;
}