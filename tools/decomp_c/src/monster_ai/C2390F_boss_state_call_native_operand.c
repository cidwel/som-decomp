#include "som_c.h"
#include "som_hand_b.h"

/* C2390F boss_state_call_native_operand   [class A, 14 bytes, hand written]
 * Source: src/rom/boss_state_call_native_operand.s
 * Documented in docs/graphics.md
 *
 * Reads the native operand word at [$30],Y into A, advances Y past it, calls the boss state's native pointer jump
 * (C2391D) with the new Y saved on the stack, then restores Y and reloads X from $87.  The direct page and the data
 * bank are whatever the caller has; the widths follow the registers (LDX/LDA/PHY take their size from the M and X
 * flags at run time).  The pushed Y stays on the stack while the handler runs, so the handler may overwrite it.
 */
static void boss_state_call_native_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    const uint16_t sp0 = r->sp;
    hand_ldx_dp(c, 0x87);                        /* LDX $87 */
    const uint32_t ptr = (dp_rd16(c, 0x30) | ((uint32_t)dp_rd8(c, 0x32) << 16)) + r->y;
    const int bytes = r->mf ? 1 : 2;
    for (int i = 0; i < bytes; i++) if (!hand_rd_ok((ptr + i) & 0xFFFFFF)) { c->fail = 3; return; }
    a_lda(r, r->mf ? BUS8(c, ptr & 0xFFFFFF) : BUS16(c, ptr & 0xFFFFFF));         /* LDA [$30],Y */
    r->y = r->xf ? (uint8_t)(r->y + 1) : (uint16_t)(r->y + 1); zn(r, r->y, r->xf);   /* INY, INY */
    r->y = r->xf ? (uint8_t)(r->y + 1) : (uint16_t)(r->y + 1); zn(r, r->y, r->xf);
    i_phy(c);                                    /* PHY */
    /* JSR boss_state_jump_to_native_pointer.  The native handler it jumps to may drop its own return address and return
     * through the word pushed above (a script cursor, not code): the original then runs on at an arbitrary address,
     * which the C does not know: the interpreter continues from the popped address until this routine's own RTS. */
    push16(c, 0x3918);
    som_call_nested(c, 0xC2391D, SOM_RTS);
    if (c->fail) return;
    if (c->unwound && r->sp == (uint16_t)(sp0 + 2)) return;   /* the handler's RTS was this routine's own return */
    if (c->unwound || r->pc != 0x3919) { c->unwound = 0; som_interp_run(c, SOM_RTS, sp0); return; }
    i_ply(c);                                    /* PLY */
    hand_ldx_dp(c, 0x87);                        /* LDX $87 */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2390F, SOM_RTS, "hand", boss_state_call_native_operand, 0, L_ALL, 2, -1, -1, 14, 9)
