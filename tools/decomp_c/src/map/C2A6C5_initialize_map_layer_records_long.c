#include "som_c.h"

/* C2A6C5 initialize_map_layer_records_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_map_layer_records_long.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_map_layer_records_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xA6C7, 0xC2A6C9); /* initialize_map_layer_records */
    r->mf = true;
    r->xf = true;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A6C5, SOM_RTL, "hand", initialize_map_layer_records_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 4, 2)
