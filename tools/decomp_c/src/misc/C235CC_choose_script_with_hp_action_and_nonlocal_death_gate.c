#include "som_c.h"
#include "som_hand_d.h"

/* C235CC choose_script_with_hp_action_and_nonlocal_death_gate   [class C, 64 bytes, 25 instructions]
 * Source: src/rom/choose_script_with_hp_action_and_nonlocal_death_gate.s
 * Documented in docs/boss-actor-controller.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: AV.
 */
/* JSR for a callee chain that can drop this routine's own return address as well (the nonlocal exit through the descriptor
 * callbacks): the original stops at the unwinding RTS whose stack pointer is the entry S plus the return size.  The nested run
 * ends there when the routine's S is raised by that size for the duration of the call; the C routine then returns at once and
 * the harness continues from the exit state like it does for any unwinder. */
#undef JSR
#define JSR(c, retpc, target) do { const uint8_t db_call_ = (c)->cpu.db; const uint16_t rsp_ = (c)->routine_sp; \
        push16((c), (retpc)); (c)->routine_sp = (uint16_t)(entry_sp_ + 2); som_call_nested((c), (target), SOM_RTS); (c)->routine_sp = rsp_; \
        if ((c)->unwound) return; \
        if (!(c)->fail && (c)->cpu.pc != (uint16_t)((retpc) + 1)) { (c)->fail = 3; return; } \
        if ((c)->fail) return; \
        if ((c)->cpu.db != db_call_) { (c)->fail = 3; return; } } while (0)

static void choose_script_with_hp_action_and_nonlocal_death_gate(SomCtx *c)
{
    Cpu *r = &c->cpu;
    const uint16_t entry_sp_ = r->sp;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
L_C235CC:;
    LDA(c, ABX, 0x82);
    a_cmp(r, 0x2);
    if (!r->z) goto L_C235E3;
    JSR(c, 0x35d6, 0xC234B0);
    if (!r->c) goto L_C235E3;
    REQUIRE_M16(c);
    a_lda(r, 0x4);
    STA(c, ABX, 0x94);
    i_pla(c);
    TAIL_CALL(c, 0xC20AFD, SOM_RTS);
L_C235E3:;
    LDX(c, DP, 0x87);
    LDA(c, ABX, 0x82);
    if (!r->z) goto L_C235F0;
    JSR(c, 0x35ec, 0xC23372);
    STZ(c, ABX, 0xad);
L_C235F0:;
    LDA(c, ABX, 0xad);
    CMP(c, ABX, 0x2d);
    if (!r->c) goto L_C23602;
    STZ(c, ABX, 0x82);
    JSR(c, 0x35fd, 0xC23617);
    if (!r->c) goto L_C2360B;
    LDX(c, DP, 0x87);
L_C23602:;
    REQUIRE_M16(c);
    a_lda(r, 0x1);
    STA(c, ABX, 0x82);
    TAIL_CALL_DYN(c, 0xC2360C, SOM_RTS);
L_C2360B:;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC235CC, SOM_RTS, "hand", choose_script_with_hp_action_and_nonlocal_death_gate, SOM_UNWINDS, L_A | L_V, 2, 0, 0, 64, 25)
