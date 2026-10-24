#include "som_c.h"

/* C21A81 prepare_boss_animation_graphics_cache_by_mode   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/prepare_boss_animation_graphics_cache_by_mode.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void prepare_boss_animation_graphics_cache_by_mode(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0098 + x);
    if ((value & 0x1000) == 0) {
        r->a = value;
        JSR(c, 0x1A8F, 0xC21ACA); /* prepare_boss_animation_background_graphics_cache */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value;
    JSR(c, 0x1A8B, 0xC21A91); /* prepare_boss_animation_regular_graphics_cache */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21A81, SOM_RTS, "gen", prepare_boss_animation_graphics_cache_by_mode, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 16, 7)
