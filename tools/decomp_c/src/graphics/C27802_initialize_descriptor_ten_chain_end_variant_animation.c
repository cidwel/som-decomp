#include "som_c.h"

/* C27802 initialize_descriptor_ten_chain_end_variant_animation   [class B, 47 bytes, 18 instructions]
 * Source: src/rom/initialize_descriptor_ten_chain_end_variant_animation.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_ten_chain_end_variant_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x7806, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    uint16_t value2 = RAM16(0x00B0 + value);
    RAM16_SET(0x002B + value, RAM16(0x002B + value2));
    RAM16_SET(0x0032 + value, RAM16(0x0032 + value2));
    uint16_t value5 = RAM16(0x0042 + value);
    r->a = (uint16_t)(value5 + 0x0140);
    r->y = value2;
    r->c = value5 + 0x0140 > 0xFFFF;
    r->v = (((uint16_t)(value5 + 0x0140) ^ 0x0140) & (value5 ^ (uint16_t)(value5 + 0x0140)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x781F, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0090 + value, 0x7938);
    r->a = 0x7938;
    r->c = 0;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27802, SOM_RTS, "gen", initialize_descriptor_ten_chain_end_variant_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 47, 18)
