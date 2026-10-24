#include "som_c.h"

/* C0F102 test_second_third_hero_byte_positions_and_unwind_parent   [class C, 34 bytes, 16 instructions]
 * Source: src/rom/test_second_third_hero_byte_positions_and_unwind_parent.s
 * Documented in docs/actor-charge-hero-link.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void test_second_third_hero_byte_positions_and_unwind_parent(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xE200);
    if (value == 0) {
        RETURN_RTS(c);
    }
    if (!(value & 0x80)) {
        uint8_t value2 = RAM8(0xE202);
        uint8_t value3 = RAM8(0xE402);
        if (value2 != value3) {
            r->c = value2 >= value3;
            r->sp += 2;
            RETURN_RTS(c);
        }
        uint8_t value6 = RAM8(0xE204);
        uint8_t value7 = RAM8(0xE404);
        if (value6 == value7) {
            r->c = value6 >= value7;
            RETURN_RTS(c);
        }
        r->c = value6 >= value7;
        r->sp += 2;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0F102, SOM_RTS, "gen", test_second_third_hero_byte_positions_and_unwind_parent, SOM_UNWINDS, L_B | L_Y | L_C | L_V, 2, 1, 0, 34, 16)
