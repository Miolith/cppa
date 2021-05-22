#pragma once
#include <asmjit/asmjit.h>
#include <asmjit/core/codeholder.h>
#include <asmjit/core/jitruntime.h>
#include <asmjit/x86/x86assembler.h>

using namespace asmjit;

auto max_int8(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::sil, x86::dil);
  x.mov(x86::eax, x86::edi);
  x.cmovge(x86::eax, x86::esi);
  x.ret();

  char (*fn)(char, char);
  rt.add(&fn, &code);

  return fn;
}

auto max_int16(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::si, x86::di);
  x.mov(x86::eax, x86::edi);
  x.cmovge(x86::eax, x86::esi);
  x.ret();

  short (*fn)(short, short);
  rt.add(&fn, &code);
  return fn;
}

auto max_int32(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::edi, x86::esi);
  x.mov(x86::eax, x86::esi);
  x.cmovge(x86::eax, x86::edi);
  x.ret();

  int (*fn)(int a, int b);
  rt.add(&fn, &code);

  return fn;
}

auto max_int64(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{
  x.cmp(x86::rdi, x86::rsi);
  x.mov(x86::rax, x86::rsi);
  x.cmovge(x86::rax, x86::rdi);
  x.ret();

  long (*fn)(long, long);
  rt.add(&fn, &code);

  return fn;
}

auto max_uint8(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{
  x.cmp(x86::sil, x86::dil);
  x.mov(x86::eax, x86::edi);
  x.cmovnb(x86::eax, x86::esi);
  x.ret();

  unsigned char (*fn)(unsigned char, unsigned char);
  rt.add(&fn, &code);

  return fn;
}

auto max_uint16(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::si, x86::di);
  x.mov(x86::eax, x86::edi);
  x.cmovnb(x86::eax, x86::esi);
  x.ret();

  unsigned short (*fn)(unsigned short, unsigned short);
  rt.add(&fn, &code);

  return fn;
}

auto max_uint32(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{


  x.cmp(x86::edi, x86::esi);
  x.mov(x86::eax, x86::esi);
  x.cmovnb(x86::eax, x86::edi);
  x.ret();

  unsigned int (*fn)(unsigned int, unsigned int);
  rt.add(&fn, &code);

  return fn;
}

auto max_uint64(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{


  x.cmp(x86::rdi, x86::rsi);
  x.mov(x86::rax, x86::rsi);
  x.cmovnb(x86::rax, x86::rdi);
  x.ret();

  unsigned long (*fn)(unsigned long, unsigned long);
  rt.add(&fn, &code);

  return fn;
}

auto max_float32(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{


  x.maxss(x86::xmm1, x86::xmm0);
  x.movaps(x86::xmm0, x86::xmm1);
  x.ret();

  float (*fn)(float, float);
  rt.add(&fn, &code);

  return fn;
}

auto max_float64(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{


  x.maxsd(x86::xmm1, x86::xmm0);
  x.movapd(x86::xmm0, x86::xmm1);
  x.ret();

  double (*fn)(double, double);
  rt.add(&fn, &code);

  return fn;
}

/****** MIN *******/


auto min_int8(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::sil, x86::dil);
  x.mov(x86::eax, x86::edi);
  x.cmovle(x86::eax, x86::esi);
  x.ret();

  char (*fn)(char, char);
  rt.add(&fn, &code);

  return fn;
}

auto min_int16(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::si, x86::di);
  x.mov(x86::eax, x86::edi);
  x.cmovle(x86::eax, x86::esi);
  x.ret();

  short (*fn)(short, short);
  rt.add(&fn, &code);
  return fn;
}

auto min_int32(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::edi, x86::esi);
  x.mov(x86::eax, x86::esi);
  x.cmovle(x86::eax, x86::edi);
  x.ret();

  int (*fn)(int a, int b);
  rt.add(&fn, &code);

  return fn;
}

auto min_int64(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{
  x.cmp(x86::rdi, x86::rsi);
  x.mov(x86::rax, x86::rsi);
  x.cmovle(x86::rax, x86::rdi);
  x.ret();

  long (*fn)(long, long);
  rt.add(&fn, &code);

  return fn;
}

auto min_uint8(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{
  x.cmp(x86::sil, x86::dil);
  x.mov(x86::eax, x86::edi);
  x.cmovbe(x86::eax, x86::esi);
  x.ret();

  unsigned char (*fn)(unsigned char, unsigned char);
  rt.add(&fn, &code);

  return fn;
}

auto min_uint16(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::si, x86::di);
  x.mov(x86::eax, x86::edi);
  x.cmovbe(x86::eax, x86::esi);
  x.ret();

  unsigned short (*fn)(unsigned short, unsigned short);
  rt.add(&fn, &code);

  return fn;
}

auto min_uint32(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::edi, x86::esi);
  x.mov(x86::eax, x86::esi);
  x.cmovbe(x86::eax, x86::edi);
  x.ret();

  unsigned int (*fn)(unsigned int, unsigned int);
  rt.add(&fn, &code);

  return fn;
}

auto min_uint64(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{

  x.cmp(x86::rdi, x86::rsi);
  x.mov(x86::rax, x86::rsi);
  x.cmovbe(x86::rax, x86::rdi);
  x.ret();

  unsigned long (*fn)(unsigned long, unsigned long);
  rt.add(&fn, &code);

  return fn;
}

auto min_float32(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{


  x.minss(x86::xmm1, x86::xmm0);
  x.movaps(x86::xmm0, x86::xmm1);
  x.ret();

  float (*fn)(float, float);
  rt.add(&fn, &code);

  return fn;
}

auto min_float64(JitRuntime& rt, CodeHolder& code, x86::Assembler& x)
{


  x.minsd(x86::xmm1, x86::xmm0);
  x.movapd(x86::xmm0, x86::xmm1);
  x.ret();

  double (*fn)(double, double);
  rt.add(&fn, &code);

  return fn;
}
