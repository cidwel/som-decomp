#include "som_c.h"

/* D0D308 clear_native_menu_descriptor_row_attributes   [class A, 17 bytes, 9 instructions]
 * Source: src/rom/clear_native_menu_descriptor_row_attributes.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void clear_native_menu_descriptor_row_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t x1 = 0;
    for (;;) {
        BUS16_SET(c, 0x0018A0 + x1, 0);
        x1 = (uint16_t)(x1 + 2);
        if (!(x1 < 0x20)) break;
    }
    r->a = 0;
    r->x = x1;
    r->y = y;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D308, SOM_RTS, "gen", clear_native_menu_descriptor_row_attributes, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 17, 9)
