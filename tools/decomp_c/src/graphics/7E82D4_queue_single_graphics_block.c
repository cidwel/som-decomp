#include "som_c.h"

/* 7E82D4 queue_single_graphics_block   [class B, 106 bytes, 58 instructions]
 * Source: src/boot/queue_single_graphics_block.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: XY.
 */
static void queue_single_graphics_block(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 0x0A) + 0x5 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x0A) = db;
    RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7F;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0A), x);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0A), y);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) = (uint8_t)value;
    uint8_t a1;
    if (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) != 0) {
        a1 = 9;
    } else {
        a1 = 1;
    }
    r->a = a1;
    r->c = (uint16_t)(sp0 - 5) >= 5;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 5) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0A)) & 0x8000) != 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 0x0A);
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8303, 0x7E8FC7); GUARD_JSR(c, sp_call, 0x8303); } /* allocate_transfer_descriptor */
    r->sp += 11;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0006 + dp_ret) = (uint8_t)x_ret2;
        uint8_t value2 = RAM8(0x0002 + dp_ret);
        r->x = value2;
        r->y = (uint8_t)y_ret;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->xf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0x830A, 0x7ED6B3); GUARD_JSR(c, sp_call, 0x830A); } /* read_vram_address_tag_word */
        r->sp += 11;
        r->xf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0x830D, 0x7E805F); GUARD_JSR(c, sp_call, 0x830D); } /* select_graphics_registration */
        r->sp += 11;
        bool m_ret3 = r->mf;
        uint16_t a_all3 = r->a;
        if (m_ret3) {
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 2 + (uint8_t)a_all3);
            r->a = (a_all3 >> 8 << 8) | value3;
            r->x = (uint8_t)a_all3;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8314, 0x7EC34D); GUARD_JSR(c, sp_call, 0x8314); } /* derive_sixteen_bit_mask_from_low_nibble */
            r->sp += 11;
            uint16_t a_all4 = r->a;
            uint8_t x_ret4 = r->x;
            uint8_t value4 = RAM8(0x0006 + dp_ret);
            BUS8_SET(c, (db_ret << 0x10) + 5 + value4, (uint8_t)(x_ret4 << 3));
            BUS8_SET(c, (db_ret << 0x10) + 0x0A + value4, RAM8(0x0002 + dp_ret));
            BUS8_SET(c, (db_ret << 0x10) + 2 + value4, RAM8(0x0004 + dp_ret));
            uint8_t value7 = RAM8(0x0001 + dp_ret);
            BUS8_SET(c, (db_ret << 0x10) + 4 + value4, value7);
            r->a = (a_all4 >> 8 << 8) | value7;
            r->x = value4;
            r->c = (uint8_t)(x_ret4 << 2) & 0x80;
            r->z = value7 == 0;
            r->n = value7 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8331, 0x7E90DA); GUARD_JSR(c, sp_call, 0x8331); } /* submit_transfer_or_program_hdma */
            r->sp += 11;
            uint8_t value8 = RAM8(0x0000 + sp0 - 0x0A);
            uint8_t value9 = RAM8(0x0000 + sp0 - 2);
            uint8_t value10 = RAM8(0x0000 + sp0 - 1);
            uint8_t value11 = RAM8(0x0000 + sp0);
            r->mf = value9 & 0x20;
            r->xf = value9 & 0x10;
            r->db = value8;
            r->dp = (value11 << 8) | value10;
            r->i = value9 & 0x04;
            r->d = value9 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value12 = BUS16_RDP(c, (db_ret << 0x10) + 2 + (uint8_t)a_all3);
            r->a = value12;
            r->x = (uint8_t)a_all3;
            r->z = value12 == 0;
            r->n = value12 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8314, 0x7EC34D); GUARD_JSR(c, sp_call, 0x8314); } /* derive_sixteen_bit_mask_from_low_nibble */
            r->sp += 11;
            uint8_t x_ret7 = r->x;
            uint8_t value13 = RAM8(0x0006 + dp_ret);
            BUS16_SET(c, (db_ret << 0x10) + 5 + value13, x_ret7 << 1 << 1 << 1);
            BUS16_SET(c, (db_ret << 0x10) + 0x0A + value13, RAM16(0x0002 + dp_ret));
            uint16_t value15 = RAM16(0x0004 + dp_ret);
            BUS16_SET(c, (db_ret << 0x10) + 2 + value13, value15);
            uint8_t value16 = RAM8(0x0001 + dp_ret);
            BUS8_SET(c, (db_ret << 0x10) + 4 + value13, value16);
            r->a = (value15 >> 8 << 8) | value16;
            r->x = value13;
            r->c = x_ret7 << 1 << 1 & 0x8000;
            r->z = value16 == 0;
            r->n = value16 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8331, 0x7E90DA); GUARD_JSR(c, sp_call, 0x8331); } /* submit_transfer_or_program_hdma */
            r->sp += 11;
            uint8_t value17 = RAM8(0x0000 + sp0 - 0x0A);
            uint8_t value18 = RAM8(0x0000 + sp0 - 2);
            uint8_t value19 = RAM8(0x0000 + sp0 - 1);
            uint8_t value20 = RAM8(0x0000 + sp0);
            r->mf = value18 & 0x20;
            r->xf = value18 & 0x10;
            r->db = value17;
            r->dp = (value20 << 8) | value19;
            r->i = value18 & 0x04;
            r->d = value18 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        RAM16_SET(0x0006 + dp_ret, x_ret2);
        uint16_t value21 = RAM16(0x0002 + dp_ret);
        r->x = value21;
        r->z = value21 == 0;
        r->n = value21 & 0x8000;
        r->xf = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0x830A, 0x7ED6B3); GUARD_JSR(c, sp_call, 0x830A); } /* read_vram_address_tag_word */
        r->sp += 11;
        r->xf = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0x830D, 0x7E805F); GUARD_JSR(c, sp_call, 0x830D); } /* select_graphics_registration */
        r->sp += 11;
        bool m_ret7 = r->mf;
        uint16_t a_all9 = r->a;
        if (m_ret7) {
            uint8_t value22 = BUS8_RDP(c, (db_ret << 0x10) + 2 + a_all9);
            r->a = (a_all9 >> 8 << 8) | value22;
            r->x = a_all9;
            r->z = value22 == 0;
            r->n = value22 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8314, 0x7EC34D); GUARD_JSR(c, sp_call, 0x8314); } /* derive_sixteen_bit_mask_from_low_nibble */
            r->sp += 11;
            uint16_t a_all10 = r->a;
            uint16_t x_ret11 = r->x;
            uint16_t value23 = RAM16(0x0006 + dp_ret);
            BUS8_SET(c, (db_ret << 0x10) + 5 + value23, (uint8_t)((uint8_t)x_ret11 << 3));
            BUS8_SET(c, (db_ret << 0x10) + 0x0A + value23, RAM8(0x0002 + dp_ret));
            BUS8_SET(c, (db_ret << 0x10) + 2 + value23, RAM8(0x0004 + dp_ret));
            uint8_t value26 = RAM8(0x0001 + dp_ret);
            BUS8_SET(c, (db_ret << 0x10) + 4 + value23, value26);
            r->a = (a_all10 >> 8 << 8) | value26;
            r->x = value23;
            r->c = (uint8_t)((uint8_t)x_ret11 << 2) & 0x80;
            r->z = value26 == 0;
            r->n = value26 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8331, 0x7E90DA); GUARD_JSR(c, sp_call, 0x8331); } /* submit_transfer_or_program_hdma */
            r->sp += 11;
            uint8_t value27 = RAM8(0x0000 + sp0 - 0x0A);
            uint8_t value28 = RAM8(0x0000 + sp0 - 2);
            uint8_t value29 = RAM8(0x0000 + sp0 - 1);
            uint8_t value30 = RAM8(0x0000 + sp0);
            r->mf = value28 & 0x20;
            r->xf = value28 & 0x10;
            r->db = value27;
            r->dp = (value30 << 8) | value29;
            r->i = value28 & 0x04;
            r->d = value28 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value31 = BUS16_RDP(c, (db_ret << 0x10) + 2 + a_all9);
            r->a = value31;
            r->x = a_all9;
            r->z = value31 == 0;
            r->n = value31 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8314, 0x7EC34D); GUARD_JSR(c, sp_call, 0x8314); } /* derive_sixteen_bit_mask_from_low_nibble */
            r->sp += 11;
            uint16_t x_ret14 = r->x;
            uint16_t value32 = RAM16(0x0006 + dp_ret);
            BUS16_SET(c, (db_ret << 0x10) + 5 + value32, (uint16_t)(x_ret14 << 3));
            BUS16_SET(c, (db_ret << 0x10) + 0x0A + value32, RAM16(0x0002 + dp_ret));
            uint16_t value34 = RAM16(0x0004 + dp_ret);
            BUS16_SET(c, (db_ret << 0x10) + 2 + value32, value34);
            uint8_t value35 = RAM8(0x0001 + dp_ret);
            BUS8_SET(c, (db_ret << 0x10) + 4 + value32, value35);
            r->a = (value34 >> 8 << 8) | value35;
            r->x = value32;
            r->c = (uint16_t)(x_ret14 << 2) & 0x8000;
            r->z = value35 == 0;
            r->n = value35 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8331, 0x7E90DA); GUARD_JSR(c, sp_call, 0x8331); } /* submit_transfer_or_program_hdma */
            r->sp += 11;
            uint8_t value36 = RAM8(0x0000 + sp0 - 0x0A);
            uint8_t value37 = RAM8(0x0000 + sp0 - 2);
            uint8_t value38 = RAM8(0x0000 + sp0 - 1);
            uint8_t value39 = RAM8(0x0000 + sp0);
            r->mf = value37 & 0x20;
            r->xf = value37 & 0x10;
            r->db = value36;
            r->dp = (value39 << 8) | value38;
            r->i = value37 & 0x04;
            r->d = value37 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7E82D4, SOM_RTS, "gen", queue_single_graphics_block, 0, L_X | L_Y, 13, 1, 0, 106, 58)
