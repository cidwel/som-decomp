#include "som_c.h"

/* D0D319 rotate_native_menu_descriptor_rows_and_append_category_tail   [class B, 126 bytes, 54 instructions]
 * Source: src/rom/rotate_native_menu_descriptor_rows_and_append_category_tail.s
 * Documented in docs/event-menu-descriptor-order.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void rotate_native_menu_descriptor_rows_and_append_category_tail(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x1847);
    bool m_flag;
    uint8_t a_hi1;
    if (value != 3) {
        m_flag = 1;
        a_hi1 = a_hi;
    } else {
        RAM16_SET(0x182E, ((a_hi << 8) | RAM8(0x1846)) & 0xFF);
        m_flag = 0;
        a_hi1 = 0;
    }
    uint16_t value3 = RAM16(0x182E);
    uint8_t a_hi4;
    uint16_t x3;
    if (value3 == 0) {
        a_hi4 = value3 >> 8;
        x3 = x;
    } else {
        uint8_t a1 = (uint8_t)value3;
        uint8_t a_hi2 = value3 >> 8;
        uint16_t x1 = x;
        for (;;) {
            uint16_t value4 = RAM16(0x1880 + 0);
            uint16_t value5 = RAM16(0x18A0 + 0);
            uint8_t a_hi3 = value5 >> 8;
            uint16_t x2 = 0;
            for (;;) {
                uint16_t value6 = BUS16(c, 0x1882 + x2);
                if (value6 != 0xFFFF) {
                    BUS16_SET(c, 0x1880 + x2, value6);
                    uint16_t value7 = BUS16(c, 0x18A2 + x2);
                    BUS16_SET(c, 0x18A0 + x2, value7);
                    a_hi3 = value7 >> 8;
                    x2 = (uint16_t)(x2 + 2);
                    continue;
                }
                a_hi3 = value6 >> 8;
                break;
            }
            BUS16_SET(c, 0x18A0 + x2, value5);
            BUS16_SET(c, 0x1880 + x2, value4);
            bool again = (uint16_t)(((a_hi2 << 8) | a1) - 1) != 0;
            uint8_t a1_next = (uint8_t)(((a_hi2 << 8) | a1) - 1);
            uint8_t a_hi2_next = (uint16_t)(((a_hi2 << 8) | a1) - 1) >> 8;
            uint16_t x1_next = x2;
            a1 = a1_next;
            a_hi2 = a_hi2_next;
            x1 = x1_next;
            if (!again) break;
        }
        a_hi4 = a_hi2;
        x3 = x1;
    }
    uint16_t ring_category = RAM16(RING_CATEGORY);
    uint8_t a_hi7;
    uint16_t x6;
    bool carry3;
    bool zero2;
    if ((ring_category & 0xFF) < 4) {
        a_hi7 = 0;
        x6 = x3;
        carry3 = (ring_category & 0xFF) >= 4;
        zero2 = (ring_category & 0xFF) == 4;
    } else {
        uint16_t value8 = RAM16(0x1847);
        uint8_t a_hi6;
        uint16_t x5;
        bool carry2;
        bool zero1;
        if ((value8 & 0xFF) != 0) {
            a_hi6 = 0;
            x5 = x3;
            carry2 = (ring_category & 0xFF) >= 4;
            zero1 = (value8 & 0xFF) == 0;
        } else {
            uint8_t a2 = value8 & 0xFF;
            uint8_t a_hi5 = 0;
            uint16_t x4 = 0;
            bool carry1 = (ring_category & 0xFF) >= 4;
            for (;;) {
                uint16_t value9 = BUS16(c, 0x1880 + x4);
                if (value9 != 0xFFFF) {
                    a2 = (uint8_t)value9;
                    a_hi5 = value9 >> 8;
                    x4 = (uint16_t)(x4 + 2);
                    carry1 = value9 >= 0xFFFF;
                    continue;
                }
                a2 = (uint8_t)value9;
                a_hi5 = value9 >> 8;
                carry1 = value9 >= 0xFFFF;
                break;
            }
            BUS16_SET(c, 0x1882 + x4, (a_hi5 << 8) | a2);
            uint16_t value10 = BUS16(c, 0xD8FF16);
            BUS16_SET(c, 0x1880 + x4, value10);
            BUS16_SET(c, 0x1882 + x4, 0xFFFF);
            a_hi6 = 0xFF;
            x5 = x4;
            carry2 = carry1;
            zero1 = 0;
        }
        a_hi7 = a_hi6;
        x6 = x5;
        carry3 = carry2;
        zero2 = zero1;
    }
    r->a = (a_hi7 << 8) | a;
    r->x = x6;
    r->y = y;
    r->c = carry3;
    r->z = zero2;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D319, SOM_RTS, "hand", rotate_native_menu_descriptor_rows_and_append_category_tail, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 6, 1, 0, 126, 54)
