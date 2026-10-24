#include "som_c.h"

/* C27E39 scan_native58_party_collision_and_mark_party_action_bytes   [class B, 138 bytes, 65 instructions]
 * Source: src/rom/scan_native58_party_collision_and_mark_party_action_bytes.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void scan_native58_party_collision_and_mark_party_action_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    BUS16_SET(c, (uint16_t)(dp + 0x64), 0);
    BUS16_SET(c, (uint16_t)(dp + 0x46), RAM16(0x002B + x));
    uint16_t value2 = RAM16(0x0032 + x);
    uint16_t value3 = RAM16(0x00A5 + x);
    BUS16_SET(c, (uint16_t)(dp + 0x4E), (uint16_t)(value2 + value3));
    uint16_t value4 = RAM16(0x001E + x);
    uint16_t value5 = BUS16(c, 0xD97F09 + (uint16_t)(value4 << 1));
    BUS16_SET(c, (uint16_t)(dp + 0x48), value5 & 0xFF);
    uint16_t value6 = BUS16(c, 0xD97F0A + (uint16_t)(value4 << 1));
    BUS16_SET(c, (uint16_t)(dp + 0x50), value6 & 0xFF);
    uint8_t a_hi1 = 0;
    uint16_t y1 = 0;
    bool overflow1 = ((value2 ^ (uint16_t)(value2 + value3)) & (value3 ^ (uint16_t)(value2 + value3)) & 0x8000) != 0;
    for (;;) {
        uint16_t value7 = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
        uint8_t a_hi3;
        bool overflow3;
        if (value7 != 1) {
            a_hi3 = value7 >> 8;
            overflow3 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        } else {
            BUS16_SET(c, (uint16_t)(dp + 0x56), RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)));
            BUS16_SET(c, (uint16_t)(dp + 0x5E), RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)));
            uint16_t value10 = RAM16(0x0089 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
            uint16_t value11 = BUS16(c, 0xD97F09 + ((value10 & 3) + 1 << 1));
            BUS16_SET(c, (uint16_t)(dp + 0x58), value11 & 0xFF);
            uint16_t value12 = BUS16(c, 0xD97F0A + ((value10 & 3) + 1 << 1));
            BUS16_SET(c, (uint16_t)(dp + 0x60), value12 & 0xFF);
            r->a = value12 & 0xFF;
            r->x = (value10 & 3) + 1 << 1;
            r->y = y1;
            r->c = (value10 & 3) + 1 & 0x8000;
            r->z = (value12 & 0xFF) == 0;
            r->n = value12 & 0xFF & 0x8000;
            r->v = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = dp;
            { const uint16_t sp_call = r->sp; JSR(c, 0x7E9A, 0xC217A9); GUARD_JSR(c, sp_call, 0x7E9A); } /* test_animation_party_radii_and_mark_contact_slot */
            uint16_t a_all = r->a;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            uint8_t a_hi2;
            bool overflow2;
            if (!carry_ret) {
                a_hi2 = a_all >> 8;
                overflow2 = overflow_ret;
            } else {
                RAM8(0x0007 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) = 5;
                RAM8(0x000A + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) = 5;
                BUS16_SET(c, (uint16_t)(dp + 0x64), ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) >> 8 << 8) | 5);
                a_hi2 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) >> 8;
                overflow2 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            }
            a_hi3 = a_hi2;
            overflow3 = overflow2;
        }
        a_hi1 = a_hi3;
        y1 = (uint16_t)(y1 + 1);
        overflow1 = overflow3;
        if (!(y1 != 3)) break;
    }
    uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp + 0x64));
    if (value14 == 0) {
        r->a = value14;
        r->x = value13;
        r->y = y1;
        r->c = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = dp;
        RETURN_RTS(c);
    }
    r->a = value14;
    r->x = value13;
    r->y = y1;
    r->c = 1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27E39, SOM_RTS, "gen", scan_native58_party_collision_and_mark_party_action_bytes, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 138, 65)
