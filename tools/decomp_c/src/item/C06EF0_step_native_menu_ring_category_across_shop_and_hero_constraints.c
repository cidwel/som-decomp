#include "som_c.h"

/* C06EF0 step_native_menu_ring_category_across_shop_and_hero_constraints   [class B, 110 bytes, 53 instructions]
 * Source: src/rom/step_native_menu_ring_category_across_shop_and_hero_constraints.s
 * Documented in docs/event-menu-ring-category.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCZV.
 */
static void step_native_menu_ring_category_across_shop_and_hero_constraints(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1803);
    uint8_t a_hi3;
    uint8_t x12;
    bool carry7;
    bool overflow3;
    if ((value & 8) == 0) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1847);
        uint8_t a_hi2;
        uint8_t x9;
        bool carry5;
        bool overflow2;
        if (value2 != 2) {
            uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x1809);
            uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x1814);
            uint8_t x2;
            bool carry1;
            if ((uint8_t)(value3 + value4) & 0x80) {
                x2 = 3;
                carry1 = value3 + value4 > 0xFF;
            } else {
                uint8_t x1;
                if ((uint8_t)(value3 + value4) < 4) {
                    x1 = (uint8_t)((a >> 8 << 8) | (uint8_t)(value3 + value4));
                } else {
                    x1 = 0;
                }
                x2 = x1;
                carry1 = (uint8_t)(value3 + value4) >= 4;
            }
            uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x1808);
            uint8_t x5;
            bool carry2;
            if (value5 != 0) {
                x5 = x2;
                carry2 = carry1;
            } else {
                uint8_t x4;
                if (x2 != 1) {
                    x4 = x2;
                } else {
                    uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0x1814);
                    uint8_t x3;
                    if (!(value6 & 0x80)) {
                        x3 = x2;
                    } else {
                        x3 = 0;
                    }
                    x4 = x3;
                }
                x5 = x4;
                carry2 = x2 >= 1;
            }
            a_hi2 = a >> 8;
            x9 = x5;
            carry5 = carry2;
            overflow2 = ((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) != 0;
        } else {
            uint8_t a_hi1 = a >> 8;
            uint8_t x6 = (uint8_t)x;
            bool carry3 = value2 >= 2;
            bool overflow1 = value & 0x40;
            for (;;) {
                uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0x1809);
                uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0x1814);
                uint8_t x8;
                if ((uint8_t)(value7 + value8) & 0x80) {
                    x8 = 6;
                } else {
                    uint8_t x7;
                    if ((uint8_t)(value7 + value8) < 7) {
                        x7 = (uint8_t)((a_hi1 << 8) | (uint8_t)(value7 + value8));
                    } else {
                        x7 = 0;
                    }
                    x8 = x7;
                }
                BUS8_SET(c, (db << 0x10) + 0x1809, x8);
                bool carry4;
                if (x8 == 0) {
                    carry4 = x8 >= 0;
                } else {
                    if (x8 < 4) {
                        x6 = x8;
                        carry3 = x8 >= 4;
                        overflow1 = ((value7 ^ (uint8_t)(value7 + value8)) & (value8 ^ (uint8_t)(value7 + value8)) & 0x80) != 0;
                        continue;
                    }
                    carry4 = x8 >= 4;
                }
                x6 = x8;
                carry3 = carry4;
                overflow1 = ((value7 ^ (uint8_t)(value7 + value8)) & (value8 ^ (uint8_t)(value7 + value8)) & 0x80) != 0;
                break;
            }
            a_hi2 = a_hi1;
            x9 = x6;
            carry5 = carry3;
            overflow2 = overflow1;
        }
        a_hi3 = a_hi2;
        x12 = x9;
        carry7 = carry5;
        overflow3 = overflow2;
    } else {
        uint8_t value9 = BUS8_RDP(c, (db << 0x10) + 0x1814);
        uint8_t value10 = BUS8_RDP(c, (db << 0x10) + 0x1809);
        uint8_t x11;
        bool carry6;
        if ((uint8_t)(value9 + value10) < 4) {
            x11 = 6;
            carry6 = (uint8_t)(value9 + value10) >= 4;
        } else {
            uint8_t x10;
            if ((uint8_t)(value9 + value10) < 7) {
                x10 = (uint8_t)((a >> 8 << 8) | (uint8_t)(value9 + value10));
            } else {
                x10 = 4;
            }
            x11 = x10;
            carry6 = (uint8_t)(value9 + value10) >= 7;
        }
        a_hi3 = a >> 8;
        x12 = x11;
        carry7 = carry6;
        overflow3 = ((value9 ^ (uint8_t)(value9 + value10)) & (value10 ^ (uint8_t)(value9 + value10)) & 0x80) != 0;
    }
    BUS8_SET(c, (db << 0x10) + 0x1809, x12);
    r->a = (a_hi3 << 8) | x12;
    r->x = x12;
    r->y = (uint8_t)y;
    r->c = carry7;
    r->z = x12 == 0;
    r->v = overflow3;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06EF0, SOM_RTS, "gen", step_native_menu_ring_category_across_shop_and_hero_constraints, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, -1, 0, 110, 53)
