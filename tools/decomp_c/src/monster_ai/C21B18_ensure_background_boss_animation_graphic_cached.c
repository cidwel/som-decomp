#include "som_c.h"

/* C21B18 ensure_background_boss_animation_graphic_cached   [class B, 21 bytes, 9 instructions]
 * Source: src/rom/ensure_background_boss_animation_graphic_cached.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void ensure_background_boss_animation_graphic_cached(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool overflow = r->v;
    JSR(c, 0x1B1A, 0xC21B2D); /* derive_boss_animation_graphics_cache_key */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0x1B1F, 0xC21B53); /* find_background_boss_animation_graphics_cache_key */
    uint16_t a_all2 = r->a;
    bool carry_ret2 = r->c;
    uint8_t a_hi2;
    bool carry2;
    bool overflow2;
    if (!carry_ret2) {
        a_hi2 = a_all2 >> 8;
        carry2 = carry_ret2;
        overflow2 = overflow;
    } else {
        r->mf = 1;
        r->xf = 1;
        JSR(c, 0x1B24, 0xC21B7F); /* find_background_boss_animation_graphics_cache_slot */
        uint16_t a_all3 = r->a;
        bool carry_ret3 = r->c;
        uint8_t a_hi1;
        bool carry1;
        bool overflow1;
        if (carry_ret3) {
            a_hi1 = a_all3 >> 8;
            carry1 = carry_ret3;
            overflow1 = overflow;
        } else {
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0x1B29, 0xC21BE5); /* enqueue_background_boss_animation_graphics_transfer */
            uint16_t a_all4 = r->a;
            bool carry_ret4 = r->c;
            bool overflow_ret = r->v;
            a_hi1 = a_all4 >> 8;
            carry1 = carry_ret4;
            overflow1 = overflow_ret;
        }
        a_hi2 = a_hi1;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21B18, SOM_RTS, "gen", ensure_background_boss_animation_graphic_cached, 0, L_B | L_Y | L_C | L_V, 1, 0, 1, 21, 9)
