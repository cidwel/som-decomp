#include "som_c.h"

static void test_native_hero_status_against_category_row_mask(SomCtx *c);

/* D9FCC1 dispatch_native_inventory_status_masks_by_mode_and_category   [class C, 288 bytes, 133 instructions]
 * Source: src/rom/dispatch_native_inventory_status_masks_by_mode_and_category.s
 * Documented in docs/event-menu-inventory-masks.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void dispatch_native_inventory_status_masks_by_mode_and_category(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x1847);
    if (value != 3) {
        uint16_t value2 = RAM16(0x1844);
        if ((RAM8(0x0011 + value2) & 4) != 0) {
            uint8_t a_hi1 = value2 >> 8;
            uint16_t x1 = 0;
            uint16_t y1 = y;
            bool carry1 = value >= 3;
            bool zero1 = 1;
            bool overflow1 = overflow;
            for (;;) {
                r->a = (a_hi1 << 8) | (uint8_t)a;
                r->x = x1;
                r->y = y1;
                r->v = overflow1;
                r->mf = 0;
                r->xf = 0;
                r->db = 0;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xFD79, 0xD9FE08); GUARD_JSR(c, sp_call, 0xFD79); } /* set_native_inventory_descriptor_disabled_flag */
                uint16_t a_all = r->a;
                uint8_t a_hi1_next = a_all >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 2);
                bool carry1_next = (uint16_t)(x1 + 2) >= 0x20;
                bool zero1_next = (uint16_t)(x1 + 2) == 0x20;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                carry1 = carry1_next;
                zero1 = zero1_next;
                if (!(x1 < 0x20)) break;
            }
            r->a = (a_hi1 << 8) | (uint8_t)a;
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->z = zero1;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint16_t ring_category = RAM16(RING_CATEGORY);
        r->a = (ring_category & 0xFF) << 1 << 1;
        r->x = (ring_category & 0xFF) << 1 << 1;
        r->c = (ring_category & 0xFF) << 1 & 0x8000;
        r->z = (ring_category & 0xFF) << 1 << 1 == 0;
        r->n = (ring_category & 0xFF) << 1 << 1 & 0x8000;
        switch ((ring_category & 0xFF) << 1 << 1) {
        case 0x0000: test_native_hero_status_against_category_row_mask(c); return;
        default: TAIL_CALL(c, 0xD90000 | BUS16(c, 0xD90000 + (uint16_t)(0xFD10 + ((ring_category & 0xFF) << 1 << 1))), SOM_RTS);
        }
    }
    uint8_t a_hi2 = a >> 8;
    uint16_t x2 = 0;
    uint16_t y2 = 0;
    bool carry2 = value >= 3;
    bool zero2 = 1;
    bool overflow2 = overflow;
    for (;;) {
        uint8_t inventory_weapons = RAM8(INVENTORY_WEAPONS + x2);
        uint8_t a_hi5;
        uint16_t x5;
        uint16_t y3;
        bool overflow5;
        if (inventory_weapons == 0xFF) {
            a_hi5 = a_hi2;
            x5 = x2;
            y3 = y2;
            overflow5 = overflow2;
        } else {
            uint8_t value4 = RAM8(0xCFB0 + x2);
            uint8_t a_hi4;
            uint16_t x4;
            bool overflow4;
            if (value4 >= 8) {
                r->a = (a_hi2 << 8) | value4;
                r->x = x2;
                r->y = y2;
                r->c = value4 >= 8;
                r->z = value4 == 8;
                r->n = (uint8_t)(value4 - 8) & 0x80;
                r->v = overflow2;
                r->mf = 1;
                r->xf = 0;
                r->db = 0;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xFCE8, 0xD9FDFD); GUARD_JSR(c, sp_call, 0xFCE8); } /* mark_native_inventory_descriptor_row_at_current_y */
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all2 = r->a;
                uint16_t x_ret = r->x;
                bool overflow_ret = r->v;
                a_hi4 = a_all2 >> 8;
                x4 = x_ret;
                overflow4 = overflow_ret;
            } else {
                uint8_t value5 = RAM8(0xCFB8 + x2);
                uint8_t a_hi3;
                uint16_t x3;
                bool overflow3;
                if (value4 < value5) {
                    a_hi3 = a_hi2;
                    x3 = x2;
                    overflow3 = overflow2;
                } else {
                    r->a = (a_hi2 << 8) | value4;
                    r->x = x2;
                    r->y = y2;
                    r->c = value4 >= value5;
                    r->z = value4 == value5;
                    r->n = (uint8_t)(value4 - value5) & 0x80;
                    r->v = overflow2;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xFCE8, 0xD9FDFD); GUARD_JSR(c, sp_call, 0xFCE8); } /* mark_native_inventory_descriptor_row_at_current_y */
                    if (r->mf != 1) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all3 = r->a;
                    uint16_t x_ret2 = r->x;
                    bool overflow_ret2 = r->v;
                    a_hi3 = a_all3 >> 8;
                    x3 = x_ret2;
                    overflow3 = overflow_ret2;
                }
                a_hi4 = a_hi3;
                x4 = x3;
                overflow4 = overflow3;
            }
            a_hi5 = a_hi4;
            x5 = x4;
            y3 = (uint16_t)(y2 + 2);
            overflow5 = overflow4;
        }
        a_hi2 = a_hi5;
        x2 = (uint16_t)(x5 + 1);
        y2 = y3;
        carry2 = (uint16_t)(x5 + 1) >= 8;
        zero2 = (uint16_t)(x5 + 1) == 8;
        overflow2 = overflow5;
        if (!(x2 < 8)) break;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = zero2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD9FCC1, SOM_RTS, "gen", dispatch_native_inventory_status_masks_by_mode_and_category, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 0, 316, 133)

/* D9FD46 test_native_hero_status_against_category_row_mask   [class A, 183 bytes, 84 instructions]
 * Source: src/rom/dispatch_native_inventory_status_masks_by_mode_and_category.s
 * Subroutine of dispatch_native_inventory_status_masks_by_mode_and_category, translated in place.
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void test_native_hero_status_against_category_row_mask(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM16_SET(0x1820, RAM16(0x0010 + RAM16(0x1844)));
    uint16_t value3 = BUS16(c, 0xD9FD12 + x);
    uint16_t value4 = RAM16(0x1820);
    if ((value3 & value4) != 0) {
        uint8_t ring_category = RAM8(RING_CATEGORY);
        if ((uint8_t)(ring_category - 2) == 0) {
            uint8_t a1 = (uint8_t)(ring_category - 2);
            uint8_t a_hi1 = (value3 & value4) >> 8;
            uint16_t x1 = 0;
            uint16_t y1 = y;
            bool carry1 = carry;
            bool zero1 = 1;
            bool negative1 = 0;
            bool overflow1 = overflow;
            for (;;) {
                uint16_t value5 = BUS16(c, 0xD9FE12 + x1);
                uint16_t value6 = RAM16(0x1820);
                uint8_t a2;
                uint8_t a_hi2;
                if ((value5 & value6) == 0) {
                    a2 = (uint8_t)(value5 & value6);
                    a_hi2 = (value5 & value6) >> 8;
                } else {
                    r->a = value5 & value6;
                    r->x = x1;
                    r->y = y1;
                    r->v = overflow1;
                    r->mf = 0;
                    r->xf = 0;
                    r->db = 0;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xFDF4, 0xD9FE08); GUARD_JSR(c, sp_call, 0xFDF4); } /* set_native_inventory_descriptor_disabled_flag */
                    uint16_t a_all = r->a;
                    a2 = (uint8_t)a_all;
                    a_hi2 = a_all >> 8;
                }
                uint8_t a1_next = a2;
                uint8_t a_hi1_next = a_hi2;
                uint16_t x1_next = (uint16_t)(x1 + 2);
                bool carry1_next = (uint16_t)(x1 + 2) >= 0x0E;
                bool zero1_next = (uint16_t)(x1 + 2) == 0x0E;
                bool negative1_next = (uint16_t)((uint16_t)(x1 + 2) - 0x0E) & 0x8000;
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                carry1 = carry1_next;
                zero1 = zero1_next;
                negative1 = negative1_next;
                if (!(x1 < 0x0E)) break;
            }
            r->a = (a_hi1 << 8) | a1;
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t a3 = (uint8_t)(ring_category - 2);
        uint8_t a_hi3 = (value3 & value4) >> 8;
        uint16_t x2 = 0;
        uint16_t y2 = y;
        bool carry2 = carry;
        bool zero2 = 1;
        bool negative2 = 0;
        bool overflow2 = overflow;
        for (;;) {
            r->a = (a_hi3 << 8) | a3;
            r->x = x2;
            r->y = y2;
            r->v = overflow2;
            r->mf = 0;
            r->xf = 0;
            r->db = 0;
            r->dp = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFD79, 0xD9FE08); GUARD_JSR(c, sp_call, 0xFD79); } /* set_native_inventory_descriptor_disabled_flag */
            uint16_t a_all2 = r->a;
            uint8_t a3_next = (uint8_t)a_all2;
            uint8_t a_hi3_next = a_all2 >> 8;
            uint16_t x2_next = (uint16_t)(x2 + 2);
            bool carry2_next = (uint16_t)(x2 + 2) >= 0x20;
            bool zero2_next = (uint16_t)(x2 + 2) == 0x20;
            bool negative2_next = (uint16_t)((uint16_t)(x2 + 2) - 0x20) & 0x8000;
            a3 = a3_next;
            a_hi3 = a_hi3_next;
            x2 = x2_next;
            carry2 = carry2_next;
            zero2 = zero2_next;
            negative2 = negative2_next;
            if (!(x2 < 0x20)) break;
        }
        r->a = (a_hi3 << 8) | a3;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->z = zero2;
        r->n = negative2;
        r->v = overflow2;
        r->mf = 0;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t ring_category2 = RAM8(RING_CATEGORY);
    if (ring_category2 == 3) {
        uint8_t a4 = ring_category2;
        uint8_t a_hi4 = (value3 & value4) >> 8;
        uint16_t x3 = 0;
        uint16_t y3 = 0;
        bool carry3 = ring_category2 >= 3;
        bool zero3 = 1;
        bool negative3 = 0;
        bool overflow3 = overflow;
        for (;;) {
            uint8_t value7 = RAM8(0xCC78);
            bool m_flag18;
            uint8_t a22;
            uint8_t a_hi22;
            uint16_t x21;
            uint16_t y13;
            bool overflow21;
            if (value7 == 0) {
                uint8_t inventory_weapons = RAM8(INVENTORY_WEAPONS + x3);
                bool m_flag3;
                uint8_t a7;
                uint8_t a_hi7;
                uint16_t x6;
                uint16_t y4;
                bool overflow6;
                if (inventory_weapons == 0xFF) {
                    m_flag3 = 1;
                    a7 = inventory_weapons;
                    a_hi7 = a_hi4;
                    x6 = x3;
                    y4 = y3;
                    overflow6 = overflow3;
                } else {
                    bool m_flag2;
                    uint8_t a6;
                    uint8_t a_hi6;
                    uint16_t x5;
                    bool overflow5;
                    if ((inventory_weapons & 0xC0) == 0) {
                        m_flag2 = 1;
                        a6 = inventory_weapons & 0xC0;
                        a_hi6 = a_hi4;
                        x5 = x3;
                        overflow5 = overflow3;
                    } else {
                        RAM8(0x0000 + sp0) = x3 >> 8;
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)x3;
                        uint8_t value8 = RAM8(0xE01C + (uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1));
                        bool m_flag;
                        uint8_t a5;
                        uint8_t a_hi5;
                        uint16_t x4;
                        bool overflow4;
                        if (value8 == 0) {
                            m_flag = 1;
                            a5 = value8;
                            a_hi5 = (uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1) >> 8;
                            x4 = x3;
                            overflow4 = (((((a_hi4 << 8 | (inventory_weapons & 0xC0)) & 0xFF) << 1 << 1) ^ 0x0100) & ((((a_hi4 << 8 | (inventory_weapons & 0xC0)) & 0xFF) << 1 << 1) ^ (uint16_t)((((a_hi4 << 8 | (inventory_weapons & 0xC0)) & 0xFF) << 1 << 1) - 0x0100)) & 0x8000) != 0;
                        } else {
                            r->a = ((uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1) >> 8 << 8) | value8;
                            r->x = x3;
                            r->y = y3;
                            r->c = value8 >= 0;
                            r->z = value8 == 0;
                            r->n = value8 & 0x80;
                            r->v = (((((a_hi4 << 8 | (inventory_weapons & 0xC0)) & 0xFF) << 1 << 1) ^ 0x0100) & ((((a_hi4 << 8 | (inventory_weapons & 0xC0)) & 0xFF) << 1 << 1) ^ (uint16_t)((((a_hi4 << 8 | (inventory_weapons & 0xC0)) & 0xFF) << 1 << 1) - 0x0100)) & 0x8000) != 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0;
                            r->dp = 0;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xFDDA, 0xD9FDFD); GUARD_JSR(c, sp_call, 0xFDDA); } /* mark_native_inventory_descriptor_row_at_current_y */
                            bool m_ret = r->mf;
                            if (r->xf != 0) { c->fail = 3; return; }
                            uint16_t a_all3 = r->a;
                            uint16_t x_ret = r->x;
                            bool overflow_ret = r->v;
                            m_flag = m_ret;
                            a5 = (uint8_t)a_all3;
                            a_hi5 = a_all3 >> 8;
                            x4 = x_ret;
                            overflow4 = overflow_ret;
                        }
                        m_flag2 = m_flag;
                        a6 = a5;
                        a_hi6 = a_hi5;
                        x5 = x4;
                        overflow5 = overflow4;
                    }
                    m_flag3 = m_flag2;
                    a7 = a6;
                    a_hi7 = a_hi6;
                    x6 = x5;
                    y4 = (uint16_t)(y3 + 2);
                    overflow6 = overflow5;
                }
                m_flag18 = m_flag3;
                a22 = a7;
                a_hi22 = a_hi7;
                x21 = x6;
                y13 = y4;
                overflow21 = overflow6;
            } else {
                bool m_flag17;
                uint8_t a21;
                uint8_t a_hi21;
                uint16_t x20;
                uint16_t y12;
                bool overflow20;
                if (value7 == 0) {
                    uint8_t inventory_weapons2 = RAM8(INVENTORY_WEAPONS + x3);
                    bool m_flag6;
                    uint8_t a10;
                    uint8_t a_hi10;
                    uint16_t x9;
                    uint16_t y5;
                    bool overflow9;
                    if (inventory_weapons2 == 0xFF) {
                        m_flag6 = 1;
                        a10 = inventory_weapons2;
                        a_hi10 = a_hi4;
                        x9 = x3;
                        y5 = y3;
                        overflow9 = overflow3;
                    } else {
                        bool m_flag5;
                        uint8_t a9;
                        uint8_t a_hi9;
                        uint16_t x8;
                        bool overflow8;
                        if ((inventory_weapons2 & 0xC0) == 0) {
                            m_flag5 = 1;
                            a9 = inventory_weapons2 & 0xC0;
                            a_hi9 = a_hi4;
                            x8 = x3;
                            overflow8 = overflow3;
                        } else {
                            RAM8(0x0000 + sp0) = x3 >> 8;
                            RAM8(0x0000 + sp0 - 1) = (uint8_t)x3;
                            uint8_t value9 = RAM8(0xE01C + (uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons2 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1));
                            bool m_flag4;
                            uint8_t a8;
                            uint8_t a_hi8;
                            uint16_t x7;
                            bool overflow7;
                            if (value9 == 0) {
                                m_flag4 = 1;
                                a8 = value9;
                                a_hi8 = (uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons2 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1) >> 8;
                                x7 = x3;
                                overflow7 = (((((a_hi4 << 8 | (inventory_weapons2 & 0xC0)) & 0xFF) << 1 << 1) ^ 0x0100) & ((((a_hi4 << 8 | (inventory_weapons2 & 0xC0)) & 0xFF) << 1 << 1) ^ (uint16_t)((((a_hi4 << 8 | (inventory_weapons2 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100)) & 0x8000) != 0;
                            } else {
                                r->a = ((uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons2 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1) >> 8 << 8) | value9;
                                r->x = x3;
                                r->y = y3;
                                r->c = value9 >= 0;
                                r->z = value9 == 0;
                                r->n = value9 & 0x80;
                                r->v = (((((a_hi4 << 8 | (inventory_weapons2 & 0xC0)) & 0xFF) << 1 << 1) ^ 0x0100) & ((((a_hi4 << 8 | (inventory_weapons2 & 0xC0)) & 0xFF) << 1 << 1) ^ (uint16_t)((((a_hi4 << 8 | (inventory_weapons2 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100)) & 0x8000) != 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0;
                                r->dp = 0;
                                { const uint16_t sp_call = r->sp; JSR(c, 0xFDDA, 0xD9FDFD); GUARD_JSR(c, sp_call, 0xFDDA); } /* mark_native_inventory_descriptor_row_at_current_y */
                                bool m_ret2 = r->mf;
                                if (r->xf != 0) { c->fail = 3; return; }
                                uint16_t a_all4 = r->a;
                                uint16_t x_ret2 = r->x;
                                bool overflow_ret2 = r->v;
                                m_flag4 = m_ret2;
                                a8 = (uint8_t)a_all4;
                                a_hi8 = a_all4 >> 8;
                                x7 = x_ret2;
                                overflow7 = overflow_ret2;
                            }
                            m_flag5 = m_flag4;
                            a9 = a8;
                            a_hi9 = a_hi8;
                            x8 = x7;
                            overflow8 = overflow7;
                        }
                        m_flag6 = m_flag5;
                        a10 = a9;
                        a_hi10 = a_hi9;
                        x9 = x8;
                        y5 = (uint16_t)(y3 + 2);
                        overflow9 = overflow8;
                    }
                    m_flag17 = m_flag6;
                    a21 = a10;
                    a_hi21 = a_hi10;
                    x20 = x9;
                    y12 = y5;
                    overflow20 = overflow9;
                } else {
                    uint8_t ring_owner = RAM8(RING_OWNER);
                    bool m_flag16;
                    uint8_t a20;
                    uint8_t a_hi20;
                    uint16_t x19;
                    uint16_t y11;
                    bool overflow19;
                    if (ring_owner != 0) {
                        bool m_flag11;
                        uint8_t a15;
                        uint8_t a_hi15;
                        uint16_t x14;
                        uint16_t y8;
                        bool overflow14;
                        if (x3 != 1) {
                            uint8_t inventory_weapons3 = RAM8(INVENTORY_WEAPONS + x3);
                            bool m_flag9;
                            uint8_t a13;
                            uint8_t a_hi13;
                            uint16_t x12;
                            uint16_t y6;
                            bool overflow12;
                            if (inventory_weapons3 == 0xFF) {
                                m_flag9 = 1;
                                a13 = inventory_weapons3;
                                a_hi13 = a_hi4;
                                x12 = x3;
                                y6 = y3;
                                overflow12 = overflow3;
                            } else {
                                bool m_flag8;
                                uint8_t a12;
                                uint8_t a_hi12;
                                uint16_t x11;
                                bool overflow11;
                                if ((inventory_weapons3 & 0xC0) == 0) {
                                    m_flag8 = 1;
                                    a12 = inventory_weapons3 & 0xC0;
                                    a_hi12 = a_hi4;
                                    x11 = x3;
                                    overflow11 = overflow3;
                                } else {
                                    RAM8(0x0000 + sp0) = x3 >> 8;
                                    RAM8(0x0000 + sp0 - 1) = (uint8_t)x3;
                                    uint8_t value10 = RAM8(0xE01C + (uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons3 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1));
                                    bool m_flag7;
                                    uint8_t a11;
                                    uint8_t a_hi11;
                                    uint16_t x10;
                                    bool overflow10;
                                    if (value10 == 0) {
                                        m_flag7 = 1;
                                        a11 = value10;
                                        a_hi11 = (uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons3 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1) >> 8;
                                        x10 = x3;
                                        overflow10 = (((((a_hi4 << 8 | (inventory_weapons3 & 0xC0)) & 0xFF) << 1 << 1) ^ 0x0100) & ((((a_hi4 << 8 | (inventory_weapons3 & 0xC0)) & 0xFF) << 1 << 1) ^ (uint16_t)((((a_hi4 << 8 | (inventory_weapons3 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100)) & 0x8000) != 0;
                                    } else {
                                        r->a = ((uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons3 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1) >> 8 << 8) | value10;
                                        r->x = x3;
                                        r->y = y3;
                                        r->c = value10 >= 0;
                                        r->z = value10 == 0;
                                        r->n = value10 & 0x80;
                                        r->v = (((((a_hi4 << 8 | (inventory_weapons3 & 0xC0)) & 0xFF) << 1 << 1) ^ 0x0100) & ((((a_hi4 << 8 | (inventory_weapons3 & 0xC0)) & 0xFF) << 1 << 1) ^ (uint16_t)((((a_hi4 << 8 | (inventory_weapons3 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100)) & 0x8000) != 0;
                                        r->mf = 1;
                                        r->xf = 0;
                                        r->db = 0;
                                        r->dp = 0;
                                        { const uint16_t sp_call = r->sp; JSR(c, 0xFDDA, 0xD9FDFD); GUARD_JSR(c, sp_call, 0xFDDA); } /* mark_native_inventory_descriptor_row_at_current_y */
                                        bool m_ret3 = r->mf;
                                        if (r->xf != 0) { c->fail = 3; return; }
                                        uint16_t a_all5 = r->a;
                                        uint16_t x_ret3 = r->x;
                                        bool overflow_ret3 = r->v;
                                        m_flag7 = m_ret3;
                                        a11 = (uint8_t)a_all5;
                                        a_hi11 = a_all5 >> 8;
                                        x10 = x_ret3;
                                        overflow10 = overflow_ret3;
                                    }
                                    m_flag8 = m_flag7;
                                    a12 = a11;
                                    a_hi12 = a_hi11;
                                    x11 = x10;
                                    overflow11 = overflow10;
                                }
                                m_flag9 = m_flag8;
                                a13 = a12;
                                a_hi13 = a_hi12;
                                x12 = x11;
                                y6 = (uint16_t)(y3 + 2);
                                overflow12 = overflow11;
                            }
                            m_flag11 = m_flag9;
                            a15 = a13;
                            a_hi15 = a_hi13;
                            x14 = x12;
                            y8 = y6;
                            overflow14 = overflow12;
                        } else {
                            uint8_t inventory_weapons4 = RAM8(INVENTORY_WEAPONS + x3);
                            bool m_flag10;
                            uint8_t a14;
                            uint8_t a_hi14;
                            uint16_t x13;
                            uint16_t y7;
                            bool overflow13;
                            if (inventory_weapons4 == 0xFF) {
                                m_flag10 = 1;
                                a14 = inventory_weapons4;
                                a_hi14 = a_hi4;
                                x13 = x3;
                                y7 = y3;
                                overflow13 = overflow3;
                            } else {
                                r->a = (a_hi4 << 8) | inventory_weapons4;
                                r->x = x3;
                                r->y = y3;
                                r->c = inventory_weapons4 >= 0xFF;
                                r->z = inventory_weapons4 == 0xFF;
                                r->n = (uint8_t)(inventory_weapons4 - 0xFF) & 0x80;
                                r->v = overflow3;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0;
                                r->dp = 0;
                                { const uint16_t sp_call = r->sp; JSR(c, 0xFDDA, 0xD9FDFD); GUARD_JSR(c, sp_call, 0xFDDA); } /* mark_native_inventory_descriptor_row_at_current_y */
                                bool m_ret4 = r->mf;
                                if (r->xf != 0) { c->fail = 3; return; }
                                uint16_t a_all6 = r->a;
                                uint16_t x_ret4 = r->x;
                                bool overflow_ret4 = r->v;
                                m_flag10 = m_ret4;
                                a14 = (uint8_t)a_all6;
                                a_hi14 = a_all6 >> 8;
                                x13 = x_ret4;
                                y7 = (uint16_t)(y3 + 2);
                                overflow13 = overflow_ret4;
                            }
                            m_flag11 = m_flag10;
                            a15 = a14;
                            a_hi15 = a_hi14;
                            x14 = x13;
                            y8 = y7;
                            overflow14 = overflow13;
                        }
                        m_flag16 = m_flag11;
                        a20 = a15;
                        a_hi20 = a_hi15;
                        x19 = x14;
                        y11 = y8;
                        overflow19 = overflow14;
                    } else {
                        bool m_flag15;
                        uint8_t a19;
                        uint8_t a_hi19;
                        uint16_t x18;
                        uint16_t y10;
                        bool overflow18;
                        if (x3 == 1) {
                            uint8_t inventory_weapons5 = RAM8(INVENTORY_WEAPONS + x3);
                            bool m_flag14;
                            uint8_t a18;
                            uint8_t a_hi18;
                            uint16_t x17;
                            uint16_t y9;
                            bool overflow17;
                            if (inventory_weapons5 == 0xFF) {
                                m_flag14 = 1;
                                a18 = inventory_weapons5;
                                a_hi18 = a_hi4;
                                x17 = x3;
                                y9 = y3;
                                overflow17 = overflow3;
                            } else {
                                bool m_flag13;
                                uint8_t a17;
                                uint8_t a_hi17;
                                uint16_t x16;
                                bool overflow16;
                                if ((inventory_weapons5 & 0xC0) == 0) {
                                    m_flag13 = 1;
                                    a17 = inventory_weapons5 & 0xC0;
                                    a_hi17 = a_hi4;
                                    x16 = x3;
                                    overflow16 = overflow3;
                                } else {
                                    RAM8(0x0000 + sp0) = x3 >> 8;
                                    RAM8(0x0000 + sp0 - 1) = (uint8_t)x3;
                                    uint8_t value11 = RAM8(0xE01C + (uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons5 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1));
                                    bool m_flag12;
                                    uint8_t a16;
                                    uint8_t a_hi16;
                                    uint16_t x15;
                                    bool overflow15;
                                    if (value11 == 0) {
                                        m_flag12 = 1;
                                        a16 = value11;
                                        a_hi16 = (uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons5 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1) >> 8;
                                        x15 = x3;
                                        overflow15 = (((((a_hi4 << 8 | (inventory_weapons5 & 0xC0)) & 0xFF) << 1 << 1) ^ 0x0100) & ((((a_hi4 << 8 | (inventory_weapons5 & 0xC0)) & 0xFF) << 1 << 1) ^ (uint16_t)((((a_hi4 << 8 | (inventory_weapons5 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100)) & 0x8000) != 0;
                                    } else {
                                        r->a = ((uint16_t)((uint16_t)((((a_hi4 << 8 | (inventory_weapons5 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100) << 1) >> 8 << 8) | value11;
                                        r->x = x3;
                                        r->y = y3;
                                        r->c = value11 >= 0;
                                        r->z = value11 == 0;
                                        r->n = value11 & 0x80;
                                        r->v = (((((a_hi4 << 8 | (inventory_weapons5 & 0xC0)) & 0xFF) << 1 << 1) ^ 0x0100) & ((((a_hi4 << 8 | (inventory_weapons5 & 0xC0)) & 0xFF) << 1 << 1) ^ (uint16_t)((((a_hi4 << 8 | (inventory_weapons5 & 0xC0)) & 0xFF) << 1 << 1) - 0x0100)) & 0x8000) != 0;
                                        r->mf = 1;
                                        r->xf = 0;
                                        r->db = 0;
                                        r->dp = 0;
                                        { const uint16_t sp_call = r->sp; JSR(c, 0xFDDA, 0xD9FDFD); GUARD_JSR(c, sp_call, 0xFDDA); } /* mark_native_inventory_descriptor_row_at_current_y */
                                        bool m_ret5 = r->mf;
                                        if (r->xf != 0) { c->fail = 3; return; }
                                        uint16_t a_all7 = r->a;
                                        uint16_t x_ret5 = r->x;
                                        bool overflow_ret5 = r->v;
                                        m_flag12 = m_ret5;
                                        a16 = (uint8_t)a_all7;
                                        a_hi16 = a_all7 >> 8;
                                        x15 = x_ret5;
                                        overflow15 = overflow_ret5;
                                    }
                                    m_flag13 = m_flag12;
                                    a17 = a16;
                                    a_hi17 = a_hi16;
                                    x16 = x15;
                                    overflow16 = overflow15;
                                }
                                m_flag14 = m_flag13;
                                a18 = a17;
                                a_hi18 = a_hi17;
                                x17 = x16;
                                y9 = (uint16_t)(y3 + 2);
                                overflow17 = overflow16;
                            }
                            m_flag15 = m_flag14;
                            a19 = a18;
                            a_hi19 = a_hi18;
                            x18 = x17;
                            y10 = y9;
                            overflow18 = overflow17;
                        } else {
                            r->a = (a_hi4 << 8) | ring_owner;
                            r->x = x3;
                            r->y = y3;
                            r->c = x3 >= 1;
                            r->z = x3 == 1;
                            r->n = (uint16_t)(x3 - 1) & 0x8000;
                            r->v = overflow3;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0;
                            r->dp = 0;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xFDDA, 0xD9FDFD); GUARD_JSR(c, sp_call, 0xFDDA); } /* mark_native_inventory_descriptor_row_at_current_y */
                            bool m_ret6 = r->mf;
                            if (r->xf != 0) { c->fail = 3; return; }
                            uint16_t a_all8 = r->a;
                            uint16_t x_ret6 = r->x;
                            bool overflow_ret6 = r->v;
                            m_flag15 = m_ret6;
                            a19 = (uint8_t)a_all8;
                            a_hi19 = a_all8 >> 8;
                            x18 = x_ret6;
                            y10 = (uint16_t)(y3 + 2);
                            overflow18 = overflow_ret6;
                        }
                        m_flag16 = m_flag15;
                        a20 = a19;
                        a_hi20 = a_hi19;
                        x19 = x18;
                        y11 = y10;
                        overflow19 = overflow18;
                    }
                    m_flag17 = m_flag16;
                    a21 = a20;
                    a_hi21 = a_hi20;
                    x20 = x19;
                    y12 = y11;
                    overflow20 = overflow19;
                }
                m_flag18 = m_flag17;
                a22 = a21;
                a_hi22 = a_hi21;
                x21 = x20;
                y13 = y12;
                overflow21 = overflow20;
            }
            if (m_flag18 != 0) { c->fail = 3; return; }
            a4 = a22;
            a_hi4 = a_hi22;
            x3 = (uint16_t)(x21 + 1);
            y3 = y13;
            carry3 = (uint16_t)(x21 + 1) >= 8;
            zero3 = (uint16_t)(x21 + 1) == 8;
            negative3 = (uint16_t)((uint16_t)(x21 + 1) - 8) & 0x8000;
            overflow3 = overflow21;
            if (!(x3 < 8)) break;
        }
        r->a = (a_hi4 << 8) | a4;
        r->x = x3;
        r->y = y3;
        r->c = carry3;
        r->z = zero3;
        r->n = negative3;
        r->v = overflow3;
        r->mf = 0;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    r->a = ((value3 & value4) >> 8 << 8) | ring_category2;
    r->c = ring_category2 >= 3;
    r->z = ring_category2 == 3;
    r->n = (uint8_t)(ring_category2 - 3) & 0x80;
    r->mf = 1;
    RETURN_RTS(c);
}
