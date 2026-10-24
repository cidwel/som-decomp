#include "som_c.h"

/* C027E0 configure_native_menu_background_and_scroll_ports   [class D, 62 bytes, 27 instructions]
 * Source: src/rom/configure_native_menu_background_and_scroll_ports.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void configure_native_menu_background_and_scroll_ports(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS8_SET(c, 0x002105, 5);
    BUS8_SET(c, 0x002107, 0x48);
    BUS8_SET(c, 0x002108, 0x58);
    BUS8_SET(c, 0x00210B, 0x64);
    BUS8_SET(c, 0x00210F, 0);
    BUS8_SET(c, 0x00210F, 0);
    BUS8_SET(c, 0x002106, 0);
    BUS8_SET(c, 0x002110, 0xFF);
    BUS8_SET(c, 0x002110, 0xFF);
    BUS8_SET(c, 0x002130, 0x30);
    BUS8_SET(c, 0x00212C, 0x13);
    BUS8_SET(c, 0x00212D, 0x13);
    BUS8_SET(c, 0x002101, 2);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC027E0, SOM_RTS, "gen", configure_native_menu_background_and_scroll_ports, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 62, 27)
