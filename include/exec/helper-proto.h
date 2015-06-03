/* Helper file for declaring TCG helper functions.
   This one expands prototypes for the helper functions.  */

#ifndef HELPER_PROTO_H
#define HELPER_PROTO_H 1

#include <exec/helper-head.h>

#define DEF_HELPER_FLAGS_0(name, flags, ret) \
dh_ctype(ret) HELPER(name) (void);

#define DEF_HELPER_FLAGS_1(name, flags, ret, t1) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1));

#define DEF_HELPER_FLAGS_2(name, flags, ret, t1, t2) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2));

#define DEF_HELPER_FLAGS_3(name, flags, ret, t1, t2, t3) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3));

#define DEF_HELPER_FLAGS_4(name, flags, ret, t1, t2, t3, t4) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3), \
                                   dh_ctype(t4));

#define DEF_HELPER_FLAGS_5(name, flags, ret, t1, t2, t3, t4, t5) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3), \
                            dh_ctype(t4), dh_ctype(t5));


// AVB, there will be a problem here

#ifdef CONFIG_TCG_TAINT

#define DEF_HELPER_FLAGS_6(name, flags, ret, t1, t2, t3, t4, t5, t6) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3), \
                             dh_ctype(t4), dh_ctype(t5), dh_ctype(t6));

#define DEF_HELPER_FLAGS_7(name, flags, ret, t1, t2, t3, t4, t5, t6, t7) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3), \
dh_ctype(t4), dh_ctype(t5), dh_ctype(t6), dh_ctype(t7));

#define DEF_HELPER_FLAGS_8(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3), \
dh_ctype(t4), dh_ctype(t5), dh_ctype(t6), dh_ctype(t7), dh_ctype(t8));

#define DEF_HELPER_FLAGS_9(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8, t9) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3), \
dh_ctype(t4), dh_ctype(t5), dh_ctype(t6), dh_ctype(t7), dh_ctype(t8), \
dh_ctype(t9));

#define DEF_HELPER_FLAGS_10(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3), \
dh_ctype(t4), dh_ctype(t5), dh_ctype(t6), dh_ctype(t7), dh_ctype(t8), \
dh_ctype(t9), dh_ctype(t10));

#define DEF_HELPER_FLAGS_11(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3), \
dh_ctype(t4), dh_ctype(t5), dh_ctype(t6), dh_ctype(t7), dh_ctype(t8), \
dh_ctype(t9), dh_ctype(t10), dh_ctype(t11));

#define DEF_HELPER_FLAGS_12(name, flags, ret, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12) \
dh_ctype(ret) HELPER(name) (dh_ctype(t1), dh_ctype(t2), dh_ctype(t3), \
dh_ctype(t4), dh_ctype(t5), dh_ctype(t6), dh_ctype(t7), dh_ctype(t8), \
dh_ctype(t9), dh_ctype(t10), dh_ctype(t11), dh_ctype(t12));
#endif /* CONFIG_TCG_TAINT */


#include "helper.h"
#include "trace/generated-helpers.h"
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


#endif /* HELPER_PROTO_H */
