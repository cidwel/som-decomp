#include "som_c.h"
#include "som_hand.h"

/* C2023A emit_selected_boss_object_with_saved_context   [class A, 22 bytes, 15 instructions]
 * Source: src/rom/emit_selected_boss_object_with_saved_context.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXC.
 */
static void emit_selected_boss_object_with_saved_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;

    /* PHP, PHD, PHB, SEP #$20, LDA #$7E, PHA, PLB, REP #$30 */
    RAM8(sp0) = hand_p_byte(r);
    RAM8(sp0 - 1) = r->dp >> 8;
    RAM8(sp0 - 2) = (uint8_t)r->dp;
    RAM8(sp0 - 3) = r->db;
    r->sp = sp0 - 4;
    r->db = 0x7E;
    r->mf = 0;
    r->xf = 0;
    r->a = 0x0200;
    r->dp = 0x0200;
    JSR(c, 0x024B, 0xC20F91); /* emit_selected_boss_object_camera_palette_callback_and_sprites */
    hand_plb(c);
    hand_pld(c);
    hand_plp(c);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2023A, SOM_RTL, "hand", emit_selected_boss_object_with_saved_context, 0, L_A | L_B | L_X | L_C, 5, 0, 0, 22, 15)
