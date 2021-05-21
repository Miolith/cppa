#pragma once
#include <asmjit/asmjit.h>

using namespace asmjit;

char max_int8(char a, char b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.cmp(x86::sil, x86::dil);
  x.mov(x86::eax, x86::edi);
  x.cmovge(x86::eax, x86::esi);
  x.ret(); 

  char (*fn)(char a, char b);
  rt.add(&fn, &code);

  char r = fn(a,b);
  rt.release(fn);
  return r;
}

short max_int16(short a, short b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.cmp(x86::si, x86::di);
  x.mov(x86::eax, x86::edi);
  x.cmovge(x86::eax, x86::esi);
  x.ret(); 

  short (*fn)(short a, short b);
  rt.add(&fn, &code);

  short r = fn(a,b);
  rt.release(fn);
  return r;
}

int max_int32(int a, int b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.cmp(x86::edi, x86::esi);
  x.mov(x86::eax, x86::edi);
  x.cmovge(x86::eax, x86::esi);
  x.ret(); 

  int (*fn)(int a, int b);
  rt.add(&fn, &code);

  int r = fn(a,b);
  rt.release(fn);
  return r;
}

long max_int64(long a, long b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.cmp(x86::rdi, x86::rsi);
  x.mov(x86::rax, x86::rdi);
  x.cmovge(x86::rax, x86::rsi);
  x.ret();

  long (*fn)(long a, long b);
  rt.add(&fn, &code);

  return fn(a,b);
  long r = fn(a,b);
  rt.release(fn);
  return r;
}

unsigned char max_uint8(unsigned char a, unsigned char b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.cmp(x86::sil, x86::dil);
  x.mov(x86::eax, x86::edi);
  x.cmovnb(x86::eax, x86::esi);
  x.ret(); 

  unsigned char (*fn)(unsigned char a, unsigned char b);
  rt.add(&fn, &code);

  unsigned char r = fn(a,b);
  rt.release(fn);
  return r;
}

unsigned short max_uint16(unsigned short a, unsigned short b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.cmp(x86::si, x86::di);
  x.mov(x86::eax, x86::edi);
  x.cmovnb(x86::eax, x86::esi);
  x.ret(); 

  short (*fn)(short a, short b);
  rt.add(&fn, &code);

  unsigned short r = fn(a,b);
  rt.release(fn);
  return r;
}

unsigned int max_uint32(unsigned int a, unsigned int b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.cmp(x86::sil, x86::dil);
  x.mov(x86::eax, x86::edi);
  x.cmovnb(x86::eax, x86::esi);
  x.ret(); 

  unsigned int (*fn)(unsigned int a, unsigned b);
  rt.add(&fn, &code);

  unsigned int r = fn(a,b);
  rt.release(fn);
  return r;
}

unsigned long max_uint64(unsigned long a, unsigned long b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.cmp(x86::sil, x86::dil);
  x.mov(x86::eax, x86::edi);
  x.cmovnp(x86::eax, x86::esi);
  x.ret(); 

  unsigned long (*fn)(unsigned long a, unsigned long b);
  rt.add(&fn, &code);

  unsigned long r = fn(a,b);
  rt.release(fn);
  return r;
}

float max_float32(float a, float b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.maxss(x86::xmm1, x86::xmm0);
  x.movaps(x86::xmm0, x86::xmm1);
  x.ret(); 

  float (*fn)(float a, float b);
  rt.add(&fn, &code);

  int r = fn(a,b);
  rt.release(fn);
  return r;
}

double max_float64(double a, double b) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler x(&code);
    
  x.maxsd(x86::xmm1, x86::xmm0);
  x.movapd(x86::xmm0, x86::xmm1);
  x.ret(); 

  double (*fn)(double a, double b);
  rt.add(&fn, &code);

  int r = fn(a,b);
  rt.release(fn);
  return r;
}

char min_int8(char b, char c) {
  JitRuntime rt;

  CodeHolder code;

  code.init(rt.environment());

  x86::Assembler a(&code);
    
  a.cmp(x86::sil, x86::dil);
  a.mov(x86::eax, x86::edi);
  a.cmovge(x86::eax, x86::esi);
  a.ret(); 

  char (*fn)(char a, char b);
  rt.add(&fn, &code);

  int r = fn(a,b);
  rt.release(fn);
  return r;
}

short min_int16(short a, short b) {
    return a < b ? b : a;
}

int min_int32(int a, int b) {
    return a < b ? b : a;
}

long min_int64(long a, long b) {
    return a < b ? b : a;
}

unsigned char min_uint8(unsigned char a, unsigned char b) {
    return a > b ? b : a;
}

unsigned short min_uint16(unsigned short a, unsigned short b) {
    return a < b ? b : a;
}

unsigned int min_uint32(unsigned int a, unsigned int b) {
    return a < b ? b : a;
}

unsigned long min_uint64(unsigned long a, unsigned long b) {
    return a < b ? b : a;
}

float min_float32(float a, float b) {
    return a < b ? b : a;
}

double min_float64(double a, double b) {
    return a < b ? b : a;
}
