#include "som_c.h"

/* C244D9 initialize_native54_attack_and_state11   [class B, 62 bytes, 24 instructions]
 * Source: src/rom/initialize_native54_attack_and_state11.s
 * Documented in docs/boss-native54-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_native54_attack_and_state11(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x44DD, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x00B0 + value, 0);
    RAM16_SET(0x00BA + value, 0);
    RAM16_SET(0x00BC + value, 0);
    RAM16_SET(0x00BE + value, 0);
    RAM16_SET(0x001E + value, 3);
    r->a = 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x44F5, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(OBJECT_PHASE + value, 0x0B);
    RAM16_SET(0x0062 + value, 0xFFF0);
    RAM16_SET(0x0045 + value, (uint16_t)((RAM16(0x02C7) ^ 0xFFF0) + 1));
    uint16_t value3 = RAM16(0x0042 + value);
    r->a = (uint16_t)(value3 + 0x1C);
    r->c = value3 + 0x1C > 0xFFFF;
    r->z = (uint16_t)(value3 + 0x1C) == 0;
    r->n = (uint16_t)(value3 + 0x1C) & 0x8000;
    r->v = (((uint16_t)(value3 + 0x1C) ^ 0x1C) & (value3 ^ (uint16_t)(value3 + 0x1C)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSL(c, 0x4512, 0xC0006C); /* boss_attack_row_public_jump */
    uint16_t value4 = RAM16(0x0287);
    r->x = value4;
    r->c = 0;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC244D9, SOM_RTS, "gen", initialize_native54_attack_and_state11, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 62, 24)
