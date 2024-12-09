
int modExpo(int base, int exp, int mod) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (1LL * res * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return res;
}
