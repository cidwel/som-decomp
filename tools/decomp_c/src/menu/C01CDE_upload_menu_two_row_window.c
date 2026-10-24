#include "som_c.h"

/* C01CDE upload_menu_two_row_window   [class D, 70 bytes, 34 instructions]
 * Source: src/rom/upload_menu_two_row_window.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void upload_menu_two_row_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    if (RAM8(0x1D05) == 7) {
        uint16_t value2 = RAM16(0x1D06);
        uint8_t a1 = 2;
        uint8_t a_hi1 = a_hi;
        uint16_t x1 = value2;
        uint16_t y1 = 0x9400;
        for (;;) {
            BUS16_SET(c, 0x002116, x1);
            uint16_t value3 = RAM16(0x1D08);
            BUS16_SET(c, 0x004375, value3);
            BUS8_SET(c, 0x004370, 1);
            BUS8_SET(c, 0x004371, 0x18);
            BUS16_SET(c, 0x004372, y1);
            BUS8_SET(c, 0x004374, 0x7E);
            BUS8_SET(c, 0x00420B, 0x80);
            uint16_t value4 = RAM16(0x1D18);
            uint8_t a1_next = (uint8_t)(a1 - 1);
            uint8_t a_hi1_next = (uint16_t)(y1 + value3) >> 8;
            uint16_t x1_next = (uint16_t)(x1 + value4);
            uint16_t y1_next = (uint16_t)(y1 + value3);
            a1 = a1_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            if (!(a1 != 0)) break;
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01CDE, SOM_RTS, "gen", upload_menu_two_row_window, 0, 0, 3, 1, 0, 70, 34)
