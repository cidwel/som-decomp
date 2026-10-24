#include "som_c.h"

/* C03DDC clear_controller_guard_when_actor_leaves_saved_rectangle   [class B, 89 bytes, 43 instructions]
 * Source: src/rom/clear_controller_guard_when_actor_leaves_saved_rectangle.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void clear_controller_guard_when_actor_leaves_saved_rectangle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(ACTOR_GUARD_FLAGS + x);
    uint8_t a_hi3;
    uint16_t x1;
    uint16_t y1;
    bool carry4;
    bool overflow1;
    if ((value & 0x20) == 0) {
        a_hi3 = a_hi;
        x1 = x;
        y1 = y;
        carry4 = carry;
        overflow1 = overflow;
    } else {
        uint8_t value2 = RAM8(0x0381);
        uint16_t value3 = RAM16(0xFF86 + (uint8_t)(value2 << 2));
        RAM16_SET(BATTLE_TEMP_A4, (uint16_t)(value3 + 0x0C));
        RAM16_SET(BATTLE_TEMP_A6, (uint16_t)((uint16_t)(value3 + 0x0C) - 0x18));
        uint16_t value4 = RAM16(0xFF88 + (uint8_t)(value2 << 2));
        RAM16_SET(BATTLE_TEMP_A8, (uint16_t)(value4 + 0x0C));
        RAM16_SET(0x03AA, (uint16_t)((uint16_t)(value4 + 0x0C) - 0x18));
        uint16_t value5 = RAM16(0xE002 + x);
        uint16_t battle_temp_a4 = RAM16(BATTLE_TEMP_A4);
        bool m_flag4;
        uint8_t a_hi2;
        bool carry3;
        if (value5 >= battle_temp_a4) {
            RAM8(0xCF03) = 0;
            RAM8(ACTOR_GUARD_FLAGS + x) &= 0xDF;
            m_flag4 = 1;
            a_hi2 = value5 >> 8;
            carry3 = value5 >= battle_temp_a4;
        } else {
            uint16_t battle_temp_a6 = RAM16(BATTLE_TEMP_A6);
            bool m_flag3;
            uint8_t a_hi1;
            bool carry2;
            if (value5 < battle_temp_a6) {
                RAM8(0xCF03) = 0;
                RAM8(ACTOR_GUARD_FLAGS + x) &= 0xDF;
                m_flag3 = 1;
                a_hi1 = value5 >> 8;
                carry2 = value5 >= battle_temp_a6;
            } else {
                uint16_t value8 = RAM16(0xE004 + x);
                uint16_t battle_temp_a8 = RAM16(BATTLE_TEMP_A8);
                bool m_flag2;
                bool carry1;
                if (value8 >= battle_temp_a8) {
                    RAM8(0xCF03) = 0;
                    RAM8(ACTOR_GUARD_FLAGS + x) &= 0xDF;
                    m_flag2 = 1;
                    carry1 = value8 >= battle_temp_a8;
                } else {
                    uint16_t value10 = RAM16(0x03AA);
                    bool m_flag;
                    if (value8 < value10) {
                        RAM8(0xCF03) = 0;
                        RAM8(ACTOR_GUARD_FLAGS + x) &= 0xDF;
                        m_flag = 1;
                    } else {
                        m_flag = 0;
                    }
                    m_flag2 = m_flag;
                    carry1 = value8 >= value10;
                }
                m_flag3 = m_flag2;
                a_hi1 = value8 >> 8;
                carry2 = carry1;
            }
            m_flag4 = m_flag3;
            a_hi2 = a_hi1;
            carry3 = carry2;
        }
        uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
        a_hi3 = a_hi2;
        x1 = battle_defender_ptr;
        y1 = (uint8_t)(value2 << 2);
        carry4 = carry3;
        overflow1 = (((uint16_t)(value4 + 0x0C) ^ 0x18) & ((uint16_t)(value4 + 0x0C) ^ (uint16_t)((uint16_t)(value4 + 0x0C) - 0x18)) & 0x8000) != 0;
    }
    r->a = (r->a & 0x00FF) | (a_hi3 << 8);
    r->x = x1;
    r->y = y1;
    r->c = carry4;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03DDC, SOM_RTS, "gen", clear_controller_guard_when_actor_leaves_saved_rectangle, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 89, 43)
