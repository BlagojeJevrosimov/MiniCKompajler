//OPIS: dve globalne promenljive
//RETURN: 202

int x;
int y;

int f1(int a) {
    x = a;
    return x;
}

int f2(int h) {
    y = h + x;
    return y;
}

int main() {
  int g;
  int b;
  g = f1(42);
  b = f2(17);
  return g + b + x + y;
}

