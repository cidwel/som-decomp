#include "som_c.h"

/* C242E1 initialize_descriptor_one_animation_bank_and_phase   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/initialize_descriptor_one_animation_bank_and_phase.s
 * Documented in docs/boss-descriptor-one.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_one_animation_bank_and_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x42E3, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x007E + x, 0);
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC242E1, SOM_RTS, "gen", initialize_descriptor_one_animation_bank_and_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 7, 3)
