#include "som_c.h"

/* C1F29C prepare_map_palette_snapshot_long   [class A, 16 bytes, 10 instructions]
 * Source: src/rom/prepare_map_palette_snapshot_long.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void prepare_map_palette_snapshot_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x00E2) &= 0xEF;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xF2A9, 0xC1F2AC); /* copy_map_palette_snapshot_and_hdma_records */
    r->sp += 1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1F29C, SOM_RTL, "gen", prepare_map_palette_snapshot_long, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 16, 10)
