#include "som_c.h"

/* C066F3 update_native_menu_horizontal_repeat_and_description_request   [class B, 77 bytes, 33 instructions]
 * Source: src/rom/update_native_menu_horizontal_repeat_and_description_request.s
 * Documented in docs/event-menu-navigation-icons.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void update_native_menu_horizontal_repeat_and_description_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    if (RAM8(0x1814) != 0) {
        r->x = (uint8_t)x;
        r->y = (uint8_t)y;
        r->xf = 1;
        RETURN_RTS(c);
    }
    uint8_t value2 = RAM8(0x1801);
    if ((value2 & 1) != 0) {
        uint8_t value3 = RAM8(0x1806);
        bool carry1;
        if (value3 == 0) {
            RAM8(0x1848) = 0x1E;
            RAM8(0x1806) = 0xFF;
            carry1 = carry;
        } else {
            if (value3 != 0xFF) {
                if (RAM8(0x1807) == 0) {
                    RAM8(0x1806) = 0xFF;
                }
            }
            carry1 = value3 <= 0xFF;
        }
        RAM8(0x1802) &= 0xFB;
        r->x = 0xFF;
        r->y = (uint8_t)y;
        r->c = carry1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    if ((value2 & 2) != 0) {
        uint8_t value6 = RAM8(0x1806);
        bool carry2;
        if (value6 == 0) {
            RAM8(0x1848) = 0x1E;
            RAM8(0x1806) = 1;
            carry2 = carry;
        } else {
            if (value6 != 1) {
                if (RAM8(0x1807) == 0) {
                    RAM8(0x1806) = 1;
                }
            }
            carry2 = value6 <= 1;
        }
        RAM8(0x1802) &= 0xFB;
        r->x = 1;
        r->y = (uint8_t)y;
        r->c = carry2;
        r->xf = 1;
        RETURN_RTS(c);
    }
    if (RAM8(0x1807) != 0) {
        r->x = 1;
        r->y = (uint8_t)y;
        r->xf = 1;
        RETURN_RTS(c);
    }
    if (RAM8(0x1806) == 0) {
        RAM8(0x1802) &= 0xFB;
        r->x = 1;
        r->y = (uint8_t)y;
        r->xf = 1;
        RETURN_RTS(c);
    }
    RAM8(0x1802) |= 4;
    RAM8(0x1806) = 0;
    r->y = (uint8_t)y;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x671E, 0xC06B4C); GUARD_JSL(c, sp_call, 0x671E); } /* persist_native_menu_category_row_and_equipment_rank */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC066F3, SOM_RTS, "gen", update_native_menu_horizontal_repeat_and_description_request, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 77, 33)
