#include "som_c.h"
#include "som_hand_d.h"

/* C26FAC initialize_descriptor_eight_child_animation_and_cycle   [class B, 61 bytes, 24 instructions]
 * Source: src/rom/initialize_descriptor_eight_child_animation_and_cycle.s
 * Documented in docs/boss-descriptor-eight-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_eight_child_animation_and_cycle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    a_ldx(r, dp_rd16(c, 0x87)); /* object */
    RAM16_SET(OBJECT_PHASE + r->x, m_inc(r, RAM16(OBJECT_PHASE + r->x)));
    a_lda(r, 0x00FA);
    JSR(c, 0x6FB6, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    REQUIRE_M16X16(c);
    a_lda(r, 0x0001);
    RAM16_SET(0x0000 + r->x, r->a);
    RAM16_SET(0x00B2 + r->x, 0);
    RAM16_SET(0x00B4 + r->x, 0);
    a_ldx(r, dp_rd16(c, 0x87));
    a_ldy(r, RAM16(0x00B0 + r->x)); /* parent */
    a_lda(r, RAM16(OBJECT_PHASE + r->y));
    a_cmp(r, 0x0004);
    if (r->c) {
        RAM16_SET(OBJECT_PHASE + r->x, m_inc(r, RAM16(OBJECT_PHASE + r->x)));
        r->c = 0;
        RETURN_RTS(c);
    }
    a_lda(r, RAM16(0x002B + r->y));
    RAM16_SET(0x002B + r->x, r->a);
    a_lda(r, RAM16(0x0032 + r->y));
    RAM16_SET(0x0032 + r->x, r->a);
    JSR(c, 0x6FDE, 0xC27003); /* refresh_descriptor_eight_child_parent_state_animation */
    JSR(c, 0x6FE1, 0xC2701A); /* dispatch_descriptor_eight_child_animation_palette_cycle */
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26FAC, SOM_RTS, "hand", initialize_descriptor_eight_child_animation_and_cycle, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 61, 24)
