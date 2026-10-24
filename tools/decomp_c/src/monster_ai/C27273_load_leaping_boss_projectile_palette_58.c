#include "som_c.h"

/* C27273 load_leaping_boss_projectile_palette_58   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/load_leaping_boss_projectile_palette_58.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void load_leaping_boss_projectile_palette_58(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 0x58;
    r->x = 0x0F;
    JSR(c, 0x727B, 0xC226F9); /* copy_boss_palette_with_cpu_words */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27273, SOM_RTS, "gen", load_leaping_boss_projectile_palette_58, 0, 0, 1, 0, 0, 10, 4)
