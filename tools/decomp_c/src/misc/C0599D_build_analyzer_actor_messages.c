#include "som_c.h"

/* C0599D build_analyzer_actor_messages   [class B, 226 bytes, 103 instructions]
 * Source: src/rom/build_analyzer_actor_messages.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void build_analyzer_actor_messages(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xE1E7 + x);
    if (value < 0x83) {
        RAM8(0x0000 + sp0) = y >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
        RAM8(0x0000 + sp0 - 2) = x >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)x;
        r->a = (a_hi << 8) | value;
        r->c = value >= 0x83;
        r->z = value == 0x83;
        r->n = (uint8_t)(value - 0x83) & 0x80;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59A9, 0xC05CCF); GUARD_JSR(c, sp_call, 0x59A9); } /* allocate_message_queue_line */
        r->sp += 4;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59AC, 0xC05A7F); GUARD_JSR(c, sp_call, 0x59AC); } /* replace_message_prefix_with_dialogue_marker */
        r->sp += 4;
        r->x = 0x628C;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59B2, 0xC05C2A); GUARD_JSR(c, sp_call, 0x59B2); } /* append_rom_message_text */
        r->sp += 4;
        uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
        uint16_t value2 = RAM16(ACTOR_HP + battle_defender_ptr);
        RAM16_SET(0x03D0, value2);
        r->a = value2;
        r->x = battle_defender_ptr;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59C0, 0xC05C6C); GUARD_JSR(c, sp_call, 0x59C0); } /* append_message_word_decimal */
        r->sp += 4;
        uint16_t y_ret4 = r->y;
        RAM8(0xFE00 + y_ret4) = 0xC1;
        uint16_t battle_defender_ptr2 = RAM16(BATTLE_DEFENDER_PTR);
        uint16_t value3 = RAM16(ACTOR_MAX_HP + battle_defender_ptr2);
        RAM16_SET(0x03D0, value3);
        r->a = value3;
        r->x = battle_defender_ptr2;
        r->y = (uint16_t)(y_ret4 + 1);
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59D4, 0xC05C6C); GUARD_JSR(c, sp_call, 0x59D4); } /* append_message_word_decimal */
        r->sp += 4;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59D7, 0xC05CCF); GUARD_JSR(c, sp_call, 0x59D7); } /* allocate_message_queue_line */
        r->sp += 4;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59DA, 0xC05A7F); GUARD_JSR(c, sp_call, 0x59DA); } /* replace_message_prefix_with_dialogue_marker */
        r->sp += 4;
        r->x = 0x6290;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59E0, 0xC05C2A); GUARD_JSR(c, sp_call, 0x59E0); } /* append_rom_message_text */
        r->sp += 4;
        uint16_t a_all8 = r->a;
        uint16_t battle_defender_ptr3 = RAM16(BATTLE_DEFENDER_PTR);
        uint8_t value4 = RAM8(ACTOR_MP + battle_defender_ptr3);
        RAM8(0x03D0) = value4;
        r->a = (a_all8 >> 8 << 8) | value4;
        r->x = battle_defender_ptr3;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59EA, 0xC05C38); GUARD_JSR(c, sp_call, 0x59EA); } /* append_message_byte_decimal */
        r->sp += 4;
        uint16_t a_all9 = r->a;
        uint16_t y_ret9 = r->y;
        bool carry_ret5 = r->c;
        bool overflow_ret3 = r->v;
        RAM8(0xFE00 + y_ret9) = 0xC1;
        uint16_t battle_defender_ptr4 = RAM16(BATTLE_DEFENDER_PTR);
        uint8_t value5 = RAM8(ACTOR_KIND_FLAGS + battle_defender_ptr4);
        RAM8(0x0000 + sp0 - 4) = ((((value5 >> 7 << 7) | (overflow_ret3 << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | ((value5 == 0) << 1) | carry_ret5;
        uint8_t value6 = RAM8(ACTOR_MAX_MP + battle_defender_ptr4);
        RAM8(0x03D0) = value6;
        r->a = (a_all9 >> 8 << 8) | value6;
        r->x = battle_defender_ptr4;
        r->y = (uint16_t)(y_ret9 + 1);
        r->z = value6 == 0;
        r->n = value6 & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x59FE, 0xC05C38); GUARD_JSR(c, sp_call, 0x59FE); } /* append_message_byte_decimal */
        r->sp += 5;
        uint16_t a_all10 = r->a;
        uint8_t value7 = RAM8(0x0000 + sp0 - 4);
        bool m_flag;
        bool x_flag;
        uint8_t a_hi1;
        if (value7 & 0x80) {
            m_flag = value7 & 0x20;
            x_flag = value7 & 0x10;
            a_hi1 = a_all10 >> 8;
        } else {
            r->c = value7 & 0x01;
            r->z = value7 & 0x02;
            r->n = value7 & 0x80;
            r->v = value7 & 0x40;
            r->mf = value7 & 0x20;
            r->xf = value7 & 0x10;
            r->i = value7 & 0x04;
            r->d = value7 & 0x08;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5A04, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5A04); } /* allocate_message_queue_line */
            r->sp += 4;
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5A07, 0xC05A7F); GUARD_JSR(c, sp_call, 0x5A07); } /* replace_message_prefix_with_dialogue_marker */
            r->sp += 4;
            if (r->xf != 0) { c->fail = 3; return; }
            r->x = 0x62D2;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5A0D, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5A0D); } /* append_rom_message_text */
            r->sp += 4;
            uint16_t battle_defender_ptr5 = RAM16(BATTLE_DEFENDER_PTR);
            uint16_t value8 = RAM16(0xE18D + battle_defender_ptr5);
            RAM16_SET(0x03D0, value8);
            r->a = value8;
            r->x = battle_defender_ptr5;
            r->z = value8 == 0;
            r->n = value8 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5A1B, 0xC05C6C); GUARD_JSR(c, sp_call, 0x5A1B); } /* append_message_word_decimal */
            r->sp += 4;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5A1E, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5A1E); } /* allocate_message_queue_line */
            r->sp += 4;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5A21, 0xC05A7F); GUARD_JSR(c, sp_call, 0x5A21); } /* replace_message_prefix_with_dialogue_marker */
            r->sp += 4;
            uint16_t battle_defender_ptr6 = RAM16(BATTLE_DEFENDER_PTR);
            uint16_t value9 = RAM16(0xE1C8 + battle_defender_ptr6);
            RAM16_SET(0x03D0, value9);
            r->a = value9;
            r->x = battle_defender_ptr6;
            r->z = value9 == 0;
            r->n = value9 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5A2F, 0xC05C6C); GUARD_JSR(c, sp_call, 0x5A2F); } /* append_message_word_decimal */
            r->sp += 4;
            r->x = 0x62D7;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5A35, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5A35); } /* append_rom_message_text */
            r->sp += 4;
            uint16_t a_all18 = r->a;
            m_flag = 1;
            x_flag = 0;
            a_hi1 = a_all18 >> 8;
        }
        if (x_flag) {
            uint8_t battle_defender_ptr7 = RAM8(BATTLE_DEFENDER_PTR);
            if (m_flag) {
                RAM8(BATTLE_DIV_WORK) = RAM8(ACTOR_WEAK_ELEMENT + battle_defender_ptr7);
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                RAM16_SET(BATTLE_DIV_WORK, RAM16(ACTOR_WEAK_ELEMENT + battle_defender_ptr7));
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
        } else {
            uint16_t battle_defender_ptr8 = RAM16(BATTLE_DEFENDER_PTR);
            if (m_flag) {
                RAM8(BATTLE_DIV_WORK) = RAM8(ACTOR_WEAK_ELEMENT + battle_defender_ptr8);
                RAM16_SET(0x03B4, 0x5DDB);
                RAM8(0x03D0) = 7;
                RAM8(BATTLE_MUL_WORK) = 0x80;
                RAM8(0x03B6) = 0xC0;
                uint8_t a_hi2 = a_hi1;
                uint16_t y1 = 0x5DDB;
                do {
                    uint8_t battle_mul_work = RAM8(BATTLE_MUL_WORK);
                    uint8_t battle_div_work = RAM8(BATTLE_DIV_WORK);
                    uint8_t a_hi3;
                    uint16_t y2;
                    if ((battle_mul_work & battle_div_work) != 0) {
                        uint8_t value13 = RAM8(0x03D0);
                        RAM8(0x0000 + sp0 - 4) = y1 >> 8;
                        RAM8(0x0000 + sp0 - 5) = (uint8_t)y1;
                        uint16_t value14 = BUS16_RDL(c, (RAM8(0x03B6) << 0x10) + RAM16(0x03B4) + (uint8_t)(value13 << 1), RAM8(0x03B6));
                        r->a = value14;
                        r->x = value14;
                        r->y = y1;
                        r->c = value13 & 0x80;
                        r->z = value14 == 0;
                        r->n = value14 & 0x8000;
                        r->v = battle_div_work & 0x40;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0x0300;
                        r->i = value7 & 0x04;
                        r->d = value7 & 0x08;
                        r->sp -= 4;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x5A6F, 0xC05CCF); GUARD_JSR(c, sp_call, 0x5A6F); } /* allocate_message_queue_line */
                        r->sp += 4;
                        uint16_t x_ret14 = r->x;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 4;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x5A72, 0xC05A7F); GUARD_JSR(c, sp_call, 0x5A72); } /* replace_message_prefix_with_dialogue_marker */
                        r->sp += 4;
                        RAM8(0x0000 + sp0 - 4) = x_ret14 >> 8;
                        RAM8(0x0000 + sp0 - 5) = (uint8_t)x_ret14;
                        uint16_t battle_defender_ptr9 = RAM16(BATTLE_DEFENDER_PTR);
                        r->x = battle_defender_ptr9;
                        r->z = battle_defender_ptr9 == 0;
                        r->n = battle_defender_ptr9 & 0x8000;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x5A78, 0xC05C06); GUARD_JSR(c, sp_call, 0x5A78); } /* append_actor_name_message_token */
                        r->sp += 6;
                        uint8_t value15 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value16 = RAM8(0x0000 + sp0 - 4);
                        r->x = (value16 << 8) | value15;
                        r->z = ((value16 << 8) | value15) == 0;
                        r->n = ((value16 << 8) | value15) & 0x8000;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 4;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x5A7C, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5A7C); } /* append_rom_message_text */
                        r->sp += 4;
                        uint16_t a_all22 = r->a;
                        uint16_t y_ret22 = r->y;
                        a_hi3 = a_all22 >> 8;
                        y2 = y_ret22;
                    } else {
                        a_hi3 = a_hi2;
                        y2 = y1;
                    }
                    RAM8(0x03D0)--;
                    RAM8(BATTLE_MUL_WORK) >>= 1;
                    a_hi2 = a_hi3;
                    y1 = y2;
                } while (RAM8(BATTLE_MUL_WORK) != 0);
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0x0300;
                r->i = value7 & 0x04;
                r->d = value7 & 0x08;
                RETURN_RTL(c);
            } else {
                RAM16_SET(BATTLE_DIV_WORK, RAM16(ACTOR_WEAK_ELEMENT + battle_defender_ptr8));
                RAM16_SET(0x03B4, 0x5DDB);
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
        }
    }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0599D, SOM_RTL, "gen", build_analyzer_actor_messages, 0, 0, 6, 1, 0, 226, 103)
