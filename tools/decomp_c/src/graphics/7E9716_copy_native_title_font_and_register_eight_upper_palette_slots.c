#include "som_c.h"

/* 7E9716 copy_native_title_font_and_register_eight_upper_palette_slots   [class B, 77 bytes, 47 instructions]
 * Source: src/boot/copy_native_title_font_and_register_eight_upper_palette_slots.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$02ED.  Callers read: BXYCV.
 */
static void copy_native_title_font_and_register_eight_upper_palette_slots(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x02ED) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_hi_9744 = 0;
    uint8_t x_9744 = 0;
    bool carry_9744 = 0;
    bool overflow_9744 = 0;
    uint16_t direct_page_9744 = 0;
    uint8_t data_bank_9744 = 0;
    uint8_t a_hi_97442 = 0;
    uint16_t x_97442 = 0;
    bool carry_97442 = 0;
    bool overflow_97442 = 0;
    uint16_t direct_page_97442 = 0;
    uint8_t data_bank_97442 = 0;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xED;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0;
    RAM8(0x0000 + sp0 - 7) = 0xC0;
    RAM8(0x0000 + sp0 - 8) = 0x7E;
    RAM8(0x0000 + sp0 - 9) = 0x50;
    RAM8(0x0000 + sp0 - 0x0A) = 0;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0C) = x >> 8;
    RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)x;
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | 0x7F;
    r->y = 0x5000;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9735, 0x7EC44E); GUARD_JSR(c, sp_call, 0x9735); } /* copy_far_stack_arguments */
    r->sp += 14;
    uint16_t dp_ret = r->dp;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    BUS8_SET(c, (uint16_t)(dp_ret + 1), 8);
    if (x_ret) {
        a_hi_9744 = (uint16_t)((uint16_t)(sp0 - 0x0E) + 8) >> 8;
        x_9744 = (uint8_t)x_ret2;
        carry_9744 = (uint16_t)(sp0 - 0x0E) + 8 > 0xFFFF;
        overflow_9744 = (((uint16_t)(sp0 - 0x0E) ^ (uint16_t)((uint16_t)(sp0 - 0x0E) + 8)) & ((uint16_t)((uint16_t)(sp0 - 0x0E) + 8) ^ 8) & 0x8000) != 0;
        direct_page_9744 = dp_ret;
        data_bank_9744 = 0x7F;
        goto shared_9744;
    } else {
        a_hi_97442 = (uint16_t)((uint16_t)(sp0 - 0x0E) + 8) >> 8;
        x_97442 = x_ret2;
        carry_97442 = (uint16_t)(sp0 - 0x0E) + 8 > 0xFFFF;
        overflow_97442 = (((uint16_t)(sp0 - 0x0E) ^ (uint16_t)((uint16_t)(sp0 - 0x0E) + 8)) & ((uint16_t)((uint16_t)(sp0 - 0x0E) + 8) ^ 8) & 0x8000) != 0;
        direct_page_97442 = dp_ret;
        data_bank_97442 = 0x7F;
        goto shared_9744_1;
    }
    shared_9744:;
    r->a = (a_hi_9744 << 8) | 8;
    r->x = x_9744;
    r->c = carry_9744;
    r->z = 0;
    r->n = 0;
    r->v = overflow_9744;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_9744;
    r->dp = direct_page_9744;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9748, 0x7EBBAB); GUARD_JSR(c, sp_call, 0x9748); } /* allocate_palette_slot */
    r->sp += 6;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
    BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value - 1));
    if ((uint8_t)(value - 1) != 0) {
        a_hi_97442 = a_all2 >> 8;
        x_97442 = x_ret3;
        carry_97442 = carry_ret2;
        overflow_97442 = overflow_ret2;
        direct_page_97442 = dp_ret2;
        data_bank_97442 = db_ret;
        goto shared_9744_1;
    }
    RAM8(0x0000 + sp0 - 6) = x_ret3 >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)x_ret3;
    r->a = 0x7E87;
    r->y = 0x5140;
    r->z = 0;
    r->n = 1;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9758, 0x7EBC9A); GUARD_JSR(c, sp_call, 0x9758); } /* copy_palette_colours */
    r->sp += 8;
    bool x_ret4 = r->xf;
    if (x_ret4) {
        c->fail = 3;
        return;
    } else {
        uint8_t value14 = RAM8(0x0000 + sp0 - 7);
        uint8_t value15 = RAM8(0x0000 + sp0 - 6);
        r->x = (value15 << 8) | value14;
        r->z = ((value15 << 8) | value14) == 0;
        r->n = ((value15 << 8) | value14) & 0x8000;
        r->xf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x975C, 0x7EBBFE); GUARD_JSR(c, sp_call, 0x975C); } /* queue_palette_upload */
        r->sp += 6;
        bool m_ret4 = r->mf;
        uint8_t value16 = RAM8(0x0000 + sp0 - 5);
        if (m_ret4) {
            uint8_t value19 = RAM8(0x0000 + sp0 - 2);
            uint8_t value20 = RAM8(0x0000 + sp0 - 1);
            uint8_t value21 = RAM8(0x0000 + sp0);
            r->c = value19 & 0x01;
            r->v = value19 & 0x40;
            r->mf = value19 & 0x20;
            r->xf = value19 & 0x10;
            r->db = value16;
            r->dp = (value21 << 8) | value20;
            r->i = value19 & 0x04;
            r->d = value19 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    }
    shared_9744_1:;
    r->a = (a_hi_97442 << 8) | 8;
    r->x = x_97442;
    r->c = carry_97442;
    r->z = 0;
    r->n = 0;
    r->v = overflow_97442;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_97442;
    r->dp = direct_page_97442;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9748, 0x7EBBAB); GUARD_JSR(c, sp_call, 0x9748); } /* allocate_palette_slot */
    r->sp += 6;
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret4 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all6 = r->a;
    uint16_t x_ret10 = r->x;
    bool carry_ret6 = r->c;
    bool overflow_ret6 = r->v;
    uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 1));
    BUS8_SET(c, (uint16_t)(dp_ret5 + 1), (uint8_t)(value27 - 1));
    if ((uint8_t)(value27 - 1) != 0) {
        a_hi_97442 = a_all6 >> 8;
        x_97442 = x_ret10;
        carry_97442 = carry_ret6;
        overflow_97442 = overflow_ret6;
        direct_page_97442 = dp_ret5;
        data_bank_97442 = db_ret4;
        goto shared_9744_1;
    }
    RAM8(0x0000 + sp0 - 6) = x_ret10 >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)x_ret10;
    r->a = 0x7E87;
    r->y = 0x5140;
    r->z = 0;
    r->n = 1;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9758, 0x7EBC9A); GUARD_JSR(c, sp_call, 0x9758); } /* copy_palette_colours */
    r->sp += 8;
    bool x_ret11 = r->xf;
    if (x_ret11) {
        c->fail = 3;
        return;
    } else {
        uint8_t value40 = RAM8(0x0000 + sp0 - 7);
        uint8_t value41 = RAM8(0x0000 + sp0 - 6);
        r->x = (value41 << 8) | value40;
        r->z = ((value41 << 8) | value40) == 0;
        r->n = ((value41 << 8) | value40) & 0x8000;
        r->xf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x975C, 0x7EBBFE); GUARD_JSR(c, sp_call, 0x975C); } /* queue_palette_upload */
        r->sp += 6;
        bool m_ret7 = r->mf;
        uint8_t value42 = RAM8(0x0000 + sp0 - 5);
        if (m_ret7) {
            uint8_t value45 = RAM8(0x0000 + sp0 - 2);
            uint8_t value46 = RAM8(0x0000 + sp0 - 1);
            uint8_t value47 = RAM8(0x0000 + sp0);
            r->c = value45 & 0x01;
            r->v = value45 & 0x40;
            r->mf = value45 & 0x20;
            r->xf = value45 & 0x10;
            r->db = value42;
            r->dp = (value47 << 8) | value46;
            r->i = value45 & 0x04;
            r->d = value45 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    }
}
SOM_REGISTER(0x7E9716, SOM_RTS, "gen", copy_native_title_font_and_register_eight_upper_palette_slots, 0, L_B | L_X | L_Y | L_C | L_V, 14, 0, 0, 77, 47)
