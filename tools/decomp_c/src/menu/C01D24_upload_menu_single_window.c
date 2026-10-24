#include "som_c.h"

/* C01D24 upload_menu_single_window   [class D, 46 bytes, 18 instructions]
 * Source: src/rom/upload_menu_single_window.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void upload_menu_single_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if (RAM8(0x1D05) != 7) {
        BUS16_SET(c, 0x002116, RAM16(0x1D06));
        BUS16_SET(c, 0x004375, RAM16(0x1D08));
        BUS8_SET(c, 0x004370, 1);
        BUS8_SET(c, 0x004371, 0x18);
        BUS16_SET(c, 0x004372, 0x9400);
        BUS8_SET(c, 0x004374, 0x7E);
        BUS8_SET(c, 0x00420B, 0x80);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01D24, SOM_RTS, "gen", upload_menu_single_window, 0, 0, 1, 1, 0, 46, 18)
