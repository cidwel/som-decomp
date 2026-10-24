#include "som_c.h"

/* D0D279 publish_native_inventory_owner_and_rotated_selection_attribute   [class B, 143 bytes, 81 instructions]
 * Source: src/rom/publish_native_inventory_owner_and_rotated_selection_attribute.s
 * Documented in docs/event-menu-inventory-attributes.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void publish_native_inventory_owner_and_rotated_selection_attribute(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x182C);
    uint8_t value2 = RAM8(0xCC00 + x);
    uint8_t ring_category = RAM8(RING_CATEGORY);
    bool m_flag;
    uint8_t a_hi2;
    uint16_t x2;
    if (ring_category != 3) {
        m_flag = 1;
        a_hi2 = (uint16_t)((uint16_t)(x - value) << 1) >> 8;
        x2 = (uint16_t)((uint16_t)(x - value) << 1);
    } else {
        uint8_t a_hi1 = (uint16_t)((uint16_t)(x - value) << 1) >> 8;
        uint16_t x1 = value;
        uint16_t y1 = 0;
        for (;;) {
            if (x1 != x) {
                if (RAM8(0xCC00 + x1) == 0xFF) {
                    uint8_t a_hi1_next = x1 >> 8;
                    uint16_t x1_next = (uint16_t)(x1 + 1);
                    a_hi1 = a_hi1_next;
                    x1 = x1_next;
                    continue;
                }
                uint8_t a_hi1_next2 = x1 >> 8;
                uint16_t x1_next2 = (uint16_t)(x1 + 1);
                uint16_t y1_next = (uint16_t)(y1 + 1);
                a_hi1 = a_hi1_next2;
                x1 = x1_next2;
                y1 = y1_next;
                continue;
            }
            a_hi1 = x1 >> 8;
            break;
        }
        m_flag = 0;
        a_hi2 = (uint16_t)(y1 << 1) >> 8;
        x2 = (uint16_t)(y1 << 1);
    }
    bool m_flag7;
    uint8_t a_hi8;
    uint16_t x8;
    uint16_t y2;
    if ((value2 & 0xC0) == 0) {
        uint8_t value4 = RAM8(0x1803);
        bool m_flag2;
        uint8_t a_hi3;
        uint16_t x3;
        if ((value4 & 2) == 0) {
            m_flag2 = 1;
            a_hi3 = a_hi2;
            x3 = x2;
        } else {
            uint8_t value5 = RAM8(0x182E);
            uint8_t a1;
            if (!((uint8_t)(((uint8_t)x2 >> 1) - value5) & 0x80)) {
                a1 = (uint8_t)(((uint8_t)x2 >> 1) - value5);
            } else {
                a1 = (uint8_t)((uint8_t)((uint8_t)(((uint8_t)x2 >> 1) - value5) + RAM8(RING_ENTRY_COUNT)) - 1);
            }
            m_flag2 = 0;
            a_hi3 = (((a_hi2 << 8) | a1) & 0xFF) << 1 >> 8;
            x3 = (((a_hi2 << 8) | a1) & 0xFF) << 1;
        }
        m_flag7 = m_flag2;
        a_hi8 = a_hi3;
        x8 = x3;
        y2 = 0;
    } else {
        uint8_t ring_owner = RAM8(RING_OWNER);
        bool m_flag6;
        uint8_t a_hi7;
        uint16_t x7;
        if ((uint8_t)((((a_hi2 << 8 | (value2 & 0xC0)) & 0xC0) << 1 << 1 >> 8) - 1) != ring_owner) {
            uint8_t value6 = RAM8(0x1803);
            bool m_flag3;
            uint8_t a_hi4;
            uint16_t x4;
            if ((value6 & 2) == 0) {
                m_flag3 = 1;
                a_hi4 = (uint8_t)(((a_hi2 << 8 | (value2 & 0xC0)) & 0xC0) << 1 << 1);
                x4 = x2;
            } else {
                uint8_t value7 = RAM8(0x182E);
                uint8_t a2;
                if (!((uint8_t)(((uint8_t)x2 >> 1) - value7) & 0x80)) {
                    a2 = (uint8_t)(((uint8_t)x2 >> 1) - value7);
                } else {
                    a2 = (uint8_t)((uint8_t)((uint8_t)(((uint8_t)x2 >> 1) - value7) + RAM8(RING_ENTRY_COUNT)) - 1);
                }
                m_flag3 = 0;
                a_hi4 = ((((uint8_t)(((a_hi2 << 8 | (value2 & 0xC0)) & 0xC0) << 1 << 1) << 8) | a2) & 0xFF) << 1 >> 8;
                x4 = ((((uint8_t)(((a_hi2 << 8 | (value2 & 0xC0)) & 0xC0) << 1 << 1) << 8) | a2) & 0xFF) << 1;
            }
            m_flag6 = m_flag3;
            a_hi7 = a_hi4;
            x7 = x4;
        } else {
            uint8_t value8 = RAM8(0x1803);
            bool m_flag5;
            uint8_t a_hi6;
            uint16_t x6;
            if ((value8 & 2) != 0) {
                bool m_flag4;
                uint8_t a_hi5;
                uint16_t x5;
                if ((value8 & 2) == 0) {
                    m_flag4 = 1;
                    a_hi5 = (uint8_t)(((a_hi2 << 8 | (value2 & 0xC0)) & 0xC0) << 1 << 1);
                    x5 = x2;
                } else {
                    uint8_t value9 = RAM8(0x182E);
                    uint8_t a3;
                    if (!((uint8_t)(((uint8_t)x2 >> 1) - value9) & 0x80)) {
                        a3 = (uint8_t)(((uint8_t)x2 >> 1) - value9);
                    } else {
                        a3 = (uint8_t)((uint8_t)((uint8_t)(((uint8_t)x2 >> 1) - value9) + RAM8(RING_ENTRY_COUNT)) - 1);
                    }
                    m_flag4 = 0;
                    a_hi5 = ((((uint8_t)(((a_hi2 << 8 | (value2 & 0xC0)) & 0xC0) << 1 << 1) << 8) | a3) & 0xFF) << 1 >> 8;
                    x5 = ((((uint8_t)(((a_hi2 << 8 | (value2 & 0xC0)) & 0xC0) << 1 << 1) << 8) | a3) & 0xFF) << 1;
                }
                m_flag5 = m_flag4;
                a_hi6 = a_hi5;
                x6 = x5;
            } else {
                RAM16_SET(0x182E, x2 >> 1);
                m_flag5 = 0;
                a_hi6 = x2 >> 1 >> 8;
                x6 = x2;
            }
            m_flag6 = m_flag5;
            a_hi7 = a_hi6;
            x7 = x6;
        }
        m_flag7 = m_flag6;
        a_hi8 = a_hi7;
        x8 = x7;
        y2 = ((uint8_t)(((a_hi2 << 8 | (value2 & 0xC0)) & 0xC0) << 1 << 1) << 8) | (((a_hi2 << 8 | (value2 & 0xC0)) & 0xC0) << 1 << 1 >> 8);
    }
    BUS16_SET(c, 0x0018A0 + x8, y2);
    r->a = a;
    r->x = x;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D279, SOM_RTS, "gen", publish_native_inventory_owner_and_rotated_selection_attribute, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 8, 0, 0, 143, 81)
