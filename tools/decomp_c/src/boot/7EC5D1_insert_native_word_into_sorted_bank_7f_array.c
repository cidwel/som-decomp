#include "som_c.h"

/* 7EC5D1 insert_native_word_into_sorted_bank_7f_array   [class B, 80 bytes, 52 instructions]
 * Source: src/boot/insert_native_word_into_sorted_bank_7f_array.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void insert_native_word_into_sorted_bank_7f_array(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), x);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), y);
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), value);
    if (value == 0) {
        uint16_t value2 = RAM16(0x0003 + (uint16_t)(sp0 - 9));
        BUS16_SET(c, 0x7F0000 + x, value2);
        uint8_t value3 = RAM8(0x0000 + sp0 - 9);
        RAM16_SET(0x0000 + sp0 - 4, value2);
        uint8_t value4 = RAM8(0x0000 + sp0 - 4);
        uint8_t value5 = RAM8(0x0000 + sp0 - 3);
        uint8_t value6 = RAM8(0x0000 + sp0 - 2);
        uint8_t value7 = RAM8(0x0000 + sp0 - 1);
        uint8_t value8 = RAM8(0x0000 + sp0);
        r->a = (value5 << 8) | value4;
        r->c = value6 & 0x01;
        r->z = ((value8 << 8) | value7) == 0;
        r->n = ((value8 << 8) | value7) & 0x8000;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = value6 & 0x10;
        r->db = value3;
        r->dp = (value8 << 8) | value7;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->a = value;
    r->c = value >= 0;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->v = (((uint16_t)(sp0 - 5) ^ 4) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC5F7, 0x7EC583); GUARD_JSR(c, sp_call, 0xC5F7); } /* search_native_sorted_word_array_and_return_insertion_position */
    r->sp += 10;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint16_t value9 = RAM16(0x0001 + (uint16_t)(sp0 - 9));
        uint16_t value10 = RAM16(0x0005 + (uint16_t)(sp0 - 9));
        if ((uint16_t)(((uint16_t)((uint8_t)x_ret2 - value9) >> 1) - value10) == 0) {
            uint16_t value11 = RAM16(0x0003 + (uint16_t)(sp0 - 9));
            RAM16_SET(0x10000 + (uint8_t)x_ret2, value11);
            uint8_t value12 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, value11);
            uint8_t value13 = RAM8(0x0000 + sp0 - 4);
            uint8_t value14 = RAM8(0x0000 + sp0 - 3);
            uint8_t value15 = RAM8(0x0000 + sp0 - 2);
            uint8_t value16 = RAM8(0x0000 + sp0 - 1);
            uint8_t value17 = RAM8(0x0000 + sp0);
            r->a = (value14 << 8) | value13;
            r->x = (uint8_t)x_ret2;
            r->y = (uint8_t)y_ret;
            r->c = value15 & 0x01;
            r->z = ((value17 << 8) | value16) == 0;
            r->n = ((value17 << 8) | value16) & 0x8000;
            r->v = value15 & 0x40;
            r->mf = value15 & 0x20;
            r->xf = value15 & 0x10;
            r->db = value12;
            r->dp = (value17 << 8) | value16;
            r->i = value15 & 0x04;
            r->d = value15 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)x_ret2;
        r->a = (uint16_t)((uint16_t)(((uint16_t)(((uint16_t)((uint8_t)x_ret2 - value9) >> 1) - value10) ^ 0xFFFF) + 1) << 1);
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)((uint8_t)x_ret2 + 2);
        r->c = (uint16_t)(((uint16_t)(((uint16_t)((uint8_t)x_ret2 - value9) >> 1) - value10) ^ 0xFFFF) + 1) & 0x8000;
        r->z = (uint8_t)((uint8_t)x_ret2 + 2) == 0;
        r->n = (uint8_t)((uint8_t)x_ret2 + 2) & 0x80;
        r->v = ((((uint16_t)((uint8_t)x_ret2 - value9) >> 1) ^ value10) & (((uint16_t)((uint8_t)x_ret2 - value9) >> 1) ^ (uint16_t)(((uint16_t)((uint8_t)x_ret2 - value9) >> 1) - value10)) & 0x8000) != 0;
        r->xf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC60D, 0x7EC4DC); GUARD_JSR(c, sp_call, 0xC60D); } /* copy_native_same_bank_memory_backward_through_stack_generated_mvp */
        r->sp += 11;
        uint16_t dp_ret = r->dp;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        if (x_ret3) {
            uint8_t value18 = RAM8(0x0000 + sp0 - 0x0A);
            if (m_ret) {
                uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret + 3));
                RAM8(0x10000 + value18) = value19;
                RAM8(0x0000 + sp0 - 4) = value19;
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
                RAM16_SET(0x10000 + value18, value21);
                uint8_t value22 = RAM8(0x0000 + sp0 - 9);
                RAM16_SET(0x0000 + sp0 - 4, value21);
                uint8_t value23 = RAM8(0x0000 + sp0 - 4);
                uint8_t value24 = RAM8(0x0000 + sp0 - 3);
                uint8_t value25 = RAM8(0x0000 + sp0 - 2);
                uint8_t value26 = RAM8(0x0000 + sp0 - 1);
                uint8_t value27 = RAM8(0x0000 + sp0);
                r->a = (value24 << 8) | value23;
                r->x = value18;
                r->y = (uint8_t)y_ret2;
                r->c = value25 & 0x01;
                r->z = ((value27 << 8) | value26) == 0;
                r->n = ((value27 << 8) | value26) & 0x8000;
                r->v = value25 & 0x40;
                r->mf = value25 & 0x20;
                r->xf = value25 & 0x10;
                r->db = value22;
                r->dp = (value27 << 8) | value26;
                r->i = value25 & 0x04;
                r->d = value25 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint8_t value28 = RAM8(0x0000 + sp0 - 0x0A);
            uint8_t value29 = RAM8(0x0000 + sp0 - 9);
            if (m_ret) {
                uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp_ret + 3));
                RAM8(0x10000 + ((value29 << 8) | value28)) = value30;
                RAM8(0x0000 + sp0 - 3) = value30;
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                c->fail = 3;
                return;
            }
        }
    } else {
        uint16_t value37 = RAM16(0x0001 + (uint16_t)(sp0 - 9));
        uint16_t value38 = RAM16(0x0005 + (uint16_t)(sp0 - 9));
        if ((uint16_t)(((uint16_t)(x_ret2 - value37) >> 1) - value38) == 0) {
            uint16_t value39 = RAM16(0x0003 + (uint16_t)(sp0 - 9));
            BUS16_SET(c, 0x7F0000 + x_ret2, value39);
            uint8_t value40 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, value39);
            uint8_t value41 = RAM8(0x0000 + sp0 - 4);
            uint8_t value42 = RAM8(0x0000 + sp0 - 3);
            uint8_t value43 = RAM8(0x0000 + sp0 - 2);
            uint8_t value44 = RAM8(0x0000 + sp0 - 1);
            uint8_t value45 = RAM8(0x0000 + sp0);
            r->a = (value42 << 8) | value41;
            r->c = value43 & 0x01;
            r->z = ((value45 << 8) | value44) == 0;
            r->n = ((value45 << 8) | value44) & 0x8000;
            r->v = value43 & 0x40;
            r->mf = value43 & 0x20;
            r->xf = value43 & 0x10;
            r->db = value40;
            r->dp = (value45 << 8) | value44;
            r->i = value43 & 0x04;
            r->d = value43 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0 - 0x0A) = x_ret2 >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x_ret2;
        r->a = (uint16_t)((uint16_t)(((uint16_t)(((uint16_t)(x_ret2 - value37) >> 1) - value38) ^ 0xFFFF) + 1) << 1);
        r->y = (uint16_t)(x_ret2 + 2);
        r->c = (uint16_t)(((uint16_t)(((uint16_t)(x_ret2 - value37) >> 1) - value38) ^ 0xFFFF) + 1) & 0x8000;
        r->z = (uint16_t)(x_ret2 + 2) == 0;
        r->n = (uint16_t)(x_ret2 + 2) & 0x8000;
        r->v = ((((uint16_t)(x_ret2 - value37) >> 1) ^ value38) & (((uint16_t)(x_ret2 - value37) >> 1) ^ (uint16_t)(((uint16_t)(x_ret2 - value37) >> 1) - value38)) & 0x8000) != 0;
        r->xf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC60D, 0x7EC4DC); GUARD_JSR(c, sp_call, 0xC60D); } /* copy_native_same_bank_memory_backward_through_stack_generated_mvp */
        r->sp += 12;
        uint16_t dp_ret2 = r->dp;
        bool m_ret2 = r->mf;
        bool x_ret5 = r->xf;
        if (x_ret5) {
            uint8_t value46 = RAM8(0x0000 + sp0 - 0x0B);
            if (m_ret2) {
                uint8_t value47 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 3));
                RAM8(0x10000 + value46) = value47;
                RAM8(0x0000 + sp0 - 5) = value47;
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                c->fail = 3;
                return;
            }
        } else {
            uint8_t value56 = RAM8(0x0000 + sp0 - 0x0B);
            uint8_t value57 = RAM8(0x0000 + sp0 - 0x0A);
            if (m_ret2) {
                uint8_t value58 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 3));
                RAM8(0x10000 + ((value57 << 8) | value56)) = value58;
                RAM8(0x0000 + sp0 - 4) = value58;
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                uint16_t value60 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
                BUS16_SET(c, 0x7F0000 + ((value57 << 8) | value56), value60);
                uint8_t value61 = RAM8(0x0000 + sp0 - 9);
                RAM16_SET(0x0000 + sp0 - 4, value60);
                uint8_t value62 = RAM8(0x0000 + sp0 - 4);
                uint8_t value63 = RAM8(0x0000 + sp0 - 3);
                uint8_t value64 = RAM8(0x0000 + sp0 - 2);
                uint8_t value65 = RAM8(0x0000 + sp0 - 1);
                uint8_t value66 = RAM8(0x0000 + sp0);
                r->a = (value63 << 8) | value62;
                r->x = (value57 << 8) | value56;
                r->c = value64 & 0x01;
                r->z = ((value66 << 8) | value65) == 0;
                r->n = ((value66 << 8) | value65) & 0x8000;
                r->v = value64 & 0x40;
                r->mf = value64 & 0x20;
                r->xf = value64 & 0x10;
                r->db = value61;
                r->dp = (value66 << 8) | value65;
                r->i = value64 & 0x04;
                r->d = value64 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0x7EC5D1, SOM_RTS, "gen", insert_native_word_into_sorted_bank_7f_array, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 12, 1, 0, 80, 52)
