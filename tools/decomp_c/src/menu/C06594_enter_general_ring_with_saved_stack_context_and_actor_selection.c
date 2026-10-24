#include "som_c.h"
#include "som_hand_d.h"
/* SOM_PLAIN_CALLS: every memory access below goes through the live DB / D registers, so a callee that returns with another data
 * bank is followed exactly and needs no data-bank check. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) CALL_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) CALL_JSL((c), (retpc), (target))

/* C06594 enter_general_ring_with_saved_stack_context_and_actor_selection   [class C, 67 bytes, 26 instructions]
 * Source: src/rom/enter_general_ring_with_saved_stack_context_and_actor_selection.s
 * Documented in docs/event-menu-general.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
/* abs in the current data bank (a callee may have changed it) */
#define DBABS(off) (((uint32_t)r->db << 16) + (off))

static void enter_general_ring_with_saved_stack_context_and_actor_selection(SomCtx *c)
{
    Cpu *r = &c->cpu;
L_C06594:;
    i_php(c);
    i_phb(c);
    i_phd(c);
    i_rep(r, 0x20);
    STA(c, ABS, 0x1820);
    i_tsc(r);
    STA(c, ABS, 0x19ce);
    LDA(c, ABS, 0x1820);
    i_sep(r, 0x20);
    STZ(c, ABS, 0x1847);
    JSR(c, 0x65aa, 0xC06696);
    JSR(c, 0x65ad, 0xC069F0);
    if (!r->z) goto L_C065D4;
    JSL(c, 0x65b3, 0xD0DE29);
    JSR(c, 0x65b6, 0xC066B5);
    JSR(c, 0x65b9, 0xC065D7);
    JSL(c, 0x65bd, 0xD0DCBE);
L_C065BE:;
    i_sep(r, 0x20);
    LDA(c, ABS, 0x1847);
    if (!r->z) goto L_C065C9;
    JSL(c, 0x65c8, 0xC20018);
L_C065C9:;
    LDA(c, ABS, 0x19f0);
    REQUIRE_M8(c);
    a_cmp(r, 0xc0);
    if (r->z) goto L_C065D4;
    JSL(c, 0x65d3, 0xC00095);
L_C065D4:;
    TAIL_CALL(c, 0xC0645C, SOM_RTL); /* restore_inventory_menu_direct_page_bank_and_status: PLD PLB PLP RTL */
}
SOM_REGISTER(0xC06594, SOM_RTL, "hand", enter_general_ring_with_saved_stack_context_and_actor_selection, 0, L_ALL, 0, -1, -1, 67, 26)
