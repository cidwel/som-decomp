#include "som_c.h"

/* 7EBA21 update_nine_warm_child_sprite_animation_records   [class B, 94 bytes, 51 instructions]
 * Source: src/boot/update_nine_warm_child_sprite_animation_records.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$04EC.  Callers read: CV.
 */
static void update_nine_warm_child_sprite_animation_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x04EC) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 4;
    RAM8(0x0000 + sp0 - 1) = 0xEC;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), x);
    uint16_t value = BUS16(c, 0x7F0012 + x);
    if ((uint16_t)(value + 1) < 4) {
        BUS16_SET(c, 0x7F0012 + x, (uint16_t)(value + 1));
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 9);
        uint16_t value2 = RAM16(0x603A + (uint16_t)(value + 1));
        uint16_t value3 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        uint8_t a1 = value2 & 0xFF;
        uint8_t a_hi1 = 0;
        uint16_t x1 = value3;
        bool carry1 = (uint16_t)(value + 1) >= 4;
        bool overflow1 = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
        uint8_t data_bank = 0x7F;
        uint16_t direct_page = (uint16_t)(sp0 - 7);
        for (;;) {
            uint16_t value4 = BUS16_RDP(c, (data_bank << 0x10) + x1);
            BUS16_SET(c, (data_bank << 0x10) + 6 + value4, (a_hi1 << 8) | a1);
            RAM8(0x0000 + sp0 - 7) = x1 >> 8;
            RAM8(0x0000 + sp0 - 8) = (uint8_t)x1;
            RAM8(0x0000 + sp0 - 9) = a_hi1;
            RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)((a_hi1 << 8) | a1);
            r->a = (a_hi1 << 8) | a1;
            r->x = value4;
            r->y = value4;
            r->c = carry1;
            r->z = value4 == 0;
            r->n = value4 & 0x8000;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBA6C, 0x7EB7B9); GUARD_JSR(c, sp_call, 0xBA6C); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 11;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            uint8_t value5 = RAM8(0x0000 + sp0 - 0x0A);
            uint8_t value6 = RAM8(0x0000 + sp0 - 9);
            uint8_t value7 = RAM8(0x0000 + sp0 - 8);
            uint8_t value8 = RAM8(0x0000 + sp0 - 7);
            uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value9 - 1));
            a1 = (uint8_t)(((value6 << 8) | value5) + 1);
            a_hi1 = (uint16_t)(((value6 << 8) | value5) + 1) >> 8;
            x1 = (uint16_t)(((value8 << 8) | value7) + 2);
            carry1 = carry_ret;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
            if (!((uint16_t)(value9 - 1) != 0)) break;
        }
        uint8_t value14 = RAM8(0x0000 + sp0 - 2);
        uint8_t value15 = RAM8(0x0000 + sp0 - 1);
        uint8_t value16 = RAM8(0x0000 + sp0);
        r->c = value14 & 0x01;
        r->v = value14 & 0x40;
        r->mf = value14 & 0x20;
        r->xf = value14 & 0x10;
        r->db = data_bank;
        r->dp = (value16 << 8) | value15;
        r->i = value14 & 0x04;
        r->d = value14 & 0x08;
        RETURN_RTS(c);
    }
    r->a = 4;
    r->c = (uint16_t)(value + 1) >= 4;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBA3C, 0x7EC288); GUARD_JSR(c, sp_call, 0xBA3C); } /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 7;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    if (a_all2 == 0) {
        uint16_t value17 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        BUS16_SET(c, 0x7F0014 + value17, (uint16_t)(a_all2 + 8));
        BUS16_SET(c, 0x7F0012 + value17, 0);
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 9);
        uint16_t value18 = RAM16(0x603A + 0);
        uint16_t value19 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        uint8_t a2 = value18 & 0xFF;
        uint8_t a_hi2 = 0;
        uint16_t x2 = value19;
        bool carry2 = a_all2 + 8 > 0xFFFF;
        bool overflow2 = ((a_all2 ^ (uint16_t)(a_all2 + 8)) & ((uint16_t)(a_all2 + 8) ^ 8) & 0x8000) != 0;
        uint8_t data_bank2 = 0x7F;
        uint16_t direct_page2 = (uint16_t)(sp0 - 7);
        for (;;) {
            uint16_t value20 = BUS16_RDP(c, (data_bank2 << 0x10) + x2);
            BUS16_SET(c, (data_bank2 << 0x10) + 6 + value20, (a_hi2 << 8) | a2);
            RAM8(0x0000 + sp0 - 7) = x2 >> 8;
            RAM8(0x0000 + sp0 - 8) = (uint8_t)x2;
            RAM8(0x0000 + sp0 - 9) = a_hi2;
            RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)((a_hi2 << 8) | a2);
            r->a = (a_hi2 << 8) | a2;
            r->x = value20;
            r->y = value20;
            r->c = carry2;
            r->z = value20 == 0;
            r->n = value20 & 0x8000;
            r->v = overflow2;
            r->mf = 0;
            r->xf = 0;
            r->db = data_bank2;
            r->dp = direct_page2;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBA6C, 0x7EB7B9); GUARD_JSR(c, sp_call, 0xBA6C); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 11;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            uint8_t value21 = RAM8(0x0000 + sp0 - 0x0A);
            uint8_t value22 = RAM8(0x0000 + sp0 - 9);
            uint8_t value23 = RAM8(0x0000 + sp0 - 8);
            uint8_t value24 = RAM8(0x0000 + sp0 - 7);
            uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value25 - 1));
            a2 = (uint8_t)(((value22 << 8) | value21) + 1);
            a_hi2 = (uint16_t)(((value22 << 8) | value21) + 1) >> 8;
            x2 = (uint16_t)(((value24 << 8) | value23) + 2);
            carry2 = carry_ret3;
            overflow2 = overflow_ret3;
            data_bank2 = db_ret2;
            direct_page2 = dp_ret2;
            if (!((uint16_t)(value25 - 1) != 0)) break;
        }
        uint8_t value30 = RAM8(0x0000 + sp0 - 2);
        uint8_t value31 = RAM8(0x0000 + sp0 - 1);
        uint8_t value32 = RAM8(0x0000 + sp0);
        r->c = value30 & 0x01;
        r->v = value30 & 0x40;
        r->mf = value30 & 0x20;
        r->xf = value30 & 0x10;
        r->db = data_bank2;
        r->dp = (value32 << 8) | value31;
        r->i = value30 & 0x04;
        r->d = value30 & 0x08;
        RETURN_RTS(c);
    }
    uint16_t value33 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
    BUS16_SET(c, 0x7F0014 + value33, 0x10);
    BUS16_SET(c, 0x7F0012 + value33, 0);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 9);
    uint16_t value34 = RAM16(0x603A + 0);
    uint16_t value35 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
    uint8_t a3 = value34 & 0xFF;
    uint8_t a_hi3 = 0;
    uint16_t x3 = value35;
    bool carry3 = 0;
    bool overflow3 = 0;
    uint8_t data_bank3 = 0x7F;
    uint16_t direct_page3 = (uint16_t)(sp0 - 7);
    for (;;) {
        uint16_t value36 = BUS16_RDP(c, (data_bank3 << 0x10) + x3);
        BUS16_SET(c, (data_bank3 << 0x10) + 6 + value36, (a_hi3 << 8) | a3);
        RAM8(0x0000 + sp0 - 7) = x3 >> 8;
        RAM8(0x0000 + sp0 - 8) = (uint8_t)x3;
        RAM8(0x0000 + sp0 - 9) = a_hi3;
        RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)((a_hi3 << 8) | a3);
        r->a = (a_hi3 << 8) | a3;
        r->x = value36;
        r->y = value36;
        r->c = carry3;
        r->z = value36 == 0;
        r->n = value36 & 0x8000;
        r->v = overflow3;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank3;
        r->dp = direct_page3;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBA6C, 0x7EB7B9); GUARD_JSR(c, sp_call, 0xBA6C); } /* publish_native_sprite_record_with_data_bank_7f */
        r->sp += 11;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        uint8_t value37 = RAM8(0x0000 + sp0 - 0x0A);
        uint8_t value38 = RAM8(0x0000 + sp0 - 9);
        uint8_t value39 = RAM8(0x0000 + sp0 - 8);
        uint8_t value40 = RAM8(0x0000 + sp0 - 7);
        uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 1), (uint16_t)(value41 - 1));
        a3 = (uint8_t)(((value38 << 8) | value37) + 1);
        a_hi3 = (uint16_t)(((value38 << 8) | value37) + 1) >> 8;
        x3 = (uint16_t)(((value40 << 8) | value39) + 2);
        carry3 = carry_ret4;
        overflow3 = overflow_ret4;
        data_bank3 = db_ret3;
        direct_page3 = dp_ret3;
        if (!((uint16_t)(value41 - 1) != 0)) break;
    }
    uint8_t value46 = RAM8(0x0000 + sp0 - 2);
    uint8_t value47 = RAM8(0x0000 + sp0 - 1);
    uint8_t value48 = RAM8(0x0000 + sp0);
    r->c = value46 & 0x01;
    r->v = value46 & 0x40;
    r->mf = value46 & 0x20;
    r->xf = value46 & 0x10;
    r->db = data_bank3;
    r->dp = (value48 << 8) | value47;
    r->i = value46 & 0x04;
    r->d = value46 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EBA21, SOM_RTS, "gen", update_nine_warm_child_sprite_animation_records, 0, L_C | L_V, 11, 1, 0, 94, 51)
