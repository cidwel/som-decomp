#include "som_c.h"

/* C23E69 advance_descriptor_zero_child_when_global_freeze_releases   [class A, 22 bytes, 9 instructions]
 * Source: src/rom/advance_descriptor_zero_child_when_global_freeze_releases.s
 * Documented in docs/boss-descriptor-zero-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_zero_child_when_global_freeze_releases(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0xCFFF);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if ((value2 & 1) != 0) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        zero1 = (value2 & 1) == 0;
        negative1 = value2 & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
        r->a = 0xE6;
        r->x = value;
        JSR(c, 0x3E7C, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all = r->a;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        zero1 = zero_ret;
        negative1 = negative_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23E69, SOM_RTS, "gen", advance_descriptor_zero_child_when_global_freeze_releases, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 22, 9)
