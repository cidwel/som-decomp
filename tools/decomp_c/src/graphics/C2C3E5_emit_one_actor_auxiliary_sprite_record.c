#include "som_c.h"

/* C2C3E5 emit_one_actor_auxiliary_sprite_record   [class B, 160 bytes, 71 instructions]
 * Source: src/rom/emit_one_actor_auxiliary_sprite_record.s
 * Documented in docs/graphics.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void emit_one_actor_auxiliary_sprite_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xD000 + y);
    if (value != 0) {
        if ((value & 0xF8) != 0) {
            r->mf = true;
            RETURN_RTS(c);
        }
        if (value == 2) {
            r->mf = true;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC41D, 0xC2C4C9); GUARD_JSR(c, sp_call, 0xC41D); } /* prepare_auxiliary_sprite_screen_position */
            RAM16_SET(0x0002, 2);
            uint16_t value2 = RAM16(0xD00C + y);
            RAM16_SET(0x0000 + ((y & 0x03C0) | 0xD038), value2);
            RAM16_SET(0x0004 + ((y & 0x03C0) | 0xD038), value2);
            uint16_t value3 = RAM16(0xD00E + y);
            RAM16_SET(0x0002 + ((y & 0x03C0) | 0xD038), value3);
            RAM16_SET(0x0006 + ((y & 0x03C0) | 0xD038), value3);
            uint8_t value4 = RAM8(0xD001 + y);
            uint8_t a3;
            bool carry3;
            bool overflow3;
            if ((value4 & 3) == 0) {
                uint8_t value5 = RAM8(0x0005 + ((y & 0x03C0) | 0xD038));
                RAM8(0x0005 + ((y & 0x03C0) | 0xD038)) = (uint8_t)(value5 + 0x10);
                uint8_t value6 = RAM8(0x0007 + ((y & 0x03C0) | 0xD038));
                RAM8(0x0007 + ((y & 0x03C0) | 0xD038)) = value6 ^ 0x80;
                a3 = value6 ^ 0x80;
                carry3 = value5 + 0x10 > 0xFF;
                overflow3 = ((value5 ^ (uint8_t)(value5 + 0x10)) & ((uint8_t)(value5 + 0x10) ^ 0x10) & 0x80) != 0;
            } else {
                uint8_t a2;
                bool carry2;
                bool overflow2;
                if ((uint8_t)((value4 & 3) - 1) == 0) {
                    uint8_t value7 = RAM8(0x0005 + ((y & 0x03C0) | 0xD038));
                    RAM8(0x0005 + ((y & 0x03C0) | 0xD038)) = (uint8_t)(value7 - 0x10);
                    uint8_t value8 = RAM8(0x0007 + ((y & 0x03C0) | 0xD038));
                    RAM8(0x0007 + ((y & 0x03C0) | 0xD038)) = value8 ^ 0x80;
                    a2 = value8 ^ 0x80;
                    carry2 = value7 >= 0x10;
                    overflow2 = ((value7 ^ 0x10) & (value7 ^ (uint8_t)(value7 - 0x10)) & 0x80) != 0;
                } else {
                    uint8_t a1;
                    bool carry1;
                    bool overflow1;
                    if ((uint8_t)((value4 & 3) - 2) == 0) {
                        uint8_t value9 = RAM8(0x0004 + ((y & 0x03C0) | 0xD038));
                        a1 = (uint8_t)(value9 + 0x10);
                        carry1 = value9 + 0x10 > 0xFF;
                        overflow1 = ((value9 ^ (uint8_t)(value9 + 0x10)) & ((uint8_t)(value9 + 0x10) ^ 0x10) & 0x80) != 0;
                    } else {
                        uint8_t value10 = RAM8(0x0004 + ((y & 0x03C0) | 0xD038));
                        a1 = (uint8_t)(value10 - 0x10);
                        carry1 = value10 >= 0x10;
                        overflow1 = ((value10 ^ 0x10) & (value10 ^ (uint8_t)(value10 - 0x10)) & 0x80) != 0;
                    }
                    RAM8(0x0004 + ((y & 0x03C0) | 0xD038)) = a1;
                    uint8_t value11 = RAM8(0x0007 + ((y & 0x03C0) | 0xD038));
                    RAM8(0x0007 + ((y & 0x03C0) | 0xD038)) = value11 ^ 0x40;
                    a2 = value11 ^ 0x40;
                    carry2 = carry1;
                    overflow2 = overflow1;
                }
                a3 = a2;
                carry3 = carry2;
                overflow3 = overflow2;
            }
            r->a = (value3 >> 8 << 8) | a3;
            r->x = (y & 0x03C0) | 0xD038;
            r->c = carry3;
            r->v = overflow3;
            r->mf = true;
            r->xf = false;
            { const uint16_t sp_call = r->sp; JSL(c, 0xC483, 0xC0E324); GUARD_JSL(c, sp_call, 0xC483); } /* emit_packed_actor_sprite_list_long */
            RETURN_RTS(c);
        }
        uint8_t value12 = RAM8(0xD007 + y);
        bool m_flag3;
        uint8_t a_hi3;
        if (value12 != 0) {
            m_flag3 = 1;
            a_hi3 = a >> 8;
        } else {
            bool m_flag2;
            uint8_t a_hi2;
            if (value < 2) {
                m_flag2 = 1;
                a_hi2 = a >> 8;
            } else {
                uint8_t value13 = RAM8(0x00F4);
                bool m_flag;
                uint8_t a_hi1;
                if ((value13 & 3) != 0) {
                    m_flag = 1;
                    a_hi1 = a >> 8;
                } else {
                    r->a = (a >> 8 << 8) | value13;
                    r->mf = true;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC404, 0xC2C485); GUARD_JSR(c, sp_call, 0xC404); } /* animate_auxiliary_sprite_tile_orientation */
                    uint16_t a_all3 = r->a;
                    m_flag = 0;
                    a_hi1 = a_all3 >> 8;
                }
                m_flag2 = m_flag;
                a_hi2 = a_hi1;
            }
            m_flag3 = m_flag2;
            a_hi3 = a_hi2;
        }
        r->mf = m_flag3;
        r->xf = false;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC407, 0xC2C4C9); GUARD_JSR(c, sp_call, 0xC407); } /* prepare_auxiliary_sprite_screen_position */
        RAM16_SET(0x0002, 1);
        r->a = (uint16_t)(y + 0x0C) | 0xD000;
        r->x = (uint16_t)(y + 0x0C) | 0xD000;
        r->c = y + 0x0C > 0xFFFF;
        r->v = ((y ^ (uint16_t)(y + 0x0C)) & ((uint16_t)(y + 0x0C) ^ 0x0C) & 0x8000) != 0;
        r->mf = false;
        r->xf = false;
        { const uint16_t sp_call = r->sp; JSL(c, 0xC419, 0xC0E324); GUARD_JSL(c, sp_call, 0xC419); } /* emit_packed_actor_sprite_list_long */
        RETURN_RTS(c);
    }
    r->mf = true;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C3E5, SOM_RTS, "hand", emit_one_actor_auxiliary_sprite_record, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 160, 71)
