#include "som_c.h"

/* D9FC90 check_native_menu_inventory_availability   [class B, 45 bytes, 21 instructions]
 * Source: src/rom/check_native_menu_inventory_availability.s
 * Documented in docs/event-menu-inventory-gate.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void check_native_menu_inventory_availability(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x1847);
    if (value == 0) {
        uint8_t a_hi1 = a >> 8;
        uint16_t x1 = 0x24;
        uint16_t y1 = 0x0C;
        for (;;) {
            uint8_t value2 = RAM8(0xCC00 + x1);
            if (value2 < 0xFE) {
                r->a = (a_hi1 << 8) | 1;
                r->x = x1;
                r->y = y1;
                r->c = value2 >= 0xFE;
                r->z = 0;
                r->n = 0;
                r->v = overflow;
                r->mf = 1;
                RETURN_RTL(c);
            }
            if ((uint16_t)(y1 + 1) < 0x30) {
                x1 = (uint16_t)(x1 + 1);
                y1 = (uint16_t)(y1 + 1);
                continue;
            }
            r->a = (a_hi1 << 8) | 0;
            r->x = (uint16_t)(x1 + 1);
            r->y = (uint16_t)(y1 + 1);
            r->c = (uint16_t)(y1 + 1) >= 0x30;
            r->z = 1;
            r->n = 0;
            r->v = overflow;
            r->mf = 1;
            RETURN_RTL(c);
        }
    }
    if (value != 2) {
        SET_A8(r, 1);
        r->c = value >= 2;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        RETURN_RTL(c);
    }
    uint8_t a_hi2 = a >> 8;
    uint16_t x2 = 0x24;
    uint16_t y2 = 0;
    for (;;) {
        uint8_t value3 = RAM8(0xCC00 + x2);
        if (value3 < 0xFE) {
            r->a = (a_hi2 << 8) | 1;
            r->x = x2;
            r->y = y2;
            r->c = value3 >= 0xFE;
            r->z = 0;
            r->n = 0;
            r->v = overflow;
            r->mf = 1;
            RETURN_RTL(c);
        }
        if ((uint16_t)(y2 + 1) < 0x30) {
            x2 = (uint16_t)(x2 + 1);
            y2 = (uint16_t)(y2 + 1);
            continue;
        }
        r->a = (a_hi2 << 8) | 0;
        r->x = (uint16_t)(x2 + 1);
        r->y = (uint16_t)(y2 + 1);
        r->c = (uint16_t)(y2 + 1) >= 0x30;
        r->z = 1;
        r->n = 0;
        r->v = overflow;
        r->mf = 1;
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xD9FC90, SOM_RTL, "gen", check_native_menu_inventory_availability, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 45, 21)
