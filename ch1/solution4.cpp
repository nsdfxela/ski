#include <iostream>
#include <fstream>
#include <string>
int read_data(int &s, int &n, std::istream &st) {
  st >> s;
  st >> n;
  return s;
}

#define H (2*s+3)
#define W (s+2)

#define VSX (W-1)
#define LVSX (0)

void v1(char *f, int s) {
  int xspos = VSX;//x start pos
  int yspos = 1;//y start pos
  for(int i=yspos;i<s+yspos;i++){ f[i*W + xspos] = '|';}
}

void v2(char *f, int s) {
  int xspos = VSX;//x start pos
  int yspos = 1+s+1;//y start pos
  for(int i=yspos;i<s+yspos;i++){ f[i*W + xspos] = '|';}
}

void lv1(char *f, int s) {
  int xspos = LVSX;//x start pos
  int yspos = 1;//y start pos
  for(int i=yspos;i<s+yspos;i++){ f[i*W + xspos] = '|';}
}

void lv2(char *f, int s) {
  int xspos = LVSX;//x start pos
  int yspos = 1+s+1;//y start pos
  for(int i=yspos;i<s+yspos;i++){ f[i*W + xspos] = '|';}
}


void h1(char *f, int s) {
  int xspos = 1;//x start pos
  int yspos = 0;//y start pos
  for(int i=0;i<s;i++){ f[yspos*W + xspos+i] = '_';}
}
void h2(char *f, int s) {
  int xspos = 1;//x start pos
  int yspos = 0+s+1;//y start pos
  for(int i=0;i<s;i++){ f[yspos*W + xspos+i] = '_';}
}
void h3(char *f, int s) {
  int xspos = 1;//x start pos
  int yspos = 0+s+1+s+1;//y start pos
  for(int i=0;i<s;i++){ f[yspos*W + xspos+i] = '_';}
}


void print_field(char *data, int s) {
  for(int i = 0;i<H;i++){
    for(int j = 0;j<W;j++){
      std::cout << data[i*W+j];
    }
    std::cout << std::endl;
  }

}

void print1(char * field, int s) {
  v1(field, s);
  v2(field, s);
}

void print2(char * field, int s) {
  h1(field, s);
  v1(field, s);
  h2(field, s);
  h3(field, s);
  lv2(field, s);
}

void print3(char * field, int s) {
  h1(field, s);
  v1(field, s);
  h2(field, s);
  h3(field, s);
  v2(field, s);
}

void print4(char * field, int s) {
  v1(field, s);
  h2(field, s);
  v2(field, s);
  lv1(field, s);
}

void print5(char * field, int s) {
  h1(field, s);
  lv1(field, s);
  h2(field, s);
  v2(field, s);
  h3(field, s);
}

void print6(char * field, int s) {
  h1(field, s);
  lv1(field, s);
  h2(field, s);
  v2(field, s);
  h3(field, s);
  lv2(field, s);
}

void print7(char * field, int s) {
  v1(field, s);
  v2(field, s);
  h1(field, s);
}

void print8(char * field, int s) {
  h1(field, s);
  lv1(field, s);
  h2(field, s);
  v2(field, s);
  h3(field, s);
  lv2(field, s);
  v1(field, s);
}

void print9(char * field, int s) {
  h1(field, s);
  lv1(field, s);
  h2(field, s);
  v2(field, s);
  h3(field, s);
  v1(field, s);
}



void print_data(const std::string &data, int s) {
  for(int i = 0; i < data.size(); i++) {
    //    std::cout << data[i];
    if(data[i] == '1') {
      s=5;
      char *field = new char[H*W];
      memset(field, '.', H*W);
      print9(field, s);
      print_field(field, s);
    }
    
  }
}

int main (void) {
  int s = 0, n = 0;
  std::ifstream fstr ("test.txt", std::ios::in);
  while(read_data(s, n, fstr)){
    //    std::cout << s << std::endl;
    std::string strn = std::to_string(n);
    print_data(strn, s);
  }
  return 0;
}
