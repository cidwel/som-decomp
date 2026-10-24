#include "som_c.h"

/* C0C45D map_header_reserved_return   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/map_header_reserved_return.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BX.
 */
static void map_header_reserved_return(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C45D, SOM_RTS, "gen", map_header_reserved_return, 0, L_B | L_X, 1, 1, 1, 1, 1)
