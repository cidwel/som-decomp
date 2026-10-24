#include "som_c.h"

/* C21B2D derive_boss_animation_graphics_cache_key   [class A, 20 bytes, 11 instructions]
 * Source: src/rom/derive_boss_animation_graphics_cache_key.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void derive_boss_animation_graphics_cache_key(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM16_SET(0x026C, a);
    RAM16_SET(0x026A, (a & 0x0F) >> 1);
    uint16_t value = RAM16(0x026C);
    uint16_t value2 = RAM16(0x026A);
    RAM16_SET(0x0268, ((value & 0x01E0) >> 2) | value2);
    r->a = ((value & 0x01E0) >> 2) | value2;
    r->c = (value & 0x01E0) >> 1 & 0x01;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21B2D, SOM_RTS, "gen", derive_boss_animation_graphics_cache_key, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 1, 20, 11)
