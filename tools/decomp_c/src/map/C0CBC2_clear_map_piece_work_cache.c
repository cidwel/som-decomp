#include "som_c.h"

/* C0CBC2 clear_map_piece_work_cache   [class A, 15 bytes, 9 instructions]
 * Source: src/rom/clear_map_piece_work_cache.s
 * Entry: M=any X=any DB=$7F D=$0000.  Callers read: BCV.
 */
static void clear_map_piece_work_cache(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t x1 = 0;
    for (;;) {
        BUS16_SET(c, 0x7FFF00 + x1, 0);
        x1 = (uint8_t)(x1 + 2);
        if (!(x1 != 0)) break;
    }
    r->a = 0;
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0CBC2, SOM_RTS, "gen", clear_map_piece_work_cache, 0, L_B | L_C | L_V, 1, -1, -1, 15, 9)
