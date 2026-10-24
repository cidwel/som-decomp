#include "som_c.h"

/* C255A2 place_eligible_boss_target_at_offset_and_set_control_07   [class B, 65 bytes, 29 instructions]
 * Source: src/rom/place_eligible_boss_target_at_offset_and_set_control_07.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void place_eligible_boss_target_at_offset_and_set_control_07(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0xA9 + x);
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x0190 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    bool m_flag2;
    uint8_t a2;
    uint8_t a_hi2;
    bool carry2;
    bool zero2;
    bool negative2;
    bool overflow2;
    if ((value2 & 0xC568) != 0) {
        m_flag2 = 0;
        a2 = (uint8_t)(value2 & 0xC568);
        a_hi2 = (value2 & 0xC568) >> 8;
        carry2 = (uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000 > 0xFFFF;
        zero2 = (value2 & 0xC568) == 0;
        negative2 = value2 & 0xC568 & 0x8000;
        overflow2 = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    } else {
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x60 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
        bool m_flag;
        uint8_t a1;
        uint8_t a_hi1;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        if (value3 != 0) {
            m_flag = 1;
            a1 = value3;
            a_hi1 = (value2 & 0xC568) >> 8;
            carry1 = (uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000 > 0xFFFF;
            zero1 = value3 == 0;
            negative1 = value3 & 0x80;
            overflow1 = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        } else {
            BUS8_SET(c, (db << 0x10) + 0x01E5 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), 7);
            uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x0190 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
            BUS8_SET(c, (db << 0x10) + 0x0190 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), value4 | 1);
            BUS8_SET(c, (db << 0x10) + 0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), 0x20);
            uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x2B + x);
            BUS16_SET(c, (db << 0x10) + 2 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), (uint16_t)(value5 + 0x10));
            uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x32 + x);
            BUS16_SET(c, (db << 0x10) + 4 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), (uint16_t)(value6 + 1));
            m_flag = 0;
            a1 = (uint8_t)(value6 + 1);
            a_hi1 = (uint16_t)(value6 + 1) >> 8;
            carry1 = value5 + 0x10 > 0xFFFF;
            zero1 = (uint16_t)(value6 + 1) == 0;
            negative1 = (uint16_t)(value6 + 1) & 0x8000;
            overflow1 = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
        }
        m_flag2 = m_flag;
        a2 = a1;
        a_hi2 = a_hi1;
        carry2 = carry1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = carry2;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC255A2, SOM_RTS, "gen", place_eligible_boss_target_at_offset_and_set_control_07, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 65, 29)
