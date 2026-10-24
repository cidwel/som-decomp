#include "som_c.h"

/* C253F1 initialize_descriptor_twelve_height_phase_and_one_shot_flag   [class A, 27 bytes, 10 instructions]
 * Source: src/rom/initialize_descriptor_twelve_height_phase_and_one_shot_flag.s
 * Documented in docs/boss-descriptor-twelve.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_twelve_height_phase_and_one_shot_flag(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x53F3, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x007E + x, 0);
    RAM16_SET(0x00BE + x, 0);
    RAM16_SET(0x0066 + x, 0x0400);
    RAM16_SET(0x00A7 + x, 5);
    uint16_t value = RAM16(0x0042 + x);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC253F1, SOM_RTS, "gen", initialize_descriptor_twelve_height_phase_and_one_shot_flag, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 27, 10)
