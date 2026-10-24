#include "som_c.h"
#include "som_hand_d.h"
/* SOM_PLAIN_CALLS: every memory access below goes through the live DB / D registers, so a callee that returns with another data
 * bank is followed exactly and needs no data-bank check. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) CALL_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) CALL_JSL((c), (retpc), (target))

/* 7EB2FB receive_raw_task_record   [class A, 23 bytes, 16 instructions]
 * Source: src/boot/receive_raw_task_record.s
 * Documented in docs/boot.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCZNV.
 *
 * Switches to DB=$7F and suspends the current task until it is woken with a non-zero X (the received record).
 */
static void receive_raw_task_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
L_7EB2FB:;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_sep(r, 0x20);
    i_phb(c);
    a_lda(r, 0x7f);
    i_pha(c);
    i_plb(c);
    i_rep(r, 0x20);
L_7EB308:;
    JSR(c, 0xb30a, 0x7EA911);
    i_txa(r);
    if (r->z) goto L_7EB308;
    i_plb(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB2FB, SOM_RTS, "hand", receive_raw_task_record, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 0, -1, 0, 23, 16)
