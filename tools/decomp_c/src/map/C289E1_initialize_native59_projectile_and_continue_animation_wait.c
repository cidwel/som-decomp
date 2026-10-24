#include "som_c.h"

/* C289E1 initialize_native59_projectile_and_continue_animation_wait   [class B, 56 bytes, 21 instructions]
 * Source: src/rom/initialize_native59_projectile_and_continue_animation_wait.s
 * Documented in docs/boss-native59-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_native59_projectile_and_continue_animation_wait(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->a = 0x010C;
    r->x = value;
    JSR(c, 0x89F1, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(0x009E + value2);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value3 != 0) {
        a1 = (uint8_t)value3;
        a_hi1 = value3 >> 8;
        zero1 = value3 == 0;
        negative1 = value3 & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value2, (uint16_t)(RAM16(OBJECT_PHASE + value2) + 1));
        r->a = 0x010D;
        r->x = value2;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x8A01, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(0x0066 + value2, 0x10);
        RAM16_SET(0x00C6 + value2, 0x1E);
        RAM16_SET(0x00B4 + value2, 0x1E);
        RAM16_SET(0x0090 + value2, 0x3F4C);
        a1 = 0x4C;
        a_hi1 = 0x3F;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value2;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC289E1, SOM_RTS, "gen", initialize_native59_projectile_and_continue_animation_wait, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 56, 21)
