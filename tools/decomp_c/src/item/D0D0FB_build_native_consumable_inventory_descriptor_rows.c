#include "som_c.h"

/* D0D0FB build_native_consumable_inventory_descriptor_rows   [class B, 179 bytes, 83 instructions]
 * Source: src/rom/build_native_consumable_inventory_descriptor_rows.s
 * Documented in docs/event-menu-inventory-rows.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void build_native_consumable_inventory_descriptor_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = 0x0C;
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t inventory_consumables = RAM16(INVENTORY_CONSUMABLES + x1);
        uint8_t a_hi3;
        uint16_t x3;
        uint16_t y3;
        bool carry3;
        bool overflow3;
        if ((inventory_consumables & 0xFF) == 0xFF) {
            a_hi3 = 0;
            x3 = x1;
            y3 = y1;
            carry3 = (inventory_consumables & 0xFF) >= 0xFF;
            overflow3 = overflow1;
        } else {
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            bool carry2;
            bool overflow2;
            if ((inventory_consumables & 0x1F) >= 0x0D) {
                a_hi2 = 0;
                x2 = x1;
                y2 = y1;
                carry2 = (inventory_consumables & 0x1F) >= 0x0D;
                overflow2 = overflow1;
            } else {
                r->a = inventory_consumables & 0x1F;
                r->x = x1;
                r->y = y1;
                r->mf = false;
                r->xf = false;
                r->db = 0;
                r->dp = 0;
                r->sp -= 2;
                JSR(c, 0xD118, 0xD0D263); /* append_native_menu_descriptor_from_category_table */
                r->sp += 2;
                uint16_t a_all = r->a;
                uint16_t x_ret = r->x;
                uint16_t y_ret = r->y;
                bool carry_ret = r->c;
                bool overflow_ret = r->v;
                a_hi2 = a_all >> 8;
                x2 = x_ret;
                y2 = y_ret;
                carry2 = carry_ret;
                overflow2 = overflow_ret;
            }
            a_hi3 = a_hi2;
            x3 = x2;
            y3 = y2;
            carry3 = carry2;
            overflow3 = overflow2;
        }
        bool again = (uint16_t)(((a_hi1 << 8) | a1) - 1) != 0;
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) - 1);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) - 1) >> 8;
        uint16_t x1_next = (uint16_t)(x3 + 1);
        uint16_t y1_next = y3;
        bool carry1_next = carry3;
        bool overflow1_next = overflow3;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!again) break;
    }
    uint16_t value = RAM16(0x1873);
    RAM16_SET(0x182E, value & 0xFF);
    uint8_t a2 = value & 0xFF;
    uint8_t a_hi4 = 0;
    bool zero1 = (value & 0xFF) == 0;
    bool negative1 = value & 0xFF & 0x8000;
    for (;;) {
        r->a = (a_hi4 << 8) | a2;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = false;
        r->xf = false;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t a3 = 7;
    uint8_t a_hi5 = 0;
    uint16_t x4 = 0;
    uint16_t y4 = y1;
    bool overflow4 = overflow1;
    for (;;) {
        uint8_t ring_owner = RAM8(RING_OWNER);
        uint8_t a5;
        if ((uint8_t)(ring_owner - 1) != 0) {
            a5 = RAM8(0xE5C8 + x4);
        } else {
            uint8_t value3 = RAM8(0xE3C8 + x4);
            uint8_t a4;
            if (x4 != 6) {
                a4 = value3;
            } else {
                a4 = RAM8(0xE3C9 + x4);
            }
            a5 = a4;
        }
        uint8_t a_hi8;
        uint16_t y5;
        bool overflow5;
        if ((((a_hi5 << 8) | a5) & 0xFF) == 0) {
            a_hi8 = 0;
            y5 = y4;
            overflow5 = overflow4;
        } else {
            uint16_t value5 = RAM16(0x1828);
            uint8_t a_hi7;
            uint16_t x7;
            if ((uint16_t)(x4 + 0) < 6) {
                a_hi7 = (uint16_t)(x4 + 0) >> 8;
                x7 = (uint16_t)((uint16_t)((uint16_t)(x4 + 0) << 1) + value5);
            } else {
                uint16_t ring_owner2 = RAM16(RING_OWNER);
                uint8_t a_hi6;
                uint16_t x6;
                if ((ring_owner2 & 0xFF) != 2) {
                    a_hi6 = 0;
                    x6 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(x4 + 0) << 1) + value5) + 2);
                } else {
                    uint16_t x5;
                    if ((uint16_t)(x4 + 0) != 6) {
                        x5 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(x4 + 0) << 1) + value5) + 2);
                    } else {
                        x5 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(x4 + 0) << 1) + value5) + 0);
                    }
                    a_hi6 = (uint16_t)(x4 + 0) >> 8;
                    x6 = x5;
                }
                a_hi7 = a_hi6;
                x7 = x6;
            }
            uint16_t value6 = BUS16(c, 0xD8FD60 + x7);
            RAM16_SET(0x0000 + y4, value6);
            a_hi8 = value6 >> 8;
            y5 = (uint16_t)(y4 + 2);
            overflow5 = (((uint16_t)((uint16_t)(x4 + 0) << 1) ^ (uint16_t)((uint16_t)((uint16_t)(x4 + 0) << 1) + value5)) & (value5 ^ (uint16_t)((uint16_t)((uint16_t)(x4 + 0) << 1) + value5)) & 0x8000) != 0;
        }
        bool again2 = (uint16_t)(((a_hi5 << 8) | a3) - 1) != 0;
        uint8_t a3_next = (uint8_t)(((a_hi5 << 8) | a3) - 1);
        uint8_t a_hi5_next = (uint16_t)(((a_hi5 << 8) | a3) - 1) >> 8;
        uint16_t x4_next = (uint16_t)(x4 + 1);
        uint16_t y4_next = y5;
        bool overflow4_next = overflow5;
        a3 = a3_next;
        a_hi5 = a_hi5_next;
        x4 = x4_next;
        y4 = y4_next;
        overflow4 = overflow4_next;
        if (!again2) break;
    }
    uint16_t value7 = RAM16(0x1874);
    uint16_t ring_owner3 = RAM16(RING_OWNER);
    uint8_t a_hi9;
    uint16_t x8;
    if ((ring_owner3 & 0xFF) == 1) {
        a_hi9 = 0;
        x8 = value7;
    } else {
        uint16_t value8 = RAM16(0x1875);
        a_hi9 = value8 >> 8;
        x8 = value8;
    }
    RAM16_SET(0x182E, x8 & 0xFF);
    r->a = x8 & 0xFF;
    r->x = x8;
    r->y = y4;
    r->c = (ring_owner3 & 0xFF) >= 1;
    r->z = (x8 & 0xFF) == 0;
    r->n = x8 & 0xFF & 0x8000;
    r->v = overflow4;
    r->mf = false;
    r->xf = false;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D0FB, SOM_RTS, "hand", build_native_consumable_inventory_descriptor_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 0, 0, 179, 83)
