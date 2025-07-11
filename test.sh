assert() {
    expected="$1"
    input="$2"

    ./cc_sakura2 "$input" > tmp.s
    cc -o tmp tmp.s
    ./tmp

	actual="$?"

    ESC=$(printf '\033')
    if [ "$actual" = "$expected" ]; then
        echo "$input ${ESC}[32;1m=> $actual${ESC}[m"
    else
        echo "$input ${ESC}[31;1m=> $expected expected, but got $actual${ESC}[m"
        exit 1
    fi
}

assert 0 0
assert 42 42
assert 21 "5+20-4"

echo OK
