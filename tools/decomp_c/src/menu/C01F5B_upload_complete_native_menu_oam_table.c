#include "som_c.h"

/* C01F5B upload_complete_native_menu_oam_table   [class D, 45 bytes, 20 instructions]
 * Source: src/rom/upload_complete_native_menu_oam_table.s
 * Documented in docs/event-menu-controller.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void upload_complete_native_menu_oam_table(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS16_SET(c, 0x002102, 0);
    BUS8_SET(c, 0x004370, 0);
    BUS8_SET(c, 0x004371, 4);
    BUS16_SET(c, 0x004372, 0x9C00);
    BUS8_SET(c, 0x004374, 0x7E);
    BUS16_SET(c, 0x004375, 0x0220);
    BUS8_SET(c, 0x00420B, 0x80);
    r->x = 0x0220;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01F5B, SOM_RTS, "gen", upload_complete_native_menu_oam_table, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 45, 20)
