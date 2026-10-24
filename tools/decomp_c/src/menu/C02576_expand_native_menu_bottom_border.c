#include "som_c.h"

/* C02576 expand_native_menu_bottom_border   [class A, 32 bytes, 16 instructions]
 * Source: src/rom/expand_native_menu_bottom_border.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void expand_native_menu_bottom_border(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM16_SET(0x9000 + x, 0xA020);
    r->a = 0xA024;
    r->x = (uint16_t)(x + 2);
    r->mf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2586, 0xC02596); GUARD_JSR(c, sp_call, 0x2586); } /* expand_native_menu_border_interior_columns */
    r->sp += 2;
    uint16_t x_ret = r->x;
    RAM16_SET(0x9000 + x_ret, 0xE020);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02576, SOM_RTS, "gen", expand_native_menu_bottom_border, 0, 0, 2, 1, 0, 32, 16)
