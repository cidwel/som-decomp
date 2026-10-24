#include "som_c.h"

/* C206C5 test_boss_target_height_with_inverted_flag_pair   [class B, 42 bytes, 23 instructions]
 * Source: src/rom/test_boss_target_height_with_inverted_flag_pair.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void test_boss_target_height_with_inverted_flag_pair(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x0224);
    uint8_t value3 = RAM8(0x000B + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000));
    uint8_t value4 = RAM8(0x000B + value);
    if (((value3 | value4) & 3) != 3) {
        r->a = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) >> 8 << 8 | ((value3 | value4) & 3);
        r->y = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000);
        JSR(c, 0x06ED, 0xC206EF); /* compare_absolute_collision_height_difference_to_129 */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) >> 8 << 8 | ((value3 | value4) & 3);
    r->y = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000);
    JSR(c, 0x06E2, 0xC206EF); /* compare_absolute_collision_height_difference_to_129 */
    bool carry_ret2 = r->c;
    if (carry_ret2) {
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->c = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC206C5, SOM_RTS, "gen", test_boss_target_height_with_inverted_flag_pair, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 42, 23)
