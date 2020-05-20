	.file	"main.cpp"
# GNU C++14 (GCC) version 9.2.0 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 9.2.0, GMP version 6.1.0, MPFR version 3.1.4, MPC version 1.0.3, isl version isl-0.18-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -D_GNU_SOURCE main.cpp -mtune=generic -march=x86-64
# -fverbose-asm
# options enabled:  -faggressive-loop-optimizations -fassume-phsa
# -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -fexceptions -ffp-int-builtin-inexact
# -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
# -finline-atomics -fipa-stack-alignment -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
# -fplt -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.align 4
	.type	_ZN9__gnu_cxxL21__default_lock_policyE, @object
	.size	_ZN9__gnu_cxxL21__default_lock_policyE, 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.type	_ZStL13allocator_arg, @object
	.size	_ZStL13allocator_arg, 1
_ZStL13allocator_arg:
	.zero	1
	.type	_ZStL6ignore, @object
	.size	_ZStL6ignore, 1
_ZStL6ignore:
	.zero	1
	.section	.text._ZStanSt12memory_orderSt23__memory_order_modifier,"axG",@progbits,_ZStanSt12memory_orderSt23__memory_order_modifier,comdat
	.weak	_ZStanSt12memory_orderSt23__memory_order_modifier
	.type	_ZStanSt12memory_orderSt23__memory_order_modifier, @function
_ZStanSt12memory_orderSt23__memory_order_modifier:
.LFB2725:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)	# __m, __m
	movl	%esi, -8(%rbp)	# __mod, __mod
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:101:     return memory_order(int(__m) & int(__mod));
	movl	-4(%rbp), %edx	# __m, __m.9_1
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:101:     return memory_order(int(__m) & int(__mod));
	movl	-8(%rbp), %eax	# __mod, __mod.10_2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:101:     return memory_order(int(__m) & int(__mod));
	andl	%edx, %eax	# __m.9_1, _3
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:102:   }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2725:
	.size	_ZStanSt12memory_orderSt23__memory_order_modifier, .-_ZStanSt12memory_orderSt23__memory_order_modifier
	.section	.text._ZNSt6thread2idC2Ev,"axG",@progbits,_ZNSt6thread2idC5Ev,comdat
	.align 2
	.weak	_ZNSt6thread2idC2Ev
	.type	_ZNSt6thread2idC2Ev, @function
_ZNSt6thread2idC2Ev:
.LFB2870:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:82:       id() noexcept : _M_thread() { }
	movq	-8(%rbp), %rax	# this, tmp82
	movq	$0, (%rax)	#, this_2(D)->_M_thread
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:82:       id() noexcept : _M_thread() { }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2870:
	.size	_ZNSt6thread2idC2Ev, .-_ZNSt6thread2idC2Ev
	.weak	_ZNSt6thread2idC1Ev
	.set	_ZNSt6thread2idC1Ev,_ZNSt6thread2idC2Ev
	.section	.text._ZNSt6threadD2Ev,"axG",@progbits,_ZNSt6threadD5Ev,comdat
	.align 2
	.weak	_ZNSt6threadD2Ev
	.type	_ZNSt6threadD2Ev, @function
_ZNSt6threadD2Ev:
.LFB2877:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:138:       if (joinable())
	movq	-8(%rbp), %rax	# this, tmp83
	movq	%rax, %rdi	# tmp83,
	call	_ZNKSt6thread8joinableEv	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:138:       if (joinable())
	testb	%al, %al	# retval.26_4
	je	.L6	#,
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:139: 	std::terminate();
	call	_ZSt9terminatev	#
.L6:
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:140:     }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2877:
	.size	_ZNSt6threadD2Ev, .-_ZNSt6threadD2Ev
	.weak	_ZNSt6threadD1Ev
	.set	_ZNSt6threadD1Ev,_ZNSt6threadD2Ev
	.section	.text._ZNKSt6thread8joinableEv,"axG",@progbits,_ZNKSt6thread8joinableEv,comdat
	.align 2
	.weak	_ZNKSt6thread8joinableEv
	.type	_ZNKSt6thread8joinableEv, @function
_ZNKSt6thread8joinableEv:
.LFB2884:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:163:     { return !(_M_id == id()); }
	leaq	-8(%rbp), %rax	#, tmp85
	movq	%rax, %rdi	# tmp85,
	call	_ZNSt6thread2idC1Ev	#
	movq	-8(%rbp), %rax	# D.54280, tmp86
	movq	-24(%rbp), %rdx	# this, tmp87
	movq	%rax, %rsi	# tmp86,
	movq	(%rdx), %rdi	# this_4(D)->_M_id,
	call	_ZSteqNSt6thread2idES0_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:163:     { return !(_M_id == id()); }
	xorl	$1, %eax	#, _6
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:163:     { return !(_M_id == id()); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2884:
	.size	_ZNKSt6thread8joinableEv, .-_ZNKSt6thread8joinableEv
	.section	.text._ZSteqNSt6thread2idES0_,"axG",@progbits,_ZSteqNSt6thread2idES0_,comdat
	.weak	_ZSteqNSt6thread2idES0_
	.type	_ZSteqNSt6thread2idES0_, @function
_ZSteqNSt6thread2idES0_:
.LFB2896:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __x, __x
	movq	%rsi, -16(%rbp)	# __y, __y
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:282:     return __x._M_thread == __y._M_thread;
	movq	-8(%rbp), %rdx	# __x._M_thread, _1
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:282:     return __x._M_thread == __y._M_thread;
	movq	-16(%rbp), %rax	# __y._M_thread, _2
	cmpq	%rax, %rdx	# _2, _1
	sete	%al	#, _4
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:283:   }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2896:
	.size	_ZSteqNSt6thread2idES0_, .-_ZSteqNSt6thread2idES0_
	.section	.rodata
	.type	_ZStL10defer_lock, @object
	.size	_ZStL10defer_lock, 1
_ZStL10defer_lock:
	.zero	1
	.type	_ZStL11try_to_lock, @object
	.size	_ZStL11try_to_lock, 1
_ZStL11try_to_lock:
	.zero	1
	.type	_ZStL10adopt_lock, @object
	.size	_ZStL10adopt_lock, 1
_ZStL10adopt_lock:
	.zero	1
	.globl	_Z3ptrB5cxx11
	.bss
	.align 8
	.type	_Z3ptrB5cxx11, @object
	.size	_Z3ptrB5cxx11, 8
_Z3ptrB5cxx11:
	.zero	8
	.globl	data
	.align 4
	.type	data, @object
	.size	data, 4
data:
	.zero	4
	.section	.rodata
.LC0:
	.string	"Hello"
	.text
	.globl	_Z8producerv
	.type	_Z8producerv, @function
_Z8producerv:
.LFB3983:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3983
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%r12	#
	pushq	%rbx	#
	subq	$16, %rsp	#,
	.cfi_offset 12, -24
	.cfi_offset 3, -32
# main.cpp:21:     std::string* p = new std::string("Hello");
	leaq	-25(%rbp), %rax	#, tmp85
	movq	%rax, %rdi	# tmp85,
	call	_ZNSaIcEC1Ev	#
	leaq	-25(%rbp), %r12	#, _4
	movl	$32, %edi	#,
.LEHB0:
	call	_Znwm	#
.LEHE0:
	movq	%rax, %rbx	# tmp86, _6
	movq	%r12, %rdx	# _4,
	movl	$.LC0, %esi	#,
	movq	%rbx, %rdi	# _6,
.LEHB1:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_	#
.LEHE1:
# main.cpp:21:     std::string* p = new std::string("Hello");
	movq	%rbx, -24(%rbp)	# _6, p
	leaq	-25(%rbp), %rax	#, tmp87
	movq	%rax, %rdi	# tmp87,
	call	_ZNSaIcED1Ev	#
# main.cpp:22:     data = 42;
	movl	$42, data(%rip)	#, data
# main.cpp:23:     ptr.store(p, std::memory_order_release);
	movq	-24(%rbp), %rax	# p, tmp88
	movl	$3, %edx	#,
	movq	%rax, %rsi	# tmp88,
	movl	$_Z3ptrB5cxx11, %edi	#,
	call	_ZNSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE5storeES6_St12memory_order	#
# main.cpp:24: }
	jmp	.L16	#
.L15:
	movq	%rax, %r12	#, tmp90
# main.cpp:21:     std::string* p = new std::string("Hello");
	movl	$32, %esi	#,
	movq	%rbx, %rdi	# _6,
	call	_ZdlPvm	#
	movq	%r12, %rbx	# tmp90, tmp89
	jmp	.L13	#
.L14:
	movq	%rax, %rbx	#, tmp89
.L13:
# main.cpp:21:     std::string* p = new std::string("Hello");
	leaq	-25(%rbp), %rax	#, tmp93
	movq	%rax, %rdi	# tmp93,
	call	_ZNSaIcED1Ev	#
	movq	%rbx, %rax	# tmp89, D.80646
	movq	%rax, %rdi	# D.80646,
.LEHB2:
	call	_Unwind_Resume	#
.LEHE2:
.L16:
# main.cpp:24: }
	addq	$16, %rsp	#,
	popq	%rbx	#
	popq	%r12	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3983:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA3983:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3983-.LLSDACSB3983
.LLSDACSB3983:
	.uleb128 .LEHB0-.LFB3983
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L14-.LFB3983
	.uleb128 0
	.uleb128 .LEHB1-.LFB3983
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L15-.LFB3983
	.uleb128 0
	.uleb128 .LEHB2-.LFB3983
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE3983:
	.text
	.size	_Z8producerv, .-_Z8producerv
	.section	.rodata
.LC1:
	.string	"void consumer()"
.LC2:
	.string	"main.cpp"
.LC3:
	.string	"*p2 == \"Hello\""
.LC4:
	.string	"data == 42"
	.text
	.globl	_Z8consumerv
	.type	_Z8consumerv, @function
_Z8consumerv:
.LFB3984:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
.L19:
# main.cpp:29:     while (!(p2 = ptr.load(std::memory_order_acquire)))
	movl	$2, %esi	#,
	movl	$_Z3ptrB5cxx11, %edi	#,
	call	_ZNKSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4loadESt12memory_order	#
	movq	%rax, -8(%rbp)	# tmp85, p2
# main.cpp:29:     while (!(p2 = ptr.load(std::memory_order_acquire)))
	cmpq	$0, -8(%rbp)	#, p2
	sete	%al	#, retval.11_7
	testb	%al, %al	# retval.11_7
	je	.L18	#,
# main.cpp:29:     while (!(p2 = ptr.load(std::memory_order_acquire)))
	jmp	.L19	#
.L18:
# main.cpp:31:     assert(*p2 == "Hello"); // never fires
	movq	-8(%rbp), %rax	# p2, tmp86
	movl	$.LC0, %esi	#,
	movq	%rax, %rdi	# tmp86,
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_	#
	testb	%al, %al	# _1
	jne	.L20	#,
# main.cpp:31:     assert(*p2 == "Hello"); // never fires
	movl	$.LC1, %ecx	#,
	movl	$31, %edx	#,
	movl	$.LC2, %esi	#,
	movl	$.LC3, %edi	#,
	call	__assert_fail	#
.L20:
# main.cpp:32:     assert(data == 42); // never fires
	movl	data(%rip), %eax	# data, data.12_2
	cmpl	$42, %eax	#, data.12_2
	je	.L22	#,
# main.cpp:32:     assert(data == 42); // never fires
	movl	$.LC1, %ecx	#,
	movl	$32, %edx	#,
	movl	$.LC2, %esi	#,
	movl	$.LC4, %edi	#,
	call	__assert_fail	#
.L22:
# main.cpp:33: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3984:
	.size	_Z8consumerv, .-_Z8consumerv
	.section	.rodata
.LC5:
	.string	""
	.text
	.globl	_Z11computationB5cxx11i
	.type	_Z11computationB5cxx11i, @function
_Z11computationB5cxx11i:
.LFB3985:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3985
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%rbx	#
	subq	$40, %rsp	#,
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)	# .result_ptr, .result_ptr
	movl	%esi, -44(%rbp)	# D.73201, D.73201
# main.cpp:37:     return "";
	leaq	-17(%rbp), %rax	#, tmp83
	movq	%rax, %rdi	# tmp83,
	call	_ZNSaIcEC1Ev	#
	leaq	-17(%rbp), %rdx	#, tmp84
	movq	-40(%rbp), %rax	# <retval>, tmp85
	movl	$.LC5, %esi	#,
	movq	%rax, %rdi	# tmp85,
.LEHB3:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_	#
.LEHE3:
	leaq	-17(%rbp), %rax	#, tmp86
	movq	%rax, %rdi	# tmp86,
	call	_ZNSaIcED1Ev	#
	jmp	.L27	#
.L26:
	movq	%rax, %rbx	#, tmp88
	leaq	-17(%rbp), %rax	#, tmp87
	movq	%rax, %rdi	# tmp87,
	call	_ZNSaIcED1Ev	#
	movq	%rbx, %rax	# tmp88, D.80652
	movq	%rax, %rdi	# D.80652,
.LEHB4:
	call	_Unwind_Resume	#
.LEHE4:
.L27:
# main.cpp:38: }
	movq	-40(%rbp), %rax	# <retval>,
	addq	$40, %rsp	#,
	popq	%rbx	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3985:
	.section	.gcc_except_table
.LLSDA3985:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3985-.LLSDACSB3985
.LLSDACSB3985:
	.uleb128 .LEHB3-.LFB3985
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L26-.LFB3985
	.uleb128 0
	.uleb128 .LEHB4-.LFB3985
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE3985:
	.text
	.size	_Z11computationB5cxx11i, .-_Z11computationB5cxx11i
	.globl	_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB3986:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# D.73206, D.73206
# main.cpp:42: }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3986:
	.size	_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.globl	arr1
	.bss
	.align 4
	.type	arr1, @object
	.size	arr1, 4
arr1:
	.zero	4
	.globl	arr2
	.align 4
	.type	arr2, @object
	.size	arr2, 4
arr2:
	.zero	4
	.globl	arr3
	.align 4
	.type	arr3, @object
	.size	arr3, 4
arr3:
	.zero	4
	.globl	v
	.align 4
	.type	v, @object
	.size	v, 4
v:
	.zero	4
	.globl	_Z9dataarrayB5cxx11
	.align 32
	.type	_Z9dataarrayB5cxx11, @object
	.size	_Z9dataarrayB5cxx11, 32000
_Z9dataarrayB5cxx11:
	.zero	32000
	.text
	.globl	_Z7ThreadAiii
	.type	_Z7ThreadAiii, @function
_Z7ThreadAiii:
.LFB3987:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	addq	$-128, %rsp	#,
	movl	%edi, -116(%rbp)	# v0, v0
	movl	%esi, -120(%rbp)	# v1, v1
	movl	%edx, -124(%rbp)	# v2, v2
# main.cpp:51:     arr1.store(v);
	movl	v(%rip), %eax	# v, v.14_1
	movl	%eax, -8(%rbp)	# v.14_1, __i
	movl	$5, -12(%rbp)	#, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:392: 	memory_order __b = __m & __memory_order_mask;
	movl	-12(%rbp), %eax	# __m, tmp90
	movl	$65535, %esi	#,
	movl	%eax, %edi	# tmp90,
	call	_ZStanSt12memory_orderSt23__memory_order_modifier	#
	movl	%eax, -16(%rbp)	# tmp91, __b
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:397: 	__atomic_store_n(&_M_i, __i, int(__m));
	movl	-8(%rbp), %eax	# __i, __i.16_30
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:397: 	__atomic_store_n(&_M_i, __i, int(__m));
	movl	$arr1, %edx	#, _31
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:397: 	__atomic_store_n(&_M_i, __i, int(__m));
	movl	%eax, (%rdx)	#, __i.16_30,* _31
	mfence	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:398:       }
	nop	
# main.cpp:54:     dataarray[v0] = computation(v0);
	leaq	-112(%rbp), %rax	#, tmp92
	movl	-116(%rbp), %edx	# v0, tmp93
	movl	%edx, %esi	# tmp93,
	movq	%rax, %rdi	# tmp92,
	call	_Z11computationB5cxx11i	#
# main.cpp:54:     dataarray[v0] = computation(v0);
	movl	-116(%rbp), %eax	# v0, tmp95
	cltq
	salq	$5, %rax	#, tmp96
	leaq	_Z9dataarrayB5cxx11(%rax), %rdx	#, _2
	leaq	-112(%rbp), %rax	#, tmp97
	movq	%rax, %rsi	# tmp97,
	movq	%rdx, %rdi	# _2,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_	#
# main.cpp:54:     dataarray[v0] = computation(v0);
	leaq	-112(%rbp), %rax	#, tmp98
	movq	%rax, %rdi	# tmp98,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev	#
# main.cpp:55:     dataarray[v1] = computation(v1);
	leaq	-80(%rbp), %rax	#, tmp99
	movl	-120(%rbp), %edx	# v1, tmp100
	movl	%edx, %esi	# tmp100,
	movq	%rax, %rdi	# tmp99,
	call	_Z11computationB5cxx11i	#
# main.cpp:55:     dataarray[v1] = computation(v1);
	movl	-120(%rbp), %eax	# v1, tmp102
	cltq
	salq	$5, %rax	#, tmp103
	leaq	_Z9dataarrayB5cxx11(%rax), %rdx	#, _3
	leaq	-80(%rbp), %rax	#, tmp104
	movq	%rax, %rsi	# tmp104,
	movq	%rdx, %rdi	# _3,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_	#
# main.cpp:55:     dataarray[v1] = computation(v1);
	leaq	-80(%rbp), %rax	#, tmp105
	movq	%rax, %rdi	# tmp105,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev	#
# main.cpp:56:     dataarray[v2] = computation(v2);
	leaq	-48(%rbp), %rax	#, tmp106
	movl	-124(%rbp), %edx	# v2, tmp107
	movl	%edx, %esi	# tmp107,
	movq	%rax, %rdi	# tmp106,
	call	_Z11computationB5cxx11i	#
# main.cpp:56:     dataarray[v2] = computation(v2);
	movl	-124(%rbp), %eax	# v2, tmp109
	cltq
	salq	$5, %rax	#, tmp110
	leaq	_Z9dataarrayB5cxx11(%rax), %rdx	#, _4
	leaq	-48(%rbp), %rax	#, tmp111
	movq	%rax, %rsi	# tmp111,
	movq	%rdx, %rdi	# _4,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_	#
# main.cpp:56:     dataarray[v2] = computation(v2);
	leaq	-48(%rbp), %rax	#, tmp112
	movq	%rax, %rdi	# tmp112,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev	#
	movl	$3, -4(%rbp)	#, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:121:   { __atomic_thread_fence(int(__m)); }
	mfence	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:121:   { __atomic_thread_fence(int(__m)); }
	nop	
# main.cpp:58:     std::atomic_store_explicit(&arr1, v0, std::memory_order_relaxed);
	movl	-116(%rbp), %eax	# v0, tmp113
	movl	$0, %edx	#,
	movl	%eax, %esi	# tmp113,
	movl	$arr1, %edi	#,
	call	_ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order	#
# main.cpp:59:     std::atomic_store_explicit(&arr2, v1, std::memory_order_relaxed);
	movl	-120(%rbp), %eax	# v1, tmp114
	movl	$0, %edx	#,
	movl	%eax, %esi	# tmp114,
	movl	$arr2, %edi	#,
	call	_ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order	#
# main.cpp:60:     std::atomic_store_explicit(&arr3, v2, std::memory_order_relaxed);
	movl	-124(%rbp), %eax	# v2, tmp115
	movl	$0, %edx	#,
	movl	%eax, %esi	# tmp115,
	movl	$arr3, %edi	#,
	call	_ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order	#
# main.cpp:61: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3987:
	.size	_Z7ThreadAiii, .-_Z7ThreadAiii
	.globl	_Z7ThreadBv
	.type	_Z7ThreadBv, @function
_Z7ThreadBv:
.LFB3991:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$112, %rsp	#,
# main.cpp:66:     int v0 = std::atomic_load_explicit(&arr1, std::memory_order_relaxed);
	movl	$0, %esi	#,
	movl	$arr1, %edi	#,
	call	_ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order	#
	movl	%eax, -4(%rbp)	# tmp86, v0
# main.cpp:67:     int v1 = std::atomic_load_explicit(&arr2, std::memory_order_relaxed);
	movl	$0, %esi	#,
	movl	$arr2, %edi	#,
	call	_ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order	#
	movl	%eax, -8(%rbp)	# tmp87, v1
# main.cpp:68:     int v2 = std::atomic_load_explicit(&arr3, std::memory_order_relaxed);
	movl	$0, %esi	#,
	movl	$arr3, %edi	#,
	call	_ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order	#
	movl	%eax, -12(%rbp)	# tmp88, v2
	movl	$2, -16(%rbp)	#, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:121:   { __atomic_thread_fence(int(__m)); }
	mfence	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:121:   { __atomic_thread_fence(int(__m)); }
	nop	
# main.cpp:72:     if (v0 != -1) { print(dataarray[v0]); }
	cmpl	$-1, -4(%rbp)	#, v0
	je	.L31	#,
# main.cpp:72:     if (v0 != -1) { print(dataarray[v0]); }
	movl	-4(%rbp), %eax	# v0, tmp90
	cltq
	salq	$5, %rax	#, tmp91
	leaq	_Z9dataarrayB5cxx11(%rax), %rdx	#, _1
# main.cpp:72:     if (v0 != -1) { print(dataarray[v0]); }
	leaq	-112(%rbp), %rax	#, tmp92
	movq	%rdx, %rsi	# _1,
	movq	%rax, %rdi	# tmp92,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_	#
	leaq	-112(%rbp), %rax	#, tmp93
	movq	%rax, %rdi	# tmp93,
	call	_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
	leaq	-112(%rbp), %rax	#, tmp94
	movq	%rax, %rdi	# tmp94,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev	#
.L31:
# main.cpp:73:     if (v1 != -1) { print(dataarray[v1]); }
	cmpl	$-1, -8(%rbp)	#, v1
	je	.L32	#,
# main.cpp:73:     if (v1 != -1) { print(dataarray[v1]); }
	movl	-8(%rbp), %eax	# v1, tmp96
	cltq
	salq	$5, %rax	#, tmp97
	leaq	_Z9dataarrayB5cxx11(%rax), %rdx	#, _2
# main.cpp:73:     if (v1 != -1) { print(dataarray[v1]); }
	leaq	-80(%rbp), %rax	#, tmp98
	movq	%rdx, %rsi	# _2,
	movq	%rax, %rdi	# tmp98,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_	#
	leaq	-80(%rbp), %rax	#, tmp99
	movq	%rax, %rdi	# tmp99,
	call	_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
	leaq	-80(%rbp), %rax	#, tmp100
	movq	%rax, %rdi	# tmp100,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev	#
.L32:
# main.cpp:74:     if (v2 != -1) { print(dataarray[v2]); }
	cmpl	$-1, -12(%rbp)	#, v2
	je	.L34	#,
# main.cpp:74:     if (v2 != -1) { print(dataarray[v2]); }
	movl	-12(%rbp), %eax	# v2, tmp102
	cltq
	salq	$5, %rax	#, tmp103
	leaq	_Z9dataarrayB5cxx11(%rax), %rdx	#, _3
# main.cpp:74:     if (v2 != -1) { print(dataarray[v2]); }
	leaq	-48(%rbp), %rax	#, tmp104
	movq	%rdx, %rsi	# _3,
	movq	%rax, %rdi	# tmp104,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_	#
	leaq	-48(%rbp), %rax	#, tmp105
	movq	%rax, %rdi	# tmp105,
	call	_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
	leaq	-48(%rbp), %rax	#, tmp106
	movq	%rax, %rdi	# tmp106,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev	#
.L34:
# main.cpp:75: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3991:
	.size	_Z7ThreadBv, .-_Z7ThreadBv
	.globl	main
	.type	main, @function
main:
.LFB3992:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3992
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%rbx	#
	subq	$40, %rsp	#,
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)	# argc, argc
	movq	%rsi, -48(%rbp)	# argv, argv
# main.cpp:80:     std::thread t1(producer);
	leaq	-24(%rbp), %rax	#, tmp85
	movl	$_Z8producerv, %esi	#,
	movq	%rax, %rdi	# tmp85,
.LEHB5:
	call	_ZNSt6threadC1IRFvvEJEvEEOT_DpOT0_	#
.LEHE5:
# main.cpp:81:     std::thread t2(consumer);
	leaq	-32(%rbp), %rax	#, tmp86
	movl	$_Z8consumerv, %esi	#,
	movq	%rax, %rdi	# tmp86,
.LEHB6:
	call	_ZNSt6threadC1IRFvvEJEvEEOT_DpOT0_	#
.LEHE6:
# main.cpp:82:     t1.join();
	leaq	-24(%rbp), %rax	#, tmp87
	movq	%rax, %rdi	# tmp87,
.LEHB7:
	call	_ZNSt6thread4joinEv	#
# main.cpp:83:     t2.join();
	leaq	-32(%rbp), %rax	#, tmp88
	movq	%rax, %rdi	# tmp88,
	call	_ZNSt6thread4joinEv	#
.LEHE7:
# main.cpp:85: 	return 0;
	movl	$0, %ebx	#, _9
# main.cpp:81:     std::thread t2(consumer);
	leaq	-32(%rbp), %rax	#, tmp89
	movq	%rax, %rdi	# tmp89,
	call	_ZNSt6threadD1Ev	#
# main.cpp:80:     std::thread t1(producer);
	leaq	-24(%rbp), %rax	#, tmp90
	movq	%rax, %rdi	# tmp90,
	call	_ZNSt6threadD1Ev	#
	movl	%ebx, %eax	# _9, <retval>
	jmp	.L41	#
.L40:
	movq	%rax, %rbx	#, tmp94
# main.cpp:81:     std::thread t2(consumer);
	leaq	-32(%rbp), %rax	#, tmp92
	movq	%rax, %rdi	# tmp92,
	call	_ZNSt6threadD1Ev	#
	jmp	.L38	#
.L39:
	movq	%rax, %rbx	#, tmp93
.L38:
# main.cpp:80:     std::thread t1(producer);
	leaq	-24(%rbp), %rax	#, tmp97
	movq	%rax, %rdi	# tmp97,
	call	_ZNSt6threadD1Ev	#
	movq	%rbx, %rax	# tmp93, D.80658
	movq	%rax, %rdi	# D.80658,
.LEHB8:
	call	_Unwind_Resume	#
.LEHE8:
.L41:
# main.cpp:86: }
	addq	$40, %rsp	#,
	popq	%rbx	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3992:
	.section	.gcc_except_table
.LLSDA3992:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3992-.LLSDACSB3992
.LLSDACSB3992:
	.uleb128 .LEHB5-.LFB3992
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB6-.LFB3992
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L39-.LFB3992
	.uleb128 0
	.uleb128 .LEHB7-.LFB3992
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L40-.LFB3992
	.uleb128 0
	.uleb128 .LEHB8-.LFB3992
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
.LLSDACSE3992:
	.text
	.size	main, .-main
	.section	.text._ZNSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE5storeES6_St12memory_order,"axG",@progbits,_ZNSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE5storeES6_St12memory_order,comdat
	.align 2
	.weak	_ZNSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE5storeES6_St12memory_order
	.type	_ZNSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE5storeES6_St12memory_order, @function
_ZNSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE5storeES6_St12memory_order:
.LFB4324:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$64, %rsp	#,
	movq	%rdi, -40(%rbp)	# this, this
	movq	%rsi, -48(%rbp)	# __p, __p
	movl	%edx, -52(%rbp)	# __m, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/atomic:510:       { return _M_b.store(__p, __m); }
	movq	-40(%rbp), %rax	# this, _1
	movq	%rax, -8(%rbp)	# _1, this
	movq	-48(%rbp), %rax	# __p, tmp86
	movq	%rax, -16(%rbp)	# tmp86, __p
	movl	-52(%rbp), %eax	# __m, tmp87
	movl	%eax, -20(%rbp)	# tmp87, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:712:         memory_order __b = __m & __memory_order_mask;
	movl	-20(%rbp), %eax	# __m, tmp88
	movl	$65535, %esi	#,
	movl	%eax, %edi	# tmp88,
	call	_ZStanSt12memory_orderSt23__memory_order_modifier	#
	movl	%eax, -24(%rbp)	# tmp89, __b
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:718: 	__atomic_store_n(&_M_p, __p, int(__m));
	movq	-16(%rbp), %rdx	# __p, __p.8_11
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:718: 	__atomic_store_n(&_M_p, __p, int(__m));
	movq	-8(%rbp), %rax	# this, _12
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:718: 	__atomic_store_n(&_M_p, __p, int(__m));
	movq	%rdx, (%rax)	#, __p.8_11,* _12
	mfence	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:719:       }
	nop	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/atomic:510:       { return _M_b.store(__p, __m); }
	nop	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/atomic:510:       { return _M_b.store(__p, __m); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4324:
	.size	_ZNSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE5storeES6_St12memory_order, .-_ZNSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE5storeES6_St12memory_order
	.section	.text._ZNKSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4loadESt12memory_order,"axG",@progbits,_ZNKSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4loadESt12memory_order,comdat
	.align 2
	.weak	_ZNKSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4loadESt12memory_order
	.type	_ZNKSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4loadESt12memory_order, @function
_ZNKSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4loadESt12memory_order:
.LFB4325:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# this, this
	movl	%esi, -28(%rbp)	# __m, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/atomic:519:       { return _M_b.load(__m); }
	movq	-24(%rbp), %rax	# this, _1
	movq	%rax, -8(%rbp)	# _1, this
	movl	-28(%rbp), %eax	# __m, tmp88
	movl	%eax, -12(%rbp)	# tmp88, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:736: 	memory_order __b = __m & __memory_order_mask;
	movl	-12(%rbp), %eax	# __m, tmp89
	movl	$65535, %esi	#,
	movl	%eax, %edi	# tmp89,
	call	_ZStanSt12memory_orderSt23__memory_order_modifier	#
	movl	%eax, -16(%rbp)	# tmp90, __b
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:740: 	return __atomic_load_n(&_M_p, int(__m));
	movq	-8(%rbp), %rax	# this, _10
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:740: 	return __atomic_load_n(&_M_p, int(__m));
	movq	(%rax), %rax	#* _10, _11
# /usr/local/gcc-9.2.0/include/c++/9.2.0/atomic:519:       { return _M_b.load(__m); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4325:
	.size	_ZNKSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4loadESt12memory_order, .-_ZNKSt6atomicIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4loadESt12memory_order
	.section	.text._ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_,"axG",@progbits,_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_,comdat
	.weak	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	.type	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_, @function
_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_:
.LFB4326:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __lhs, __lhs
	movq	%rsi, -16(%rbp)	# __rhs, __rhs
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/basic_string.h:6177:     { return __lhs.compare(__rhs) == 0; }
	movq	-16(%rbp), %rdx	# __rhs, tmp85
	movq	-8(%rbp), %rax	# __lhs, tmp86
	movq	%rdx, %rsi	# tmp85,
	movq	%rax, %rdi	# tmp86,
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7compareEPKc	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/basic_string.h:6177:     { return __lhs.compare(__rhs) == 0; }
	testl	%eax, %eax	# _1
	sete	%al	#, _6
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/basic_string.h:6177:     { return __lhs.compare(__rhs) == 0; }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4326:
	.size	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_, .-_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	.section	.text._ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order,"axG",@progbits,_ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order,comdat
	.weak	_ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order
	.type	_ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order, @function
_ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order:
.LFB4332:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$48, %rsp	#,
	movq	%rdi, -40(%rbp)	# __a, __a
	movl	%esi, -44(%rbp)	# __i, __i
	movl	%edx, -48(%rbp)	# __m, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/atomic:1197:     { __a->store(__i, __m); }
	movq	-40(%rbp), %rax	# __a, _1
	movq	%rax, -8(%rbp)	# _1, this
	movl	-44(%rbp), %eax	# __i, tmp86
	movl	%eax, -12(%rbp)	# tmp86, __i
	movl	-48(%rbp), %eax	# __m, tmp87
	movl	%eax, -16(%rbp)	# tmp87, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:392: 	memory_order __b = __m & __memory_order_mask;
	movl	-16(%rbp), %eax	# __m, tmp88
	movl	$65535, %esi	#,
	movl	%eax, %edi	# tmp88,
	call	_ZStanSt12memory_orderSt23__memory_order_modifier	#
	movl	%eax, -20(%rbp)	# tmp89, __b
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:397: 	__atomic_store_n(&_M_i, __i, int(__m));
	movl	-12(%rbp), %edx	# __i, __i.16_11
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:397: 	__atomic_store_n(&_M_i, __i, int(__m));
	movq	-8(%rbp), %rax	# this, _12
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:397: 	__atomic_store_n(&_M_i, __i, int(__m));
	movl	%edx, (%rax)	#, __i.16_11,* _12
	mfence	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:398:       }
	nop	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/atomic:1197:     { __a->store(__i, __m); }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4332:
	.size	_ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order, .-_ZSt21atomic_store_explicitIiEvPSt6atomicIT_ENS2_10value_typeESt12memory_order
	.section	.text._ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order,"axG",@progbits,_ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order,comdat
	.weak	_ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order
	.type	_ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order, @function
_ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order:
.LFB4333:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# __a, __a
	movl	%esi, -28(%rbp)	# __m, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/atomic:1208:     { return __a->load(__m); }
	movq	-24(%rbp), %rax	# __a, _1
	movq	%rax, -8(%rbp)	# _1, this
	movl	-28(%rbp), %eax	# __m, tmp88
	movl	%eax, -12(%rbp)	# tmp88, __m
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:415: 	memory_order __b = __m & __memory_order_mask;
	movl	-12(%rbp), %eax	# __m, tmp89
	movl	$65535, %esi	#,
	movl	%eax, %edi	# tmp89,
	call	_ZStanSt12memory_orderSt23__memory_order_modifier	#
	movl	%eax, -16(%rbp)	# tmp90, __b
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:419: 	return __atomic_load_n(&_M_i, int(__m));
	movq	-8(%rbp), %rax	# this, _10
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/atomic_base.h:419: 	return __atomic_load_n(&_M_i, int(__m));
	movl	(%rax), %eax	#* _10, _11
# /usr/local/gcc-9.2.0/include/c++/9.2.0/atomic:1208:     { return __a->load(__m); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4333:
	.size	_ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order, .-_ZSt20atomic_load_explicitIiET_PKSt6atomicIS0_ESt12memory_order
	.section	.text._ZNSt6threadC2IRFvvEJEvEEOT_DpOT0_,"axG",@progbits,_ZNSt6threadC5IRFvvEJEvEEOT_DpOT0_,comdat
	.align 2
	.weak	_ZNSt6threadC2IRFvvEJEvEEOT_DpOT0_
	.type	_ZNSt6threadC2IRFvvEJEvEEOT_DpOT0_, @function
_ZNSt6threadC2IRFvvEJEvEEOT_DpOT0_:
.LFB4340:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA4340
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%rbx	#
	subq	$56, %rsp	#,
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)	# this, this
	movq	%rsi, -64(%rbp)	# __f, __f
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:118:       {
	movq	-56(%rbp), %rax	# this, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt6thread2idC1Ev	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:126: 	auto __depend = reinterpret_cast<void(*)()>(&pthread_create);
	movq	$pthread_create, -24(%rbp)	#, __depend
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:130:         _M_start_thread(_S_make_state(
	movq	-64(%rbp), %rax	# __f, tmp85
	movq	%rax, %rdi	# tmp85,
	call	_ZSt7forwardIRFvvEEOT_RNSt16remove_referenceIS2_E4typeE	#
	movq	%rax, %rdx	#, _2
	leaq	-32(%rbp), %rax	#, tmp86
	movq	%rdx, %rsi	# _2,
	movq	%rax, %rdi	# tmp86,
.LEHB9:
	call	_ZNSt6thread14__make_invokerIRFvvEJEEENS_8_InvokerISt5tupleIJNSt5decayIT_E4typeEDpNS5_IT0_E4typeEEEEEOS6_DpOS9_	#
	leaq	-40(%rbp), %rax	#, tmp87
	leaq	-32(%rbp), %rdx	#, tmp88
	movq	%rdx, %rsi	# tmp88,
	movq	%rax, %rdi	# tmp87,
	call	_ZNSt6thread13_S_make_stateINS_8_InvokerISt5tupleIJPFvvEEEEEEESt10unique_ptrINS_6_StateESt14default_deleteIS8_EEOT_	#
.LEHE9:
	movq	-24(%rbp), %rdx	# __depend, tmp89
	leaq	-40(%rbp), %rcx	#, tmp90
	movq	-56(%rbp), %rax	# this, tmp91
	movq	%rcx, %rsi	# tmp90,
	movq	%rax, %rdi	# tmp91,
.LEHB10:
	call	_ZNSt6thread15_M_start_threadESt10unique_ptrINS_6_StateESt14default_deleteIS1_EEPFvvE	#
.LEHE10:
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:130:         _M_start_thread(_S_make_state(
	leaq	-40(%rbp), %rax	#, tmp92
	movq	%rax, %rdi	# tmp92,
	call	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED1Ev	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:134:       }
	jmp	.L56	#
.L55:
	movq	%rax, %rbx	#, tmp94
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:130:         _M_start_thread(_S_make_state(
	leaq	-40(%rbp), %rax	#, tmp93
	movq	%rax, %rdi	# tmp93,
	call	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED1Ev	#
	movq	%rbx, %rax	# tmp94, D.80659
	movq	%rax, %rdi	# D.80659,
.LEHB11:
	call	_Unwind_Resume	#
.LEHE11:
.L56:
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:134:       }
	addq	$56, %rsp	#,
	popq	%rbx	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4340:
	.section	.gcc_except_table
.LLSDA4340:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE4340-.LLSDACSB4340
.LLSDACSB4340:
	.uleb128 .LEHB9-.LFB4340
	.uleb128 .LEHE9-.LEHB9
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB10-.LFB4340
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L55-.LFB4340
	.uleb128 0
	.uleb128 .LEHB11-.LFB4340
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
.LLSDACSE4340:
	.section	.text._ZNSt6threadC2IRFvvEJEvEEOT_DpOT0_,"axG",@progbits,_ZNSt6threadC5IRFvvEJEvEEOT_DpOT0_,comdat
	.size	_ZNSt6threadC2IRFvvEJEvEEOT_DpOT0_, .-_ZNSt6threadC2IRFvvEJEvEEOT_DpOT0_
	.weak	_ZNSt6threadC1IRFvvEJEvEEOT_DpOT0_
	.set	_ZNSt6threadC1IRFvvEJEvEEOT_DpOT0_,_ZNSt6threadC2IRFvvEJEvEEOT_DpOT0_
	.section	.text._ZSt7forwardIRFvvEEOT_RNSt16remove_referenceIS2_E4typeE,"axG",@progbits,_ZSt7forwardIRFvvEEOT_RNSt16remove_referenceIS2_E4typeE,comdat
	.weak	_ZSt7forwardIRFvvEEOT_RNSt16remove_referenceIS2_E4typeE
	.type	_ZSt7forwardIRFvvEEOT_RNSt16remove_referenceIS2_E4typeE, @function
_ZSt7forwardIRFvvEEOT_RNSt16remove_referenceIS2_E4typeE:
.LFB4471:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:75:     { return static_cast<_Tp&&>(__t); }
	movq	-8(%rbp), %rax	# __t, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:75:     { return static_cast<_Tp&&>(__t); }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4471:
	.size	_ZSt7forwardIRFvvEEOT_RNSt16remove_referenceIS2_E4typeE, .-_ZSt7forwardIRFvvEEOT_RNSt16remove_referenceIS2_E4typeE
	.section	.text._ZNSt5tupleIJPFvvEEEC2EOS2_,"axG",@progbits,_ZNSt5tupleIJPFvvEEEC5EOS2_,comdat
	.align 2
	.weak	_ZNSt5tupleIJPFvvEEEC2EOS2_
	.type	_ZNSt5tupleIJPFvvEEEC2EOS2_, @function
_ZNSt5tupleIJPFvvEEEC2EOS2_:
.LFB4488:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
	movq	%rsi, -16(%rbp)	# D.76726, D.76726
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:642:       constexpr tuple(tuple&&) = default;
	movq	-8(%rbp), %rax	# this, _1
	movq	-16(%rbp), %rdx	# D.76726, _2
	movq	%rdx, %rsi	# _2,
	movq	%rax, %rdi	# _1,
	call	_ZNSt11_Tuple_implILm0EJPFvvEEEC2EOS2_	#
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4488:
	.size	_ZNSt5tupleIJPFvvEEEC2EOS2_, .-_ZNSt5tupleIJPFvvEEEC2EOS2_
	.weak	_ZNSt5tupleIJPFvvEEEC1EOS2_
	.set	_ZNSt5tupleIJPFvvEEEC1EOS2_,_ZNSt5tupleIJPFvvEEEC2EOS2_
	.section	.text._ZNSt5tupleIJPFvvEEEC2IvLb1EEERKS1_,"axG",@progbits,_ZNSt5tupleIJPFvvEEEC5IvLb1EEERKS1_,comdat
	.align 2
	.weak	_ZNSt5tupleIJPFvvEEEC2IvLb1EEERKS1_
	.type	_ZNSt5tupleIJPFvvEEEC2IvLb1EEERKS1_, @function
_ZNSt5tupleIJPFvvEEEC2IvLb1EEERKS1_:
.LFB4491:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
	movq	%rsi, -16(%rbp)	# __elements#0, __elements#0
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:589:       : _Inherited(__elements...) { }
	movq	-8(%rbp), %rax	# this, _1
	movq	-16(%rbp), %rdx	# __elements#0, tmp83
	movq	%rdx, %rsi	# tmp83,
	movq	%rax, %rdi	# _1,
	call	_ZNSt11_Tuple_implILm0EJPFvvEEEC2ERKS1_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:589:       : _Inherited(__elements...) { }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4491:
	.size	_ZNSt5tupleIJPFvvEEEC2IvLb1EEERKS1_, .-_ZNSt5tupleIJPFvvEEEC2IvLb1EEERKS1_
	.weak	_ZNSt5tupleIJPFvvEEEC1IvLb1EEERKS1_
	.set	_ZNSt5tupleIJPFvvEEEC1IvLb1EEERKS1_,_ZNSt5tupleIJPFvvEEEC2IvLb1EEERKS1_
	.section	.text._ZNSt11_Tuple_implILm0EJPFvvEEEC2ERKS1_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPFvvEEEC5ERKS1_,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm0EJPFvvEEEC2ERKS1_
	.type	_ZNSt11_Tuple_implILm0EJPFvvEEEC2ERKS1_, @function
_ZNSt11_Tuple_implILm0EJPFvvEEEC2ERKS1_:
.LFB4494:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
	movq	%rsi, -16(%rbp)	# __head, __head
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:344:       : _Base(__head) { }
	movq	-8(%rbp), %rax	# this, _1
	movq	-16(%rbp), %rdx	# __head, tmp83
	movq	%rdx, %rsi	# tmp83,
	movq	%rax, %rdi	# _1,
	call	_ZNSt10_Head_baseILm0EPFvvELb0EEC2ERKS1_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:344:       : _Base(__head) { }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4494:
	.size	_ZNSt11_Tuple_implILm0EJPFvvEEEC2ERKS1_, .-_ZNSt11_Tuple_implILm0EJPFvvEEEC2ERKS1_
	.weak	_ZNSt11_Tuple_implILm0EJPFvvEEEC1ERKS1_
	.set	_ZNSt11_Tuple_implILm0EJPFvvEEEC1ERKS1_,_ZNSt11_Tuple_implILm0EJPFvvEEEC2ERKS1_
	.section	.text._ZNSt10_Head_baseILm0EPFvvELb0EEC2ERKS1_,"axG",@progbits,_ZNSt10_Head_baseILm0EPFvvELb0EEC5ERKS1_,comdat
	.align 2
	.weak	_ZNSt10_Head_baseILm0EPFvvELb0EEC2ERKS1_
	.type	_ZNSt10_Head_baseILm0EPFvvELb0EEC2ERKS1_, @function
_ZNSt10_Head_baseILm0EPFvvELb0EEC2ERKS1_:
.LFB4497:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# this, this
	movq	%rsi, -16(%rbp)	# __h, __h
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:126:       : _M_head_impl(__h) { }
	movq	-16(%rbp), %rax	# __h, tmp83
	movq	(%rax), %rdx	# *__h_5(D), _1
	movq	-8(%rbp), %rax	# this, tmp84
	movq	%rdx, (%rax)	# _1, this_3(D)->_M_head_impl
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:126:       : _M_head_impl(__h) { }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4497:
	.size	_ZNSt10_Head_baseILm0EPFvvELb0EEC2ERKS1_, .-_ZNSt10_Head_baseILm0EPFvvELb0EEC2ERKS1_
	.weak	_ZNSt10_Head_baseILm0EPFvvELb0EEC1ERKS1_
	.set	_ZNSt10_Head_baseILm0EPFvvELb0EEC1ERKS1_,_ZNSt10_Head_baseILm0EPFvvELb0EEC2ERKS1_
	.section	.text._ZNSt6thread14__make_invokerIRFvvEJEEENS_8_InvokerISt5tupleIJNSt5decayIT_E4typeEDpNS5_IT0_E4typeEEEEEOS6_DpOS9_,"axG",@progbits,_ZNSt6thread14__make_invokerIRFvvEJEEENS_8_InvokerISt5tupleIJNSt5decayIT_E4typeEDpNS5_IT0_E4typeEEEEEOS6_DpOS9_,comdat
	.weak	_ZNSt6thread14__make_invokerIRFvvEJEEENS_8_InvokerISt5tupleIJNSt5decayIT_E4typeEDpNS5_IT0_E4typeEEEEEOS6_DpOS9_
	.type	_ZNSt6thread14__make_invokerIRFvvEJEEENS_8_InvokerISt5tupleIJNSt5decayIT_E4typeEDpNS5_IT0_E4typeEEEEEOS6_DpOS9_, @function
_ZNSt6thread14__make_invokerIRFvvEJEEENS_8_InvokerISt5tupleIJNSt5decayIT_E4typeEDpNS5_IT0_E4typeEEEEEOS6_DpOS9_:
.LFB4472:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%rbx	#
	subq	$40, %rsp	#,
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)	# .result_ptr, .result_ptr
	movq	%rsi, -48(%rbp)	# __callable, __callable
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:267: 	} };
	movq	-40(%rbp), %rbx	# <retval>, _1
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:266: 	    std::forward<_Callable>(__callable), std::forward<_Args>(__args)...
	movq	-48(%rbp), %rax	# __callable, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZSt7forwardIRFvvEEOT_RNSt16remove_referenceIS2_E4typeE	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:267: 	} };
	movq	%rax, -24(%rbp)	# _2, D.77527
	leaq	-24(%rbp), %rax	#, tmp85
	movq	%rax, %rsi	# tmp85,
	movq	%rbx, %rdi	# _1,
	call	_ZNSt5tupleIJPFvvEEEC1IvLb1EEERKS1_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:268:       }
	movq	-40(%rbp), %rax	# <retval>,
	addq	$40, %rsp	#,
	popq	%rbx	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4472:
	.size	_ZNSt6thread14__make_invokerIRFvvEJEEENS_8_InvokerISt5tupleIJNSt5decayIT_E4typeEDpNS5_IT0_E4typeEEEEEOS6_DpOS9_, .-_ZNSt6thread14__make_invokerIRFvvEJEEENS_8_InvokerISt5tupleIJNSt5decayIT_E4typeEDpNS5_IT0_E4typeEEEEEOS6_DpOS9_
	.section	.text._ZNSt6thread13_S_make_stateINS_8_InvokerISt5tupleIJPFvvEEEEEEESt10unique_ptrINS_6_StateESt14default_deleteIS8_EEOT_,"axG",@progbits,_ZNSt6thread13_S_make_stateINS_8_InvokerISt5tupleIJPFvvEEEEEEESt10unique_ptrINS_6_StateESt14default_deleteIS8_EEOT_,comdat
	.weak	_ZNSt6thread13_S_make_stateINS_8_InvokerISt5tupleIJPFvvEEEEEEESt10unique_ptrINS_6_StateESt14default_deleteIS8_EEOT_
	.type	_ZNSt6thread13_S_make_stateINS_8_InvokerISt5tupleIJPFvvEEEEEEESt10unique_ptrINS_6_StateESt14default_deleteIS8_EEOT_, @function
_ZNSt6thread13_S_make_stateINS_8_InvokerISt5tupleIJPFvvEEEEEEESt10unique_ptrINS_6_StateESt14default_deleteIS8_EEOT_:
.LFB4499:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%r12	#
	pushq	%rbx	#
	subq	$16, %rsp	#,
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)	# .result_ptr, .result_ptr
	movq	%rsi, -32(%rbp)	# __f, __f
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:206: 	return _State_ptr{new _Impl{std::forward<_Callable>(__f)}};
	movq	-32(%rbp), %rax	# __f, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZSt7forwardINSt6thread8_InvokerISt5tupleIJPFvvEEEEEEOT_RNSt16remove_referenceIS7_E4typeE	#
	movq	%rax, %r12	#, _4
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:206: 	return _State_ptr{new _Impl{std::forward<_Callable>(__f)}};
	movl	$16, %edi	#,
	call	_Znwm	#
	movq	%rax, %rbx	# tmp85, _6
	movq	%r12, %rsi	# _4,
	movq	%rbx, %rdi	# _6,
	call	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC1EOS6_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:206: 	return _State_ptr{new _Impl{std::forward<_Callable>(__f)}};
	movq	-24(%rbp), %rax	# <retval>, tmp86
	movq	%rbx, %rsi	# _6,
	movq	%rax, %rdi	# tmp86,
	call	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC1IS3_vEEPS1_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:207:       }
	movq	-24(%rbp), %rax	# <retval>,
	addq	$16, %rsp	#,
	popq	%rbx	#
	popq	%r12	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4499:
	.size	_ZNSt6thread13_S_make_stateINS_8_InvokerISt5tupleIJPFvvEEEEEEESt10unique_ptrINS_6_StateESt14default_deleteIS8_EEOT_, .-_ZNSt6thread13_S_make_stateINS_8_InvokerISt5tupleIJPFvvEEEEEEESt10unique_ptrINS_6_StateESt14default_deleteIS8_EEOT_
	.section	.text._ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED2Ev,"axG",@progbits,_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED5Ev,comdat
	.align 2
	.weak	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED2Ev
	.type	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED2Ev, @function
_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED2Ev:
.LFB4509:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%rbx	#
	subq	$40, %rsp	#,
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:282: 	auto& __ptr = _M_t._M_ptr();
	movq	-40(%rbp), %rax	# this, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE6_M_ptrEv	#
	movq	%rax, -24(%rbp)	# tmp87, __ptr
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:283: 	if (__ptr != nullptr)
	movq	-24(%rbp), %rax	# __ptr, tmp88
	movq	(%rax), %rax	# *__ptr_10, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:283: 	if (__ptr != nullptr)
	testq	%rax, %rax	# _2
	je	.L68	#,
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:284: 	  get_deleter()(std::move(__ptr));
	movq	-40(%rbp), %rax	# this, tmp89
	movq	%rax, %rdi	# tmp89,
	call	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EE11get_deleterEv	#
	movq	%rax, %rbx	#, _3
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:284: 	  get_deleter()(std::move(__ptr));
	movq	-24(%rbp), %rax	# __ptr, tmp90
	movq	%rax, %rdi	# tmp90,
	call	_ZSt4moveIRPNSt6thread6_StateEEONSt16remove_referenceIT_E4typeEOS5_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:284: 	  get_deleter()(std::move(__ptr));
	movq	(%rax), %rax	# *_4, _5
	movq	%rax, %rsi	# _5,
	movq	%rbx, %rdi	# _3,
	call	_ZNKSt14default_deleteINSt6thread6_StateEEclEPS1_	#
.L68:
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:285: 	__ptr = pointer();
	movq	-24(%rbp), %rax	# __ptr, tmp91
	movq	$0, (%rax)	#, *__ptr_10
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:286:       }
	nop	
	addq	$40, %rsp	#,
	popq	%rbx	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4509:
	.size	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED2Ev, .-_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED2Ev
	.weak	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED1Ev
	.set	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED1Ev,_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EED2Ev
	.section	.text._ZNSt11_Tuple_implILm0EJPFvvEEEC2EOS2_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPFvvEEEC5EOS2_,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm0EJPFvvEEEC2EOS2_
	.type	_ZNSt11_Tuple_implILm0EJPFvvEEEC2EOS2_, @function
_ZNSt11_Tuple_implILm0EJPFvvEEEC2EOS2_:
.LFB4554:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%rbx	#
	subq	$24, %rsp	#,
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)	# this, this
	movq	%rsi, -32(%rbp)	# __in, __in
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:360:       : _Base(std::forward<_Head>(_M_head(__in))) { }
	movq	-24(%rbp), %rbx	# this, _1
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:360:       : _Base(std::forward<_Head>(_M_head(__in))) { }
	movq	-32(%rbp), %rax	# __in, tmp85
	movq	%rax, %rdi	# tmp85,
	call	_ZNSt11_Tuple_implILm0EJPFvvEEE7_M_headERS2_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:360:       : _Base(std::forward<_Head>(_M_head(__in))) { }
	movq	%rax, %rdi	# _2,
	call	_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE	#
	movq	%rax, %rsi	# _3,
	movq	%rbx, %rdi	# _1,
	call	_ZNSt10_Head_baseILm0EPFvvELb0EEC2IS1_EEOT_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:360:       : _Base(std::forward<_Head>(_M_head(__in))) { }
	nop	
	addq	$24, %rsp	#,
	popq	%rbx	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4554:
	.size	_ZNSt11_Tuple_implILm0EJPFvvEEEC2EOS2_, .-_ZNSt11_Tuple_implILm0EJPFvvEEEC2EOS2_
	.weak	_ZNSt11_Tuple_implILm0EJPFvvEEEC1EOS2_
	.set	_ZNSt11_Tuple_implILm0EJPFvvEEEC1EOS2_,_ZNSt11_Tuple_implILm0EJPFvvEEEC2EOS2_
	.section	.text._ZSt7forwardINSt6thread8_InvokerISt5tupleIJPFvvEEEEEEOT_RNSt16remove_referenceIS7_E4typeE,"axG",@progbits,_ZSt7forwardINSt6thread8_InvokerISt5tupleIJPFvvEEEEEEOT_RNSt16remove_referenceIS7_E4typeE,comdat
	.weak	_ZSt7forwardINSt6thread8_InvokerISt5tupleIJPFvvEEEEEEOT_RNSt16remove_referenceIS7_E4typeE
	.type	_ZSt7forwardINSt6thread8_InvokerISt5tupleIJPFvvEEEEEEOT_RNSt16remove_referenceIS7_E4typeE, @function
_ZSt7forwardINSt6thread8_InvokerISt5tupleIJPFvvEEEEEEOT_RNSt16remove_referenceIS7_E4typeE:
.LFB4556:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:75:     { return static_cast<_Tp&&>(__t); }
	movq	-8(%rbp), %rax	# __t, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:75:     { return static_cast<_Tp&&>(__t); }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4556:
	.size	_ZSt7forwardINSt6thread8_InvokerISt5tupleIJPFvvEEEEEEOT_RNSt16remove_referenceIS7_E4typeE, .-_ZSt7forwardINSt6thread8_InvokerISt5tupleIJPFvvEEEEEEOT_RNSt16remove_referenceIS7_E4typeE
	.section	.text._ZNSt6thread6_StateC2Ev,"axG",@progbits,_ZNSt6thread6_StateC5Ev,comdat
	.align 2
	.weak	_ZNSt6thread6_StateC2Ev
	.type	_ZNSt6thread6_StateC2Ev, @function
_ZNSt6thread6_StateC2Ev:
.LFB4559:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:67:     struct _State
	movl	$_ZTVNSt6thread6_StateE+16, %edx	#, _1
	movq	-8(%rbp), %rax	# this, tmp83
	movq	%rdx, (%rax)	# _1, this_3(D)->_vptr._State
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4559:
	.size	_ZNSt6thread6_StateC2Ev, .-_ZNSt6thread6_StateC2Ev
	.weak	_ZNSt6thread6_StateC1Ev
	.set	_ZNSt6thread6_StateC1Ev,_ZNSt6thread6_StateC2Ev
	.section	.text._ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC2EOS5_,"axG",@progbits,_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC5EOS5_,comdat
	.align 2
	.weak	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC2EOS5_
	.type	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC2EOS5_, @function
_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC2EOS5_:
.LFB4562:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
	movq	%rsi, -16(%rbp)	# D.77886, D.77886
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:230:       struct _Invoker
	movq	-8(%rbp), %rax	# this, _1
	movq	-16(%rbp), %rdx	# D.77886, _2
	movq	%rdx, %rsi	# _2,
	movq	%rax, %rdi	# _1,
	call	_ZNSt5tupleIJPFvvEEEC1EOS2_	#
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4562:
	.size	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC2EOS5_, .-_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC2EOS5_
	.weak	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC1EOS5_
	.set	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC1EOS5_,_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC2EOS5_
	.section	.text._ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC2EOS6_,"axG",@progbits,_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC5EOS6_,comdat
	.align 2
	.weak	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC2EOS6_
	.type	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC2EOS6_, @function
_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC2EOS6_:
.LFB4564:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%rbx	#
	subq	$24, %rsp	#,
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)	# this, this
	movq	%rsi, -32(%rbp)	# __f, __f
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:191: 	_State_impl(_Callable&& __f) : _M_func(std::forward<_Callable>(__f))
	movq	-24(%rbp), %rax	# this, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt6thread6_StateC2Ev	#
	movl	$_ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE+16, %edx	#, _2
	movq	-24(%rbp), %rax	# this, tmp87
	movq	%rdx, (%rax)	# _2, this_7(D)->D.77780._vptr._State
	movq	-24(%rbp), %rax	# this, tmp88
	leaq	8(%rax), %rbx	#, _3
	movq	-32(%rbp), %rax	# __f, tmp89
	movq	%rax, %rdi	# tmp89,
	call	_ZSt7forwardINSt6thread8_InvokerISt5tupleIJPFvvEEEEEEOT_RNSt16remove_referenceIS7_E4typeE	#
	movq	%rax, %rsi	# _4,
	movq	%rbx, %rdi	# _3,
	call	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEC1EOS5_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:192: 	{ }
	nop	
	addq	$24, %rsp	#,
	popq	%rbx	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4564:
	.size	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC2EOS6_, .-_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC2EOS6_
	.weak	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC1EOS6_
	.set	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC1EOS6_,_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEC2EOS6_
	.section	.text._ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC2IS3_vEEPS1_,"axG",@progbits,_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC5IS3_vEEPS1_,comdat
	.align 2
	.weak	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC2IS3_vEEPS1_
	.type	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC2IS3_vEEPS1_, @function
_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC2IS3_vEEPS1_:
.LFB4567:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA4567
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
	movq	%rsi, -16(%rbp)	# __p, __p
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:204: 	: _M_t(__p)
	movq	-8(%rbp), %rax	# this, _1
	movq	-16(%rbp), %rdx	# __p, tmp83
	movq	%rdx, %rsi	# tmp83,
	movq	%rax, %rdi	# _1,
	call	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC1EPS1_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:205:         { }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4567:
	.section	.gcc_except_table
.LLSDA4567:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE4567-.LLSDACSB4567
.LLSDACSB4567:
.LLSDACSE4567:
	.section	.text._ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC2IS3_vEEPS1_,"axG",@progbits,_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC5IS3_vEEPS1_,comdat
	.size	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC2IS3_vEEPS1_, .-_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC2IS3_vEEPS1_
	.weak	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC1IS3_vEEPS1_
	.set	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC1IS3_vEEPS1_,_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EEC2IS3_vEEPS1_
	.section	.text._ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE6_M_ptrEv,"axG",@progbits,_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE6_M_ptrEv,comdat
	.align 2
	.weak	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE6_M_ptrEv
	.type	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE6_M_ptrEv, @function
_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE6_M_ptrEv:
.LFB4569:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:153:       pointer&   _M_ptr() { return std::get<0>(_M_t); }
	movq	-8(%rbp), %rax	# this, _1
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:153:       pointer&   _M_ptr() { return std::get<0>(_M_t); }
	movq	%rax, %rdi	# _1,
	call	_ZSt3getILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:153:       pointer&   _M_ptr() { return std::get<0>(_M_t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4569:
	.size	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE6_M_ptrEv, .-_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE6_M_ptrEv
	.section	.text._ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EE11get_deleterEv,"axG",@progbits,_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EE11get_deleterEv,comdat
	.align 2
	.weak	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EE11get_deleterEv
	.type	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EE11get_deleterEv, @function
_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EE11get_deleterEv:
.LFB4570:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:358:       { return _M_t._M_deleter(); }
	movq	-8(%rbp), %rax	# this, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE10_M_deleterEv	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:358:       { return _M_t._M_deleter(); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4570:
	.size	_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EE11get_deleterEv, .-_ZNSt10unique_ptrINSt6thread6_StateESt14default_deleteIS1_EE11get_deleterEv
	.section	.text._ZSt4moveIRPNSt6thread6_StateEEONSt16remove_referenceIT_E4typeEOS5_,"axG",@progbits,_ZSt4moveIRPNSt6thread6_StateEEONSt16remove_referenceIT_E4typeEOS5_,comdat
	.weak	_ZSt4moveIRPNSt6thread6_StateEEONSt16remove_referenceIT_E4typeEOS5_
	.type	_ZSt4moveIRPNSt6thread6_StateEEONSt16remove_referenceIT_E4typeEOS5_, @function
_ZSt4moveIRPNSt6thread6_StateEEONSt16remove_referenceIT_E4typeEOS5_:
.LFB4571:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:100:     { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
	movq	-8(%rbp), %rax	# __t, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:100:     { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4571:
	.size	_ZSt4moveIRPNSt6thread6_StateEEONSt16remove_referenceIT_E4typeEOS5_, .-_ZSt4moveIRPNSt6thread6_StateEEONSt16remove_referenceIT_E4typeEOS5_
	.section	.text._ZNKSt14default_deleteINSt6thread6_StateEEclEPS1_,"axG",@progbits,_ZNKSt14default_deleteINSt6thread6_StateEEclEPS1_,comdat
	.align 2
	.weak	_ZNKSt14default_deleteINSt6thread6_StateEEclEPS1_
	.type	_ZNKSt14default_deleteINSt6thread6_StateEEclEPS1_, @function
_ZNKSt14default_deleteINSt6thread6_StateEEclEPS1_:
.LFB4572:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
	movq	%rsi, -16(%rbp)	# __ptr, __ptr
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:81: 	delete __ptr;
	movq	-16(%rbp), %rax	# __ptr, __ptr.25_6
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:81: 	delete __ptr;
	testq	%rax, %rax	# __ptr.25_6
	je	.L84	#,
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:81: 	delete __ptr;
	movq	(%rax), %rdx	# __ptr.25_6->_vptr._State, _1
	addq	$8, %rdx	#, _2
	movq	(%rdx), %rdx	# *_2, _3
	movq	%rax, %rdi	# __ptr.25_6,
	call	*%rdx	# _3
.L84:
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:82:       }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4572:
	.size	_ZNKSt14default_deleteINSt6thread6_StateEEclEPS1_, .-_ZNKSt14default_deleteINSt6thread6_StateEEclEPS1_
	.section	.text._ZNSt11_Tuple_implILm0EJPFvvEEE7_M_headERS2_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPFvvEEE7_M_headERS2_,comdat
	.weak	_ZNSt11_Tuple_implILm0EJPFvvEEE7_M_headERS2_
	.type	_ZNSt11_Tuple_implILm0EJPFvvEEE7_M_headERS2_, @function
_ZNSt11_Tuple_implILm0EJPFvvEEE7_M_headERS2_:
.LFB4613:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:334:       _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }
	movq	-8(%rbp), %rax	# __t, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt10_Head_baseILm0EPFvvELb0EE7_M_headERS2_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:334:       _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4613:
	.size	_ZNSt11_Tuple_implILm0EJPFvvEEE7_M_headERS2_, .-_ZNSt11_Tuple_implILm0EJPFvvEEE7_M_headERS2_
	.section	.text._ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE,"axG",@progbits,_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE,comdat
	.weak	_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE
	.type	_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE, @function
_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE:
.LFB4614:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:75:     { return static_cast<_Tp&&>(__t); }
	movq	-8(%rbp), %rax	# __t, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:75:     { return static_cast<_Tp&&>(__t); }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4614:
	.size	_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE, .-_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE
	.section	.text._ZNSt10_Head_baseILm0EPFvvELb0EEC2IS1_EEOT_,"axG",@progbits,_ZNSt10_Head_baseILm0EPFvvELb0EEC5IS1_EEOT_,comdat
	.align 2
	.weak	_ZNSt10_Head_baseILm0EPFvvELb0EEC2IS1_EEOT_
	.type	_ZNSt10_Head_baseILm0EPFvvELb0EEC2IS1_EEOT_, @function
_ZNSt10_Head_baseILm0EPFvvELb0EEC2IS1_EEOT_:
.LFB4616:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
	movq	%rsi, -16(%rbp)	# __h, __h
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:133: 	: _M_head_impl(std::forward<_UHead>(__h)) { }
	movq	-16(%rbp), %rax	# __h, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:133: 	: _M_head_impl(std::forward<_UHead>(__h)) { }
	movq	(%rax), %rdx	# *_1, _2
	movq	-8(%rbp), %rax	# this, tmp85
	movq	%rdx, (%rax)	# _2, this_4(D)->_M_head_impl
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:133: 	: _M_head_impl(std::forward<_UHead>(__h)) { }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4616:
	.size	_ZNSt10_Head_baseILm0EPFvvELb0EEC2IS1_EEOT_, .-_ZNSt10_Head_baseILm0EPFvvELb0EEC2IS1_EEOT_
	.weak	_ZNSt10_Head_baseILm0EPFvvELb0EEC1IS1_EEOT_
	.set	_ZNSt10_Head_baseILm0EPFvvELb0EEC1IS1_EEOT_,_ZNSt10_Head_baseILm0EPFvvELb0EEC2IS1_EEOT_
	.section	.text._ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC2EPS1_,"axG",@progbits,_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC5EPS1_,comdat
	.align 2
	.weak	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC2EPS1_
	.type	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC2EPS1_, @function
_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC2EPS1_:
.LFB4619:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
	movq	%rsi, -16(%rbp)	# __p, __p
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:147:       __uniq_ptr_impl(pointer __p) : _M_t() { _M_ptr() = __p; }
	movq	-8(%rbp), %rax	# this, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC1IS2_S4_Lb1EEEv	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:147:       __uniq_ptr_impl(pointer __p) : _M_t() { _M_ptr() = __p; }
	movq	-8(%rbp), %rax	# this, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE6_M_ptrEv	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:147:       __uniq_ptr_impl(pointer __p) : _M_t() { _M_ptr() = __p; }
	movq	-16(%rbp), %rdx	# __p, tmp85
	movq	%rdx, (%rax)	# tmp85, *_2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:147:       __uniq_ptr_impl(pointer __p) : _M_t() { _M_ptr() = __p; }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4619:
	.size	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC2EPS1_, .-_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC2EPS1_
	.weak	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC1EPS1_
	.set	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC1EPS1_,_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EEC2EPS1_
	.section	.text._ZSt3getILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_,"axG",@progbits,_ZSt3getILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_,comdat
	.weak	_ZSt3getILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_
	.type	_ZSt3getILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_, @function
_ZSt3getILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_:
.LFB4621:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1321:     { return std::__get_helper<__i>(__t); }
	movq	-8(%rbp), %rax	# __t, _1
	movq	%rax, %rdi	# _1,
	call	_ZSt12__get_helperILm0EPNSt6thread6_StateEJSt14default_deleteIS1_EEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1321:     { return std::__get_helper<__i>(__t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4621:
	.size	_ZSt3getILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_, .-_ZSt3getILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_
	.section	.text._ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE10_M_deleterEv,"axG",@progbits,_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE10_M_deleterEv,comdat
	.align 2
	.weak	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE10_M_deleterEv
	.type	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE10_M_deleterEv, @function
_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE10_M_deleterEv:
.LFB4622:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:155:       _Dp&       _M_deleter() { return std::get<1>(_M_t); }
	movq	-8(%rbp), %rax	# this, _1
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:155:       _Dp&       _M_deleter() { return std::get<1>(_M_t); }
	movq	%rax, %rdi	# _1,
	call	_ZSt3getILm1EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/unique_ptr.h:155:       _Dp&       _M_deleter() { return std::get<1>(_M_t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4622:
	.size	_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE10_M_deleterEv, .-_ZNSt15__uniq_ptr_implINSt6thread6_StateESt14default_deleteIS1_EE10_M_deleterEv
	.section	.text._ZNSt10_Head_baseILm0EPFvvELb0EE7_M_headERS2_,"axG",@progbits,_ZNSt10_Head_baseILm0EPFvvELb0EE7_M_headERS2_,comdat
	.weak	_ZNSt10_Head_baseILm0EPFvvELb0EE7_M_headERS2_
	.type	_ZNSt10_Head_baseILm0EPFvvELb0EE7_M_headERS2_, @function
_ZNSt10_Head_baseILm0EPFvvELb0EE7_M_headERS2_:
.LFB4657:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __b, __b
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:160:       _M_head(_Head_base& __b) noexcept { return __b._M_head_impl; }
	movq	-8(%rbp), %rax	# __b, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:160:       _M_head(_Head_base& __b) noexcept { return __b._M_head_impl; }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4657:
	.size	_ZNSt10_Head_baseILm0EPFvvELb0EE7_M_headERS2_, .-_ZNSt10_Head_baseILm0EPFvvELb0EE7_M_headERS2_
	.section	.text._ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC2IS2_S4_Lb1EEEv,"axG",@progbits,_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC5IS2_S4_Lb1EEEv,comdat
	.align 2
	.weak	_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC2IS2_S4_Lb1EEEv
	.type	_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC2IS2_S4_Lb1EEEv, @function
_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC2IS2_S4_Lb1EEEv:
.LFB4659:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:919: 	: _Inherited() { }
	movq	-8(%rbp), %rax	# this, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC2Ev	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:919: 	: _Inherited() { }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4659:
	.size	_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC2IS2_S4_Lb1EEEv, .-_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC2IS2_S4_Lb1EEEv
	.weak	_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC1IS2_S4_Lb1EEEv
	.set	_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC1IS2_S4_Lb1EEEv,_ZNSt5tupleIJPNSt6thread6_StateESt14default_deleteIS1_EEEC2IS2_S4_Lb1EEEv
	.section	.text._ZSt12__get_helperILm0EPNSt6thread6_StateEJSt14default_deleteIS1_EEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm0EPNSt6thread6_StateEJSt14default_deleteIS1_EEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE,comdat
	.weak	_ZSt12__get_helperILm0EPNSt6thread6_StateEJSt14default_deleteIS1_EEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE
	.type	_ZSt12__get_helperILm0EPNSt6thread6_StateEJSt14default_deleteIS1_EEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE, @function
_ZSt12__get_helperILm0EPNSt6thread6_StateEJSt14default_deleteIS1_EEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE:
.LFB4661:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1310:     { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }
	movq	-8(%rbp), %rax	# __t, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEE7_M_headERS5_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1310:     { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4661:
	.size	_ZSt12__get_helperILm0EPNSt6thread6_StateEJSt14default_deleteIS1_EEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE, .-_ZSt12__get_helperILm0EPNSt6thread6_StateEJSt14default_deleteIS1_EEERT0_RSt11_Tuple_implIXT_EJS5_DpT1_EE
	.section	.text._ZSt3getILm1EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_,"axG",@progbits,_ZSt3getILm1EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_,comdat
	.weak	_ZSt3getILm1EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_
	.type	_ZSt3getILm1EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_, @function
_ZSt3getILm1EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_:
.LFB4662:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1321:     { return std::__get_helper<__i>(__t); }
	movq	-8(%rbp), %rax	# __t, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZSt12__get_helperILm1ESt14default_deleteINSt6thread6_StateEEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1321:     { return std::__get_helper<__i>(__t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4662:
	.size	_ZSt3getILm1EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_, .-_ZSt3getILm1EJPNSt6thread6_StateESt14default_deleteIS1_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS9_
	.section	.text._ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC2Ev,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC5Ev,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC2Ev
	.type	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC2Ev, @function
_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC2Ev:
.LFB4694:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:207:       : _Inherited(), _Base() { }
	movq	-8(%rbp), %rax	# this, tmp83
	movq	%rax, %rdi	# tmp83,
	call	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC2Ev	#
	movq	-8(%rbp), %rax	# this, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC2Ev	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:207:       : _Inherited(), _Base() { }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4694:
	.size	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC2Ev, .-_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC2Ev
	.weak	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC1Ev
	.set	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC1Ev,_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEEC2Ev
	.section	.text._ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEE7_M_headERS5_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEE7_M_headERS5_,comdat
	.weak	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEE7_M_headERS5_
	.type	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEE7_M_headERS5_, @function
_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEE7_M_headERS5_:
.LFB4696:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:195:       _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }
	movq	-8(%rbp), %rax	# __t, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EE7_M_headERS3_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:195:       _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4696:
	.size	_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEE7_M_headERS5_, .-_ZNSt11_Tuple_implILm0EJPNSt6thread6_StateESt14default_deleteIS1_EEE7_M_headERS5_
	.section	.text._ZSt12__get_helperILm1ESt14default_deleteINSt6thread6_StateEEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm1ESt14default_deleteINSt6thread6_StateEEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE,comdat
	.weak	_ZSt12__get_helperILm1ESt14default_deleteINSt6thread6_StateEEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	.type	_ZSt12__get_helperILm1ESt14default_deleteINSt6thread6_StateEEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE, @function
_ZSt12__get_helperILm1ESt14default_deleteINSt6thread6_StateEEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE:
.LFB4697:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1310:     { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }
	movq	-8(%rbp), %rax	# __t, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEE7_M_headERS4_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1310:     { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4697:
	.size	_ZSt12__get_helperILm1ESt14default_deleteINSt6thread6_StateEEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE, .-_ZSt12__get_helperILm1ESt14default_deleteINSt6thread6_StateEEJEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	.section	.text._ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC2Ev,"axG",@progbits,_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC5Ev,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC2Ev
	.type	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC2Ev, @function
_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC2Ev:
.LFB4714:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:340:       : _Base() { }
	movq	-8(%rbp), %rax	# this, tmp82
	movq	%rax, %rdi	# tmp82,
	call	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC2Ev	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:340:       : _Base() { }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4714:
	.size	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC2Ev, .-_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC2Ev
	.weak	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC1Ev
	.set	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC1Ev,_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEEC2Ev
	.section	.text._ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC2Ev,"axG",@progbits,_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC5Ev,comdat
	.align 2
	.weak	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC2Ev
	.type	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC2Ev, @function
_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC2Ev:
.LFB4717:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:123:       : _M_head_impl() { }
	movq	-8(%rbp), %rax	# this, tmp82
	movq	$0, (%rax)	#, this_2(D)->_M_head_impl
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:123:       : _M_head_impl() { }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4717:
	.size	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC2Ev, .-_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC2Ev
	.weak	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC1Ev
	.set	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC1Ev,_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EEC2Ev
	.section	.text._ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EE7_M_headERS3_,"axG",@progbits,_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EE7_M_headERS3_,comdat
	.weak	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EE7_M_headERS3_
	.type	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EE7_M_headERS3_, @function
_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EE7_M_headERS3_:
.LFB4719:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __b, __b
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:160:       _M_head(_Head_base& __b) noexcept { return __b._M_head_impl; }
	movq	-8(%rbp), %rax	# __b, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:160:       _M_head(_Head_base& __b) noexcept { return __b._M_head_impl; }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4719:
	.size	_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EE7_M_headERS3_, .-_ZNSt10_Head_baseILm0EPNSt6thread6_StateELb0EE7_M_headERS3_
	.section	.text._ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEE7_M_headERS4_,"axG",@progbits,_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEE7_M_headERS4_,comdat
	.weak	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEE7_M_headERS4_
	.type	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEE7_M_headERS4_, @function
_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEE7_M_headERS4_:
.LFB4720:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:334:       _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }
	movq	-8(%rbp), %rax	# __t, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EE7_M_headERS4_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:334:       _M_head(_Tuple_impl& __t) noexcept { return _Base::_M_head(__t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4720:
	.size	_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEE7_M_headERS4_, .-_ZNSt11_Tuple_implILm1EJSt14default_deleteINSt6thread6_StateEEEE7_M_headERS4_
	.section	.text._ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC2Ev,"axG",@progbits,_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC5Ev,comdat
	.align 2
	.weak	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC2Ev
	.type	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC2Ev, @function
_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC2Ev:
.LFB4728:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:77:       : _Head() { }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4728:
	.size	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC2Ev, .-_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC2Ev
	.weak	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC1Ev
	.set	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC1Ev,_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EEC2Ev
	.section	.text._ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EE7_M_headERS4_,"axG",@progbits,_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EE7_M_headERS4_,comdat
	.weak	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EE7_M_headERS4_
	.type	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EE7_M_headERS4_, @function
_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EE7_M_headERS4_:
.LFB4730:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __b, __b
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:113:       _M_head(_Head_base& __b) noexcept { return __b; }
	movq	-8(%rbp), %rax	# __b, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:113:       _M_head(_Head_base& __b) noexcept { return __b; }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4730:
	.size	_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EE7_M_headERS4_, .-_ZNSt10_Head_baseILm1ESt14default_deleteINSt6thread6_StateEELb1EE7_M_headERS4_
	.weak	_ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE
	.section	.rodata._ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE,"aG",@progbits,_ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE,comdat
	.align 8
	.type	_ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE, @object
	.size	_ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE, 40
_ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE:
	.quad	0
	.quad	_ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE
	.quad	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED1Ev
	.quad	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED0Ev
	.quad	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEE6_M_runEv
	.section	.text._ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED2Ev,"axG",@progbits,_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED5Ev,comdat
	.align 2
	.weak	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED2Ev
	.type	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED2Ev, @function
_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED2Ev:
.LFB4734:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:187:       struct _State_impl : public _State
	movl	$_ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE+16, %edx	#, _1
	movq	-8(%rbp), %rax	# this, tmp84
	movq	%rdx, (%rax)	# _1, this_4(D)->D.77780._vptr._State
	movq	-8(%rbp), %rax	# this, _2
	movq	%rax, %rdi	# _2,
	call	_ZNSt6thread6_StateD2Ev	#
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4734:
	.size	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED2Ev, .-_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED2Ev
	.weak	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED1Ev
	.set	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED1Ev,_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED2Ev
	.section	.text._ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED0Ev,"axG",@progbits,_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED5Ev,comdat
	.align 2
	.weak	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED0Ev
	.type	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED0Ev, @function
_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED0Ev:
.LFB4736:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:187:       struct _State_impl : public _State
	movq	-8(%rbp), %rax	# this, tmp82
	movq	%rax, %rdi	# tmp82,
	call	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED1Ev	#
	movq	-8(%rbp), %rax	# this, tmp83
	movl	$16, %esi	#,
	movq	%rax, %rdi	# tmp83,
	call	_ZdlPvm	#
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4736:
	.size	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED0Ev, .-_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEED0Ev
	.weak	_ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE
	.section	.rodata._ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE,"aG",@progbits,_ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE,comdat
	.align 8
	.type	_ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE, @object
	.size	_ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE, 24
_ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE:
# <anonymous>:
# <anonymous>:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
# <anonymous>:
	.quad	_ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE
# <anonymous>:
	.quad	_ZTINSt6thread6_StateE
	.weak	_ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE
	.section	.rodata._ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE,"aG",@progbits,_ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE,comdat
	.align 32
	.type	_ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE, @object
	.size	_ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE, 59
_ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE:
	.string	"NSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEEE"
	.text
	.type	__tcf_0, @function
__tcf_0:
.LFB4754:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%rbx	#
	subq	$24, %rsp	#,
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)	# D.80097, D.80097
# main.cpp:46: std::string dataarray[1000]; //non-atomic data
	movl	$_Z9dataarrayB5cxx11+32000, %ebx	#, _1
.L120:
# main.cpp:46: std::string dataarray[1000]; //non-atomic data
	cmpq	$_Z9dataarrayB5cxx11, %rbx	#, _1
	je	.L118	#,
# main.cpp:46: std::string dataarray[1000]; //non-atomic data
	subq	$32, %rbx	#, _1
	movq	%rbx, %rdi	# _1,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev	#
	jmp	.L120	#
.L118:
# main.cpp:46: std::string dataarray[1000]; //non-atomic data
	addq	$24, %rsp	#,
	popq	%rbx	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4754:
	.size	__tcf_0, .-__tcf_0
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB4753:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%r12	#
	pushq	%rbx	#
	subq	$16, %rsp	#,
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movl	%edi, -20(%rbp)	# __initialize_p, __initialize_p
	movl	%esi, -24(%rbp)	# __priority, __priority
# main.cpp:86: }
	cmpl	$1, -20(%rbp)	#, __initialize_p
	jne	.L125	#,
# main.cpp:86: }
	cmpl	$65535, -24(%rbp)	#, __priority
	jne	.L125	#,
# /usr/local/gcc-9.2.0/include/c++/9.2.0/iostream:74:   static ios_base::Init __ioinit;
	movl	$_ZStL8__ioinit, %edi	#,
	call	_ZNSt8ios_base4InitC1Ev	#
	movl	$__dso_handle, %edx	#,
	movl	$_ZStL8__ioinit, %esi	#,
	movl	$_ZNSt8ios_base4InitD1Ev, %edi	#,
	call	__cxa_atexit	#
# main.cpp:46: std::string dataarray[1000]; //non-atomic data
	movl	$_Z9dataarrayB5cxx11, %eax	#, _13
	movl	$999, %ebx	#, _5
	movq	%rax, %r12	# _13, _4
.L124:
# main.cpp:46: std::string dataarray[1000]; //non-atomic data
	testq	%rbx, %rbx	# _5
	js	.L123	#,
# main.cpp:46: std::string dataarray[1000]; //non-atomic data
	movq	%r12, %rdi	# _4,
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev	#
	addq	$32, %r12	#, _4
	subq	$1, %rbx	#, _5
	jmp	.L124	#
.L123:
# main.cpp:46: std::string dataarray[1000]; //non-atomic data
	movl	$__dso_handle, %edx	#,
	movl	$0, %esi	#,
	movl	$__tcf_0, %edi	#,
	call	__cxa_atexit	#
.L125:
# main.cpp:86: }
	nop	
	addq	$16, %rsp	#,
	popq	%rbx	#
	popq	%r12	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4753:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.section	.text._ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEE6_M_runEv,"axG",@progbits,_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEE6_M_runEv,comdat
	.align 2
	.weak	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEE6_M_runEv
	.type	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEE6_M_runEv, @function
_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEE6_M_runEv:
.LFB4755:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:195: 	_M_run() { _M_func(); }
	movq	-8(%rbp), %rax	# this, tmp83
	addq	$8, %rax	#, _1
	movq	%rax, %rdi	# _1,
	call	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEclEv	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:195: 	_M_run() { _M_func(); }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4755:
	.size	_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEE6_M_runEv, .-_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFvvEEEEEE6_M_runEv
	.section	.text._ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEclEv,"axG",@progbits,_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEclEv,comdat
	.align 2
	.weak	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEclEv
	.type	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEclEv, @function
_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEclEv:
.LFB4756:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:251: 	  return _M_invoke(_Indices());
	movq	-24(%rbp), %rax	# this, tmp83
	movq	%rax, %rdi	# tmp83,
	call	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEE9_M_invokeIJLm0EEEEvSt12_Index_tupleIJXspT_EEE	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:252: 	}
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4756:
	.size	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEclEv, .-_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEEclEv
	.section	.text._ZNSt6thread8_InvokerISt5tupleIJPFvvEEEE9_M_invokeIJLm0EEEEvSt12_Index_tupleIJXspT_EEE,"axG",@progbits,_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEE9_M_invokeIJLm0EEEEvSt12_Index_tupleIJXspT_EEE,comdat
	.align 2
	.weak	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEE9_M_invokeIJLm0EEEEvSt12_Index_tupleIJXspT_EEE
	.type	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEE9_M_invokeIJLm0EEEEvSt12_Index_tupleIJXspT_EEE, @function
_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEE9_M_invokeIJLm0EEEEvSt12_Index_tupleIJXspT_EEE:
.LFB4757:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# this, this
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:244: 	  { return std::__invoke(std::get<_Ind>(std::move(_M_t))...); }
	movq	-8(%rbp), %rax	# this, _1
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:244: 	  { return std::__invoke(std::get<_Ind>(std::move(_M_t))...); }
	movq	%rax, %rdi	# _1,
	call	_ZSt4moveIRSt5tupleIJPFvvEEEEONSt16remove_referenceIT_E4typeEOS6_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:244: 	  { return std::__invoke(std::get<_Ind>(std::move(_M_t))...); }
	movq	%rax, %rdi	# _2,
	call	_ZSt3getILm0EJPFvvEEEONSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEOS6_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:244: 	  { return std::__invoke(std::get<_Ind>(std::move(_M_t))...); }
	movq	%rax, %rdi	# _3,
	call	_ZSt8__invokeIPFvvEJEENSt15__invoke_resultIT_JDpT0_EE4typeEOS3_DpOS4_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:244: 	  { return std::__invoke(std::get<_Ind>(std::move(_M_t))...); }
	nop	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/thread:244: 	  { return std::__invoke(std::get<_Ind>(std::move(_M_t))...); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4757:
	.size	_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEE9_M_invokeIJLm0EEEEvSt12_Index_tupleIJXspT_EEE, .-_ZNSt6thread8_InvokerISt5tupleIJPFvvEEEE9_M_invokeIJLm0EEEEvSt12_Index_tupleIJXspT_EEE
	.section	.text._ZSt4moveIRSt5tupleIJPFvvEEEEONSt16remove_referenceIT_E4typeEOS6_,"axG",@progbits,_ZSt4moveIRSt5tupleIJPFvvEEEEONSt16remove_referenceIT_E4typeEOS6_,comdat
	.weak	_ZSt4moveIRSt5tupleIJPFvvEEEEONSt16remove_referenceIT_E4typeEOS6_
	.type	_ZSt4moveIRSt5tupleIJPFvvEEEEONSt16remove_referenceIT_E4typeEOS6_, @function
_ZSt4moveIRSt5tupleIJPFvvEEEEONSt16remove_referenceIT_E4typeEOS6_:
.LFB4759:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:100:     { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
	movq	-8(%rbp), %rax	# __t, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:100:     { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4759:
	.size	_ZSt4moveIRSt5tupleIJPFvvEEEEONSt16remove_referenceIT_E4typeEOS6_, .-_ZSt4moveIRSt5tupleIJPFvvEEEEONSt16remove_referenceIT_E4typeEOS6_
	.section	.text._ZSt3getILm0EJPFvvEEEONSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEOS6_,"axG",@progbits,_ZSt3getILm0EJPFvvEEEONSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEOS6_,comdat
	.weak	_ZSt3getILm0EJPFvvEEEONSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEOS6_
	.type	_ZSt3getILm0EJPFvvEEEONSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEOS6_, @function
_ZSt3getILm0EJPFvvEEEONSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEOS6_:
.LFB4760:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1335:       return std::forward<__element_type&&>(std::get<__i>(__t));
	movq	-8(%rbp), %rax	# __t, tmp85
	movq	%rax, %rdi	# tmp85,
	call	_ZSt3getILm0EJPFvvEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1335:       return std::forward<__element_type&&>(std::get<__i>(__t));
	movq	%rax, %rdi	# _1,
	call	_ZSt7forwardIOPFvvEEOT_RNSt16remove_referenceIS3_E4typeE	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1336:     }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4760:
	.size	_ZSt3getILm0EJPFvvEEEONSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEOS6_, .-_ZSt3getILm0EJPFvvEEEONSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEOS6_
	.section	.text._ZSt8__invokeIPFvvEJEENSt15__invoke_resultIT_JDpT0_EE4typeEOS3_DpOS4_,"axG",@progbits,_ZSt8__invokeIPFvvEJEENSt15__invoke_resultIT_JDpT0_EE4typeEOS3_DpOS4_,comdat
	.weak	_ZSt8__invokeIPFvvEJEENSt15__invoke_resultIT_JDpT0_EE4typeEOS3_DpOS4_
	.type	_ZSt8__invokeIPFvvEJEENSt15__invoke_resultIT_JDpT0_EE4typeEOS3_DpOS4_, @function
_ZSt8__invokeIPFvvEJEENSt15__invoke_resultIT_JDpT0_EE4typeEOS3_DpOS4_:
.LFB4761:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# __fn, __fn
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/invoke.h:95:       return std::__invoke_impl<__type>(__tag{}, std::forward<_Callable>(__fn),
	movq	-24(%rbp), %rax	# __fn, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE	#
	movq	%rax, %rdi	# _1,
	call	_ZSt13__invoke_implIvPFvvEJEET_St14__invoke_otherOT0_DpOT1_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/invoke.h:96: 					std::forward<_Args>(__args)...);
	nop	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/invoke.h:97:     }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4761:
	.size	_ZSt8__invokeIPFvvEJEENSt15__invoke_resultIT_JDpT0_EE4typeEOS3_DpOS4_, .-_ZSt8__invokeIPFvvEJEENSt15__invoke_resultIT_JDpT0_EE4typeEOS3_DpOS4_
	.section	.text._ZSt3getILm0EJPFvvEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_,"axG",@progbits,_ZSt3getILm0EJPFvvEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_,comdat
	.weak	_ZSt3getILm0EJPFvvEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_
	.type	_ZSt3getILm0EJPFvvEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_, @function
_ZSt3getILm0EJPFvvEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_:
.LFB4762:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1321:     { return std::__get_helper<__i>(__t); }
	movq	-8(%rbp), %rax	# __t, _1
	movq	%rax, %rdi	# _1,
	call	_ZSt12__get_helperILm0EPFvvEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1321:     { return std::__get_helper<__i>(__t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4762:
	.size	_ZSt3getILm0EJPFvvEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_, .-_ZSt3getILm0EJPFvvEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_
	.section	.text._ZSt7forwardIOPFvvEEOT_RNSt16remove_referenceIS3_E4typeE,"axG",@progbits,_ZSt7forwardIOPFvvEEOT_RNSt16remove_referenceIS3_E4typeE,comdat
	.weak	_ZSt7forwardIOPFvvEEOT_RNSt16remove_referenceIS3_E4typeE
	.type	_ZSt7forwardIOPFvvEEOT_RNSt16remove_referenceIS3_E4typeE, @function
_ZSt7forwardIOPFvvEEOT_RNSt16remove_referenceIS3_E4typeE:
.LFB4763:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:75:     { return static_cast<_Tp&&>(__t); }
	movq	-8(%rbp), %rax	# __t, _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/move.h:75:     { return static_cast<_Tp&&>(__t); }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4763:
	.size	_ZSt7forwardIOPFvvEEOT_RNSt16remove_referenceIS3_E4typeE, .-_ZSt7forwardIOPFvvEEOT_RNSt16remove_referenceIS3_E4typeE
	.section	.text._ZSt13__invoke_implIvPFvvEJEET_St14__invoke_otherOT0_DpOT1_,"axG",@progbits,_ZSt13__invoke_implIvPFvvEJEET_St14__invoke_otherOT0_DpOT1_,comdat
	.weak	_ZSt13__invoke_implIvPFvvEJEET_St14__invoke_otherOT0_DpOT1_
	.type	_ZSt13__invoke_implIvPFvvEJEET_St14__invoke_otherOT0_DpOT1_, @function
_ZSt13__invoke_implIvPFvvEJEET_St14__invoke_otherOT0_DpOT1_:
.LFB4764:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __f, __f
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/invoke.h:60:     { return std::forward<_Fn>(__f)(std::forward<_Args>(__args)...); }
	movq	-8(%rbp), %rax	# __f, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZSt7forwardIPFvvEEOT_RNSt16remove_referenceIS2_E4typeE	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/invoke.h:60:     { return std::forward<_Fn>(__f)(std::forward<_Args>(__args)...); }
	movq	(%rax), %rax	# *_1, _2
	call	*%rax	# _2
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/invoke.h:60:     { return std::forward<_Fn>(__f)(std::forward<_Args>(__args)...); }
	nop	
# /usr/local/gcc-9.2.0/include/c++/9.2.0/bits/invoke.h:60:     { return std::forward<_Fn>(__f)(std::forward<_Args>(__args)...); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4764:
	.size	_ZSt13__invoke_implIvPFvvEJEET_St14__invoke_otherOT0_DpOT1_, .-_ZSt13__invoke_implIvPFvvEJEET_St14__invoke_otherOT0_DpOT1_
	.section	.text._ZSt12__get_helperILm0EPFvvEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm0EPFvvEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE,comdat
	.weak	_ZSt12__get_helperILm0EPFvvEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE
	.type	_ZSt12__get_helperILm0EPFvvEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE, @function
_ZSt12__get_helperILm0EPFvvEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE:
.LFB4765:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movq	%rdi, -8(%rbp)	# __t, __t
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1310:     { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }
	movq	-8(%rbp), %rax	# __t, tmp84
	movq	%rax, %rdi	# tmp84,
	call	_ZNSt11_Tuple_implILm0EJPFvvEEE7_M_headERS2_	#
# /usr/local/gcc-9.2.0/include/c++/9.2.0/tuple:1310:     { return _Tuple_impl<__i, _Head, _Tail...>::_M_head(__t); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4765:
	.size	_ZSt12__get_helperILm0EPFvvEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE, .-_ZSt12__get_helperILm0EPFvvEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE
	.text
	.type	_GLOBAL__sub_I__Z3ptrB5cxx11, @function
_GLOBAL__sub_I__Z3ptrB5cxx11:
.LFB4766:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# main.cpp:86: }
	movl	$65535, %esi	#,
	movl	$1, %edi	#,
	call	_Z41__static_initialization_and_destruction_0ii	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4766:
	.size	_GLOBAL__sub_I__Z3ptrB5cxx11, .-_GLOBAL__sub_I__Z3ptrB5cxx11
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3ptrB5cxx11
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
