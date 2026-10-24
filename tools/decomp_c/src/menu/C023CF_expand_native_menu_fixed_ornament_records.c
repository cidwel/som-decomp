#include "som_c.h"

/* C023CF expand_native_menu_fixed_ornament_records   [class B, 116 bytes, 64 instructions]
 * Source: src/rom/expand_native_menu_fixed_ornament_records.s
 * Documented in docs/event-menu-font-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void expand_native_menu_fixed_ornament_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xA20D);
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0xC7;
    uint16_t value2 = BUS16(c, 0xC70000 + (uint16_t)(value + 4));
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = value2;
    for (;;) {
        uint8_t value3 = BUS8(c, 0xC70000 + y1);
        if (value3 != 0) {
            uint16_t value4 = BUS16(c, 0xC70000 + (uint16_t)(y1 + 1));
            RAM8(0x9000 + value4) = value3;
            RAM8(0x9040 + value4) = (uint8_t)(value3 + 2);
            RAM8(0x9001 + value4) = 0x20;
            RAM8(0x9041 + value4) = 0x20;
            a_hi1 = (uint8_t)(value3 + 2);
            y1 = (uint16_t)(y1 + 3);
            continue;
        }
        a_hi1 = 0x20;
        break;
    }
    uint8_t a1 = 0;
    uint8_t a_hi2 = a_hi1;
    uint16_t y2 = (uint16_t)(y1 + 1);
    for (;;) {
        uint8_t value5 = BUS8(c, 0xC70000 + y2);
        if (value5 != 0) {
            uint8_t value6 = BUS8(c, 0xC70000 + (uint16_t)(y2 + 1));
            uint16_t value7 = BUS16(c, 0xC70000 + (uint16_t)(y2 + 2));
            uint8_t a2 = value5;
            uint8_t a_hi3 = value6;
            uint16_t x1 = value7;
            for (;;) {
                RAM8(0x9000 + x1) = a_hi3;
                RAM8(0x9040 + x1) = (uint8_t)(a_hi3 + 2);
                RAM8(0x0000 + sp0 - 1) = (uint8_t)(a_hi3 + 4);
                RAM8(0x9001 + x1) = 0x20;
                RAM8(0x9041 + x1) = 0x20;
                uint8_t value8 = RAM8(0x0000 + sp0 - 1);
                a2 = (uint8_t)(a2 - 1);
                a_hi3 = value8;
                x1 = (uint16_t)(x1 + 2);
                if (!(a2 != 0)) break;
            }
            a1 = a2;
            a_hi2 = a_hi3;
            y2 = (uint16_t)(y2 + 4);
            continue;
        }
        a1 = value5;
        break;
    }
    uint8_t value9 = RAM8(0x0000 + sp0);
    uint8_t a3;
    if (a_hi2 != 0x20) {
        a3 = a_hi2;
    } else {
        a3 = 0x50;
    }
    BUS16_SET(c, (value9 << 0x10) + 0xA1C7, ((a1 | 0x20) << 8) | a3);
    r->a = ((a1 | 0x20) << 8) | a3;
    r->x = ((a1 | 0x20) << 8) | a3;
    r->y = y2;
    r->v = overflow;
    r->db = value9;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC023CF, SOM_RTS, "gen", expand_native_menu_fixed_ornament_records, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 116, 64)
