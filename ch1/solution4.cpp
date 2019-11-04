#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int read_data(int &s, std::string &n, std::istream &st) {
  st >> s;
  st >> n;
  return s;
}

#define H (2*s+3)
#define W (s+2)

#define VSX (W-1)
#define LVSX (0)

#define DELIM ' '
#define HOR '-'

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
  for(int i=0;i<s;i++){ f[yspos*W + xspos+i] = HOR;}
}
void h2(char *f, int s) {
  int xspos = 1;//x start pos
  int yspos = 0+s+1;//y start pos
  for(int i=0;i<s;i++){ f[yspos*W + xspos+i] = HOR;}
}
void h3(char *f, int s) {
  int xspos = 1;//x start pos
  int yspos = 0+s+1+s+1;//y start pos
  for(int i=0;i<s;i++){ f[yspos*W + xspos+i] = HOR;}
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

void print0(char * field, int s) {
  h1(field, s);
  lv1(field, s);
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

void print_field(char *data, int w, int h) {
  for(int i = 0;i<h;i++){
    for(int j = 0;j<w;j++){
      std::cout << data[i*w+j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void print_data(const std::string &data, int s) {
  int field_size = H*(W+1)*data.size();
  char **fields = new char*[data.size()];
  //  memset(field, '.', field_size);
  char *current_field = nullptr;
  for(int i = 0; i < data.size(); i++) {
    //    current_field = &field[i*H*(W+1)];
    fields[i] = new char[H*(W)];
    current_field = fields[i];
    std::memset(current_field, DELIM, H*(W));
    //    std::cout << data[i];
   
    if(data[i] == '1') {  print1(current_field, s);  }
    else if(data[i] == '2') {  print2(current_field, s);  }
    else if(data[i] == '3') {  print3(current_field, s);  }
    else if(data[i] == '4') {  print4(current_field, s);  }
    else if(data[i] == '5') {  print5(current_field, s);  }
    else if(data[i] == '6') {  print6(current_field, s);  }
    else if(data[i] == '7') {  print7(current_field, s);  }
    else if(data[i] == '8') {  print8(current_field, s);  }
    else if(data[i] == '9') {  print9(current_field, s);  }
    else if(data[i] == '0') {  print0(current_field, s);  }

    //    print_field(current_field, (W), H);
  }

  for(int I = 0; I < H; I++){//rows
    for(int i = 0; i < data.size(); i++) {//digits
      for(int j = 0; j < W; j++) {//columns
      std::cout << fields[i][W*I+j];
    }
    if(i!=data.size()-1) std::cout << DELIM;
    }
    if(I!=H-1) std::cout << std::endl;
  }

  for(int i = 0; i < data.size(); i++) {
    delete [] fields[i];
  }
  delete [] fields;
  //  print_field(field, (W+1)*data.size(), H);
}

int main (void) {
  int s = 0;
  std::string n;
  //  std::ifstream fstr ("test.txt", std::ios::in);
  
  while(read_data(s, n, std::cin)){
    //    std::cout << s << std::endl;
    //    std::string strn = std::to_string(n);
    print_data(n, s);
	std::cout << std::endl;
	std::cout << std::endl;
	
  }
  return 0;
}
