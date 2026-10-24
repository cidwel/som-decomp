#include "som_c.h"

/* C1CBCF snapshot_map_state_and_backup   [class A, 27 bytes, 15 instructions]
 * Source: src/rom/snapshot_map_state_and_backup.s
 * Documented in docs/cutscene-engine.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: YV.
 */
static void snapshot_map_state_and_backup(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xCBD1, 0xC1CBEA); /* snapshot_map_scroll_and_actor_cache */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = 0xFE;
    for (;;) {
        uint16_t value = RAM16(0xCD00 + x1);
        RAM16_SET(0xCE00 + x1, value);
        a_hi1 = value >> 8;
        x1 = (uint16_t)(x1 - 2);
        if (!(!(x1 & 0x8000))) break;
    }
    r->y = y_ret;
    r->v = overflow_ret;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1CBCF, SOM_RTL, "gen", snapshot_map_state_and_backup, 0, L_Y | L_V, 2, 0, 0, 27, 15)
