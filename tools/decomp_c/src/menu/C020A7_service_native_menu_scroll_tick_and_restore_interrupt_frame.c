#include "som_c.h"
#include "som_hand_d.h"

/* C020A7 service_native_menu_scroll_tick_and_restore_interrupt_frame   [class D, 61 bytes, 32 instructions]
 * Source: src/rom/service_native_menu_scroll_tick_and_restore_interrupt_frame.s
 * Documented in docs/event-menu-interrupt.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void service_native_menu_scroll_tick_and_restore_interrupt_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
L_C020A7:;
    i_phx(c);
    i_phy(c);
    i_phb(c);
    i_pha(c);
    i_php(c);
    i_sep(r, 0x20);
    a_lda(r, 0x7e);
    i_pha(c);
    i_plb(c);
    LDA(c, ABL, 0x4210);
    LDA(c, ABS, 0xa20c);
    i_inca(r);
    STA(c, ABS, 0xa20c);
    a_and(r, 0x3);
    if (!r->z) goto L_C020DE;
    LDA(c, ABS, 0xa20b);
    i_inca(r);
    STA(c, ABS, 0xa20b);
    i_pha(c);
    STA(c, ABL, 0x210d);
    a_lda(r, 0x0);
    STA(c, ABL, 0x210d);
    i_pla(c);
    STA(c, ABL, 0x210e);
    a_lda(r, 0x0);
    STA(c, ABL, 0x210e);
L_C020DE:;
    i_plp(c);
    i_pla(c);
    i_plb(c);
    i_ply(c);
    i_plx(c);
    i_rti(c); return;
}
SOM_REGISTER(0xC020A7, SOM_RTI, "hand", service_native_menu_scroll_tick_and_restore_interrupt_frame, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, -1, -1, 61, 32)
