/* Helper file for declaring TCG helper functions.
   This one expands generation functions for tcg opcodes.  */

#ifndef HELPER_GEN_H
#define HELPER_GEN_H 1

#include <exec/helper-head.h>

#define DEF_HELPER_FLAGS_0(name, flags, ret)                            \
static inline void glue(gen_helper_, name)(dh_retvar_decl0(ret))        \
{                                                                       \
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 0, NULL);       \
}

#define DEF_HELPER_FLAGS_1(name, flags, ret, t1)                        \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)          \
    dh_arg_decl(t1, 1))                                                 \
{                                                                       \
  TCGArg args[1] = { dh_arg(t1, 1) };                                   \
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 1, args);       \
}

#define DEF_HELPER_FLAGS_2(name, flags, ret, t1, t2)                    \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)          \
    dh_arg_decl(t1, 1), dh_arg_decl(t2, 2))                             \
{                                                                       \
  TCGArg args[2] = { dh_arg(t1, 1), dh_arg(t2, 2) };                    \
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 2, args);       \
}

#define DEF_HELPER_FLAGS_3(name, flags, ret, t1, t2, t3)                \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)          \
    dh_arg_decl(t1, 1), dh_arg_decl(t2, 2), dh_arg_decl(t3, 3))         \
{                                                                       \
  TCGArg args[3] = { dh_arg(t1, 1), dh_arg(t2, 2), dh_arg(t3, 3) };     \
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 3, args);       \
}

#define DEF_HELPER_FLAGS_4(name, flags, ret, t1, t2, t3, t4)            \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)          \
    dh_arg_decl(t1, 1), dh_arg_decl(t2, 2),                             \
    dh_arg_decl(t3, 3), dh_arg_decl(t4, 4))                             \
{                                                                       \
  TCGArg args[4] = { dh_arg(t1, 1), dh_arg(t2, 2),                      \
                     dh_arg(t3, 3), dh_arg(t4, 4) };                    \
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 4, args);       \
}

#define DEF_HELPER_FLAGS_5(name, flags, ret, t1, t2, t3, t4, t5)        \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)          \
    dh_arg_decl(t1, 1),  dh_arg_decl(t2, 2), dh_arg_decl(t3, 3),        \
    dh_arg_decl(t4, 4), dh_arg_decl(t5, 5))                             \
{                                                                       \
  TCGArg args[5] = { dh_arg(t1, 1), dh_arg(t2, 2), dh_arg(t3, 3),       \
                     dh_arg(t4, 4), dh_arg(t5, 5) };                    \
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 5, args);       \
}

#ifdef CONFIG_TCG_TAINT

#define DEF_HELPER_FLAGS_6(name, flags, ret, t1, t2, t3, t4, t5, t6)    \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)          \
    dh_arg_decl(t1, 1),  dh_arg_decl(t2, 2), dh_arg_decl(t3, 3),        \
    dh_arg_decl(t4, 4), dh_arg_decl(t5, 5), dh_arg_decl(t6, 6))         \
{                                                                       \
  TCGArg args[6] = { dh_arg(t1, 1), dh_arg(t2, 2), dh_arg(t3, 3),       \
                     dh_arg(t4, 4), dh_arg(t5, 5), dh_arg(t6, 6) };     \
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 6, args);       \
}

#define DEF_HELPER_FLAGS_7(name, flags, ret, t1, t2, t3, t4, t5, t6, t7)  \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)            \
    dh_arg_decl(t1, 1),  dh_arg_decl(t2, 2), dh_arg_decl(t3, 3),          \
    dh_arg_decl(t4, 4), dh_arg_decl(t5, 5), dh_arg_decl(t6, 6),						\
		dh_arg_decl(t7, 7))																										\
{                                                                         \
  TCGArg args[7] = { dh_arg(t1, 1), dh_arg(t2, 2), dh_arg(t3, 3),         \
                     dh_arg(t4, 4), dh_arg(t5, 5), dh_arg(t6, 6),					\
										 dh_arg(t7, 7) };																			\
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 7, args);         \
}

#define DEF_HELPER_FLAGS_8(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8) \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)            \
    dh_arg_decl(t1, 1),  dh_arg_decl(t2, 2), dh_arg_decl(t3, 3),          \
    dh_arg_decl(t4, 4), dh_arg_decl(t5, 5), dh_arg_decl(t6, 6),						\
		dh_arg_decl(t7, 7), dh_arg_decl(t8, 8))																\
{                                                                         \
  TCGArg args[8] = { dh_arg(t1, 1), dh_arg(t2, 2), dh_arg(t3, 3),         \
                     dh_arg(t4, 4), dh_arg(t5, 5), dh_arg(t6, 6),					\
										 dh_arg(t7, 7), dh_arg(t8, 8) };											\
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 8, args);         \
}


#define DEF_HELPER_FLAGS_9(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8, t9) \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)            \
    dh_arg_decl(t1, 1),  dh_arg_decl(t2, 2), dh_arg_decl(t3, 3),          \
    dh_arg_decl(t4, 4), dh_arg_decl(t5, 5), dh_arg_decl(t6, 6),						\
		dh_arg_decl(t7, 7), dh_arg_decl(t8, 8), dh_arg_decl(t9, 9))						\
{                                                                         \
  TCGArg args[9] = { dh_arg(t1, 1), dh_arg(t2, 2), dh_arg(t3, 3),         \
                     dh_arg(t4, 4), dh_arg(t5, 5), dh_arg(t6, 6),					\
										 dh_arg(t7, 7), dh_arg(t8, 8), dh_arg(t9, 9) };				\
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 9, args);         \
}

#define DEF_HELPER_FLAGS_10(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)            \
    dh_arg_decl(t1, 1),  dh_arg_decl(t2, 2), dh_arg_decl(t3, 3)	,         \
    dh_arg_decl(t4, 4), dh_arg_decl(t5, 5), dh_arg_decl(t6, 6)	,					\
		dh_arg_decl(t7, 7), dh_arg_decl(t8, 8), dh_arg_decl(t9, 9))	,					\
		dh_arg_decl(t10, 10))																									\
{                                                                         \
  TCGArg args[10] = {	dh_arg(t1, 1), dh_arg(t2, 2), dh_arg(t3, 3),        \
                     dh_arg(t4, 4), dh_arg(t5, 5), dh_arg(t6, 6),					\
										 dh_arg(t7, 7), dh_arg(t8, 8), dh_arg(t9, 9),					\
										 dh_arg(t10, 10) };																		\
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 10, args);        \
}

#define DEF_HELPER_FLAGS_11(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)            \
    dh_arg_decl(t1, 1),  dh_arg_decl(t2, 2), dh_arg_decl(t3, 3)	,         \
    dh_arg_decl(t4, 4), dh_arg_decl(t5, 5), dh_arg_decl(t6, 6)	,					\
		dh_arg_decl(t7, 7), dh_arg_decl(t8, 8), dh_arg_decl(t9, 9))	,					\
		dh_arg_decl(t10, 10), dh_arg_decl(t11, 11))														\
{                                                                         \
  TCGArg args[11] = {	dh_arg(t1, 1), dh_arg(t2, 2), dh_arg(t3, 3),        \
                     dh_arg(t4, 4), dh_arg(t5, 5), dh_arg(t6, 6),					\
										 dh_arg(t7, 7), dh_arg(t8, 8), dh_arg(t9, 9),					\
										 dh_arg(t10, 10), dh_arg(t11, 11) };									\
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 11, args);        \
}

#define DEF_HELPER_FLAGS_12(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12) \
static inline void glue(gen_helper_, name)(dh_retvar_decl(ret)            \
    dh_arg_decl(t1, 1),  dh_arg_decl(t2, 2), dh_arg_decl(t3, 3)	,         \
    dh_arg_decl(t4, 4), dh_arg_decl(t5, 5), dh_arg_decl(t6, 6)	,					\
		dh_arg_decl(t7, 7), dh_arg_decl(t8, 8), dh_arg_decl(t9, 9))	,					\
		dh_arg_decl(t10, 10), dh_arg_decl(t11, 11), dh_arg_decl(t12, 12))			\
{                                                                         \
  TCGArg args[12] = {	dh_arg(t1, 1), dh_arg(t2, 2), dh_arg(t3, 3),        \
                     dh_arg(t4, 4), dh_arg(t5, 5), dh_arg(t6, 6),					\
										 dh_arg(t7, 7), dh_arg(t8, 8), dh_arg(t9, 9),					\
										 dh_arg(t10, 10), dh_arg(t11, 11),dh_arg(t12, 12) };	\
  tcg_gen_callN(&tcg_ctx, HELPER(name), dh_retvar(ret), 12, args);        \
}


#endif /* CONFIG_TCG_TAINT */


#include "helper.h"
#include "trace/generated-helpers.h"
#include "trace/generated-helpers-wrappers.h"
#include "tcg-runtime.h"

#undef DEF_HELPER_FLAGS_0
#undef DEF_HELPER_FLAGS_1
#undef DEF_HELPER_FLAGS_2
#undef DEF_HELPER_FLAGS_3
#undef DEF_HELPER_FLAGS_4
#undef DEF_HELPER_FLAGS_5
#ifdef CONFIG_TCG_TAINT
#undef DEF_HELPER_FLAGS_6
#undef DEF_HELPER_FLAGS_7
#undef DEF_HELPER_FLAGS_8
#undef DEF_HELPER_FLAGS_9
#undef DEF_HELPER_FLAGS_10
#undef DEF_HELPER_FLAGS_11
#undef DEF_HELPER_FLAGS_12
#endif /* CONFIG_TCG_TAINT */


#undef GEN_HELPER

#endif /* HELPER_GEN_H */
