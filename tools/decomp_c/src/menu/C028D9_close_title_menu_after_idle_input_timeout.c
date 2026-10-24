#include "som_c.h"

/* C028D9 close_title_menu_after_idle_input_timeout   [class A, 38 bytes, 16 instructions]
 * Source: src/rom/close_title_menu_after_idle_input_timeout.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYV.
 */
static void close_title_menu_after_idle_input_timeout(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0xA202);
    uint16_t y2;
    if (value != 0) {
        y2 = y;
    } else {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xA203);
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xA204);
        uint16_t y1;
        if ((value2 | value3) != 0) {
            BUS16_SET(c, (db << 0x10) + 0xA213, 0);
            y1 = 0;
        } else {
            uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0xA213);
            if ((uint16_t)(value4 + 1) != 0x0708) {
                BUS16_SET(c, (db << 0x10) + 0xA213, (uint16_t)(value4 + 1));
            } else {
                uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0xA20A);
                BUS8_SET(c, (db << 0x10) + 0xA20A, value5 | 1);
            }
            y1 = (uint16_t)(value4 + 1);
        }
        y2 = y1;
    }
    r->y = y2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC028D9, SOM_RTS, "gen", close_title_menu_after_idle_input_timeout, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 38, 16)
