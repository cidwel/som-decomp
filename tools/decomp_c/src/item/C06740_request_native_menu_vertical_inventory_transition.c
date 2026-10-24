#include "som_c.h"

/* C06740 request_native_menu_vertical_inventory_transition   [class A, 53 bytes, 23 instructions]
 * Source: src/rom/request_native_menu_vertical_inventory_transition.s
 * Documented in docs/event-menu-navigation-icons.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void request_native_menu_vertical_inventory_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    uint8_t value = RAM8(0x1806);
    bool x_flag2;
    uint16_t x3;
    uint16_t y3;
    if (value != 0) {
        x_flag2 = 1;
        x3 = x;
        y3 = y;
    } else {
        uint8_t value2 = RAM8(0x1803);
        bool x_flag;
        uint16_t x2;
        uint16_t y2;
        if ((value2 & 0x80) != 0) {
            x_flag = 1;
            x2 = x;
            y2 = y;
        } else {
            uint8_t value3 = RAM8(0x1801);
            uint16_t x1;
            uint16_t y1;
            if ((value3 & 8) != 0) {
                RAM8(0x1812) = 2;
                RAM8(0x1814) = 1;
                RAM8(0x1803) &= 0xBF;
                x1 = 1;
                y1 = 2;
            } else {
                if ((value3 & 4) != 0) {
                    RAM8(0x1812) = 4;
                    RAM8(0x1814) = 0xFF;
                    RAM8(0x1803) &= 0xBF;
                }
                x1 = 0xFFFF;
                y1 = 4;
            }
            x_flag = 0;
            x2 = x1;
            y2 = y1;
        }
        x_flag2 = x_flag;
        x3 = x2;
        y3 = y2;
    }
    r->x = x3;
    r->y = y3;
    r->xf = x_flag2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06740, SOM_RTS, "gen", request_native_menu_vertical_inventory_transition, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 53, 23)
