#include "som_c.h"

/* C76367 publish_eight_native_party_status_flag_icons_when_unrestricted   [class B, 70 bytes, 31 instructions]
 * Source: src/rom/publish_eight_native_party_status_flag_icons_when_unrestricted.s
 * Documented in docs/ui-native-party-status-art.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void publish_eight_native_party_status_flag_icons_when_unrestricted(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x636B, 0xC76AA4); GUARD_JSR(c, sp_call, 0x636B); } /* read_selected_native_party_status_excluding_low_two_bits */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool m_flag;
    uint8_t a_hi5;
    uint16_t x5;
    uint16_t y2;
    bool carry2;
    bool overflow2;
    if (!zero_ret) {
        m_flag = 0;
        a_hi5 = a_all >> 8;
        x5 = x_ret;
        y2 = y;
        carry2 = carry_ret;
        overflow2 = overflow;
    } else {
        RAM8(0xA15A) = 0x90;
        RAM8(0xA159) = 0x10;
        uint8_t a_hi1 = a_all >> 8;
        uint16_t x1 = 0x0100;
        uint16_t y1 = 0;
        bool carry1 = carry_ret;
        bool overflow1 = overflow;
        for (;;) {
            uint8_t value = RAM8(0xCF90 + y1);
            uint8_t a_hi4;
            uint16_t x4;
            if (value == 0) {
                a_hi4 = a_hi1;
                x4 = x1;
            } else {
                uint8_t a_hi3;
                uint16_t x3;
                if ((uint8_t)(value - 1) != 0) {
                    uint8_t a_hi2;
                    uint16_t x2;
                    if ((uint8_t)(value - 2) != 0) {
                        a_hi2 = a_hi1;
                        x2 = x1;
                    } else {
                        RAM8(0xA17E) = 8;
                        r->a = (a_hi1 << 8) | 8;
                        r->x = x1;
                        r->y = y1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x639A, 0xC763AD); GUARD_JSR(c, sp_call, 0x639A); } /* derive_native_party_status_icon_quadrant_tile_offset */
                        uint16_t a_all2 = r->a;
                        uint16_t x_ret2 = r->x;
                        a_hi2 = a_all2 >> 8;
                        x2 = x_ret2;
                    }
                    a_hi3 = a_hi2;
                    x3 = x2;
                } else {
                    RAM8(0xA17E) = 0;
                    r->a = (a_hi1 << 8) | (uint8_t)(value - 1);
                    r->x = x1;
                    r->y = y1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x638D, 0xC763AD); GUARD_JSR(c, sp_call, 0x638D); } /* derive_native_party_status_icon_quadrant_tile_offset */
                    uint16_t a_all3 = r->a;
                    uint16_t x_ret3 = r->x;
                    a_hi3 = a_all3 >> 8;
                    x3 = x_ret3;
                }
                a_hi4 = a_hi3;
                x4 = x3;
            }
            uint8_t value2 = RAM8(0xA159);
            RAM8(0xA159) = (uint8_t)(value2 + 0x0C);
            uint8_t a_hi1_next = a_hi4;
            uint16_t x1_next = x4;
            uint16_t y1_next = (uint16_t)(y1 + 1);
            bool carry1_next = (uint16_t)(y1 + 1) >= 8;
            bool overflow1_next = (((uint8_t)(value2 + 0x0C) ^ 0x0C) & (value2 ^ (uint8_t)(value2 + 0x0C)) & 0x80) != 0;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            overflow1 = overflow1_next;
            if (!(y1 != 8)) break;
        }
        m_flag = 1;
        a_hi5 = a_hi1;
        x5 = x1;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    r->a = (a_hi5 << 8) | a;
    r->x = x5;
    r->y = y2;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76367, SOM_RTS, "gen", publish_eight_native_party_status_flag_icons_when_unrestricted, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 70, 31)
