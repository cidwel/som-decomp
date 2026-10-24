#include "som_c.h"

/* C26CAB initialize_position_height_boss_child   [class A, 32 bytes, 12 instructions]
 * Source: src/rom/initialize_position_height_boss_child.s
 * Documented in docs/boss-native-child-definitions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_position_height_boss_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->a = 0xD9;
    r->x = value;
    JSR(c, 0x6CB5, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(0x0022 + value, 0x07FF);
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(OBJECT_AGE + value2);
    r->a = value3;
    r->x = value2;
    r->c = value3 >= 0x26;
    r->z = value3 == 0x26;
    r->n = (uint16_t)(value3 - 0x26) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26CAB, SOM_RTS, "gen", initialize_position_height_boss_child, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 32, 12)
