#include "som_c.h"

/* C2603B initialize_descriptor_five_animation_variant_phase   [class A, 16 bytes, 6 instructions]
 * Source: src/rom/initialize_descriptor_five_animation_variant_phase.s
 * Documented in docs/boss-descriptor-five.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_five_animation_variant_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x603D, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x007E + x, RAM16(0x0042 + x));
    RAM16_SET(0x001E + x, 0x10);
    r->a = 0x10;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2603B, SOM_RTS, "gen", initialize_descriptor_five_animation_variant_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 16, 6)
