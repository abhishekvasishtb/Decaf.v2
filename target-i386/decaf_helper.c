#include <math.h>
#include "cpu.h"
#include "dyngen-exec.h"
#include "host-utils.h"
#include "ioport.h"
#include "qemu-common.h"
#include "qemu-log.h"
#include "cpu-defs.h"
#include "helper.h"

#ifdef CONFIG_TCG_TAINT
	#include "/shared/tainting/taintcheck_opt.h"
#endif /* CONFIG_TCG_TAINT */

#include "/shared/DECAF_main.h"


//Aravind - insn_callback_dispatch fn.
extern void (*insn_cbl1[16*16]) (uint32_t eip, uint32_t next_eip, uint32_t op);
extern void (*insn_cbl2[16*16]) (uint32_t eip, uint32_t next_eip, uint32_t op);

//uint32_t KiUserExceptionDispatcher_addr_l =  0xE45C + 0x7c900000;
//uint32_t KiUserApcDispatcher_addr_l = 0xE430 + 0x7c900000;
//uint32_t KiRaiseUserExceptionDispatcher_addr_l = 0xE4A8 + 0x7c900000;
//uint32_t KiUserCallbackDispatcher_addr_l = 0xE440 + 0x7c900000;
#if 0 // AWH
void helper_insn_cb_dispatch(uint32_t eip, uint32_t next_eip, uint32_t op2)
{


  //LOK: Segmentation Fault
  return;
	uint32_t op;
	op = op2;
//		if(next_eip == KiUserExceptionDispatcher_addr_l
//				|| next_eip == KiUserApcDispatcher_addr_l
//				|| next_eip == KiRaiseUserExceptionDispatcher_addr_l
//				|| next_eip == KiUserCallbackDispatcher_addr_l) {
//			printf("***********HIT*********\n eip = 0x%08x, next_eip = 0x%08x, op = %x\n*************************\n", eip, next_eip, op);
//		}
	//printf("Inside CB: EIP = 0x%08x!, OP = 0x%08x\n", eip, op);
	if(op & 0x100) {
		op = 0x0f + (op & 0xff);
	}
	if(op > 0xf00 && op <= 0xfff) {
		if(insn_cbl2[op-0xf00])
			insn_cbl2[op-0xf00](eip, next_eip, op2);
	} else if(/* AWH op >= 0x0 &&*/ op <= 0xff){
		if(insn_cbl1[op])
			insn_cbl1[op](eip, next_eip, op2);
	} else {
		//printf("Invalid case: EIP = 0x%08x!, OP = 0x%08x\n", eip, op);
		if(insn_cbl1[0xf0]) {
			if(insn_cbl1[0xf0] > 1)
				insn_cbl1[0xf0](eip, next_eip, op2);
			else
				printf("Invalid case: EIP = 0x%08x!, next_eip = 0x%08x, OP = 0x%08x\n", eip, next_eip, op2);
		}
	}
}
//end - Aravind
#endif // AWH
#ifdef CONFIG_TCG_TAINT
void helper_DECAF_taint_cmpxchg(void) {}

/*
  patch for keystroke propagation on windows xp sp2 and sp3
*/
void helper_DECAF_taint_patch(void)
{
	if (!taint_tracking_enabled) return;

	if (cpu_single_env->eip != 0xbf8a4bde && cpu_single_env->eip != 0xbf84a74f
			&& cpu_single_env->eip != 0xbf848d65 &&  //for sp3
			cpu_single_env->eip != 0xbf848d1c) // updated sp3
		return ;

	uint32_t phys_addr, addr, addr2, phys_addr2;
	uint8_t  taint_check;
	addr = cpu_single_env->regs[R_EBP] + 8;
	phys_addr = DECAF_get_phys_addr(cpu_single_env, addr);
	if (phys_addr == -1)
		return ;

	taint_mem_check(phys_addr, 1, &taint_check);
	if (!taint_check)
		return ;

	addr2 = cpu_single_env->regs[R_EBP] + 0x14;

	if (DECAF_read_mem(cpu_single_env, addr2, 4, &addr2) >= 0 && (phys_addr2 =
			DECAF_get_phys_addr(cpu_single_env, addr2)) != -1) {
		taint_mem(phys_addr2, 1,(uint8_t*) &taint_check);
	}
}

#endif /* CONFIG_TCG_TAINT */ 
/*
 * patch for better FPU emulation added by Hu
 *
 */

void helper_DECAF_update_fpu(void)
{
	cpu_single_env->fpip_t = cpu_single_env->eip;
	cpu_single_env->fpcs_t = cpu_single_env->segs[R_CS].selector;
}

