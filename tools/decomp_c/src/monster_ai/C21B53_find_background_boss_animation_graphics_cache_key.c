#include "som_c.h"

/* C21B53 find_background_boss_animation_graphics_cache_key   [class A, 18 bytes, 10 instructions]
 * Source: src/rom/find_background_boss_animation_graphics_cache_key.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void find_background_boss_animation_graphics_cache_key(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0268);
    uint8_t x1 = 0x30;
    for (;;) {
        if (value == RAM8(0x0F55 + x1)) {
            r->a = (a_hi << 8) | value;
            r->y = y;
            r->c = 0;
            r->v = overflow;
            RETURN_RTS(c);
        }
        uint8_t value3 = RAM8(0x0FAA);
        if ((uint8_t)(x1 + 1) < value3) {
            x1 = (uint8_t)(x1 + 1);
            continue;
        }
        r->a = (a_hi << 8) | value;
        r->y = y;
        r->c = (uint8_t)(x1 + 1) >= value3;
        r->v = overflow;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC21B53, SOM_RTS, "gen", find_background_boss_animation_graphics_cache_key, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 1, 18, 10)
