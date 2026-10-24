#include "som_c.h"

/* C206EF compare_absolute_collision_height_difference_to_129   [class A, 15 bytes, 8 instructions]
 * Source: src/rom/compare_absolute_collision_height_difference_to_129.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void compare_absolute_collision_height_difference_to_129(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0262);
    uint16_t value2 = RAM16(0x0264);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value - value2) & 0x8000)) {
        a1 = (uint8_t)(value - value2);
        a_hi1 = (uint16_t)(value - value2) >> 8;
    } else {
        a1 = (uint8_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) >> 8;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = ((a_hi1 << 8) | a1) >= 0x81;
    r->v = ((value ^ value2) & (value ^ (uint16_t)(value - value2)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC206EF, SOM_RTS, "gen", compare_absolute_collision_height_difference_to_129, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 15, 8)
