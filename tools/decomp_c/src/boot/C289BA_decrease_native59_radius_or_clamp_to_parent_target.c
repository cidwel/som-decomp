#include "som_c.h"

/* C289BA decrease_native59_radius_or_clamp_to_parent_target   [class A, 23 bytes, 10 instructions]
 * Source: src/rom/decrease_native59_radius_or_clamp_to_parent_target.s
 * Documented in docs/boss-native59-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void decrease_native59_radius_or_clamp_to_parent_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B4 + value);
    uint16_t value3 = RAM16(0x00B8 + value);
    if (value2 == value3) {
        RAM16_SET(0x00B4 + value, value3);
        r->a = value3;
        r->x = value;
        r->c = value2 >= value3;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        RETURN_RTS(c);
    }
    if (value2 < value3) {
        RAM16_SET(0x00B4 + value, value3);
        r->a = value3;
        r->x = value;
        r->c = value2 >= value3;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        RETURN_RTS(c);
    }
    RAM16_SET(0x00B4 + value, (uint16_t)(RAM16(0x00B4 + value) - 1));
    r->a = value2;
    r->x = value;
    r->c = value2 >= value3;
    r->z = RAM16(0x00B4 + value) == 0;
    r->n = RAM16(0x00B4 + value) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC289BA, SOM_RTS, "gen", decrease_native59_radius_or_clamp_to_parent_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 23, 10)
