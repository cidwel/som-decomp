#include "som_c.h"

/* C1E61D emit_party_hud_sprites_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/emit_party_hud_sprites_long.s
 * Documented in docs/graphics.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: BXC.
 */
static void emit_party_hud_sprites_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xE61F, 0xC1E621); /* emit_party_hud_sprites */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1E61D, SOM_RTL, "gen", emit_party_hud_sprites_long, 0, L_B | L_X | L_C, 1, -1, 0, 4, 2)
