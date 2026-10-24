#include "som_c.h"

/* C211EC request_boss_actor_cached_palette_reload   [class A, 8 bytes, 4 instructions]
 * Source: src/rom/request_boss_actor_cached_palette_reload.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void request_boss_actor_cached_palette_reload(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM8(0x0100 + value) = 0x80;
    r->x = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC211EC, SOM_RTS, "gen", request_boss_actor_cached_palette_reload, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 8, 4)
