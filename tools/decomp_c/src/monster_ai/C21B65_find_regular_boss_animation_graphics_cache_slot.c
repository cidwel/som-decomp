#include "som_c.h"

/* C21B65 find_regular_boss_animation_graphics_cache_slot   [class A, 26 bytes, 15 instructions]
 * Source: src/rom/find_regular_boss_animation_graphics_cache_slot.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void find_regular_boss_animation_graphics_cache_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0FA8);
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = value;
    for (;;) {
        uint8_t value2 = RAM8(0x0F55 + x1);
        if (!(value2 & 0x80)) {
            if ((uint8_t)(x1 + 1) != 0x4D) {
                a1 = value2;
                x1 = (uint8_t)(x1 + 1);
                continue;
            }
            a1 = value2;
            x1 = (uint8_t)(x1 + 1);
            break;
        }
        if (value2 == 0xFE) {
            if ((uint8_t)(x1 + 1) != 0x4D) {
                a1 = value2;
                x1 = (uint8_t)(x1 + 1);
                continue;
            }
            a1 = value2;
            x1 = (uint8_t)(x1 + 1);
            break;
        }
        if (value2 == 0x80) {
            if ((uint8_t)(x1 + 1) != 0x4D) {
                a1 = value2;
                x1 = (uint8_t)(x1 + 1);
                continue;
            }
            a1 = value2;
            x1 = (uint8_t)(x1 + 1);
            break;
        }
        r->a = (a_hi1 << 8) | x1;
        r->y = y;
        r->c = 0;
        r->v = overflow;
        RETURN_RTS(c);
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y;
    r->c = 1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21B65, SOM_RTS, "gen", find_regular_boss_animation_graphics_cache_slot, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 1, 26, 15)
