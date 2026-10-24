#include "som_c.h"

/* C1302E build_spell_entity_script_transfers   [class B, 180 bytes, 96 instructions]
 * Source: src/rom/build_spell_entity_script_transfers.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$01C0.  Callers read: BYCV.
 */
static void build_spell_entity_script_transfers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01C0) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xC0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), x);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), value & 0xFF);
    uint8_t a_hi1 = (uint16_t)(y - 0xF800) >> 8;
    uint16_t x1 = (uint16_t)(y - 0xF800);
    uint16_t y1 = y;
    bool carry1 = y >= 0xF800;
    bool overflow1 = ((y ^ 0xF800) & (y ^ (uint16_t)(y - 0xF800)) & 0x8000) != 0;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 9);
    for (;;) {
        BUS16_SET(c, (uint16_t)(direct_page + 5), x1);
        r->a = 1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0x305B, 0xC12896); GUARD_JSR(c, sp_call, 0x305B); } /* allocate_spell_entity_actor_slot */
        r->sp += 10;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret = r->x;
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
        uint16_t value3 = BUS16(c, 0xDCF800 + value2);
        BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret, ((value3 & 0xFF) << 1 << 1 << 1 << 1) + 0x7000);
        uint16_t value4 = BUS16(c, 0xDCF801 + value2);
        if ((value4 & 0xFF) == 0xFF) {
            BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret, 0x302C);
            BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret, 0xC1);
            BUS8_SET(c, (db_ret << 0x10) + x_ret, 9);
            uint16_t value5 = BUS16(c, 0xDCF802 + value2);
            BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret, (value5 & 0x7F) << 1 << 1 << 1 << 1 << 1);
            r->a = (value5 & 0x7F) << 1 << 1 << 1 << 1 << 1;
            r->y = x_ret;
            r->c = (value5 & 0x7F) << 1 << 1 << 1 << 1 & 0x8000;
            r->z = x_ret == 0;
            r->n = x_ret & 0x8000;
            r->v = ((((value3 & 0xFF) << 1 << 1 << 1 << 1) ^ ((value3 & 0xFF) << 1 << 1 << 1 << 1) + 0x7000) & (((value3 & 0xFF) << 1 << 1 << 1 << 1) + 0x7000 ^ 0x7000) & 0x8000) != 0;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x30CB, 0xC12997); GUARD_JSR(c, sp_call, 0x30CB); } /* publish_spell_entity_record_or_dma_channel */
            r->sp += 10;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
            uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value7 - 1));
            if ((uint16_t)(value7 - 1) == 0) {
                a_hi1 = a_all2 >> 8;
                x1 = (uint16_t)(value6 + 3);
                y1 = y_ret2;
                carry1 = carry_ret2;
                overflow1 = overflow_ret2;
                data_bank = db_ret2;
                direct_page = dp_ret2;
                break;
            }
            a_hi1 = a_all2 >> 8;
            x1 = (uint16_t)(value6 + 3);
            y1 = y_ret2;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret2;
            continue;
        }
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret, (uint16_t)(((value4 & 0xFF) << 1 << 1 << 1 << 1 << 1) + value8));
        uint8_t value9 = BUS8(c, 0xDCF802 + value2);
        if ((value9 & 0x80) == 0) {
            BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret, 0x7E);
            uint16_t value10 = BUS16(c, 0xDCF802 + value2);
            BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret, (value10 & 0x7F) << 1 << 1 << 1 << 1 << 1);
            r->a = (value10 & 0x7F) << 1 << 1 << 1 << 1 << 1;
            r->y = x_ret;
            r->c = (value10 & 0x7F) << 1 << 1 << 1 << 1 & 0x8000;
            r->z = x_ret == 0;
            r->n = x_ret & 0x8000;
            r->v = ((((value4 & 0xFF) << 1 << 1 << 1 << 1 << 1) ^ (uint16_t)(((value4 & 0xFF) << 1 << 1 << 1 << 1 << 1) + value8)) & (value8 ^ (uint16_t)(((value4 & 0xFF) << 1 << 1 << 1 << 1 << 1) + value8)) & 0x8000) != 0;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x30CB, 0xC12997); GUARD_JSR(c, sp_call, 0x30CB); } /* publish_spell_entity_record_or_dma_channel */
            r->sp += 10;
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all3 = r->a;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 5));
            uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 1), (uint16_t)(value12 - 1));
            if ((uint16_t)(value12 - 1) == 0) {
                a_hi1 = a_all3 >> 8;
                x1 = (uint16_t)(value11 + 3);
                y1 = y_ret3;
                carry1 = carry_ret3;
                overflow1 = overflow_ret3;
                data_bank = db_ret3;
                direct_page = dp_ret3;
                break;
            }
            a_hi1 = a_all3 >> 8;
            x1 = (uint16_t)(value11 + 3);
            y1 = y_ret3;
            carry1 = carry_ret3;
            overflow1 = overflow_ret3;
            data_bank = db_ret3;
            direct_page = dp_ret3;
            continue;
        }
        BUS8_SET(c, (db_ret << 0x10) + x_ret, 0x81);
        BUS8_SET(c, (db_ret << 0x10) + 1 + x_ret, 0x39);
        BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret, 0x7E);
        uint16_t value13 = BUS16(c, 0xDCF802 + value2);
        BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret, (value13 & 0x7F) << 1 << 1 << 1 << 1 << 1);
        r->a = (value13 & 0x7F) << 1 << 1 << 1 << 1 << 1;
        r->y = x_ret;
        r->c = (value13 & 0x7F) << 1 << 1 << 1 << 1 & 0x8000;
        r->z = x_ret == 0;
        r->n = x_ret & 0x8000;
        r->v = ((((value4 & 0xFF) << 1 << 1 << 1 << 1 << 1) ^ (uint16_t)(((value4 & 0xFF) << 1 << 1 << 1 << 1 << 1) + value8)) & (value8 ^ (uint16_t)(((value4 & 0xFF) << 1 << 1 << 1 << 1 << 1) + value8)) & 0x8000) != 0;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0x30CB, 0xC12997); GUARD_JSR(c, sp_call, 0x30CB); } /* publish_spell_entity_record_or_dma_channel */
        r->sp += 10;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all4 = r->a;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 5));
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 1), (uint16_t)(value15 - 1));
        if ((uint16_t)(value15 - 1) == 0) {
            a_hi1 = a_all4 >> 8;
            x1 = (uint16_t)(value14 + 3);
            y1 = y_ret4;
            carry1 = carry_ret4;
            overflow1 = overflow_ret4;
            data_bank = db_ret4;
            direct_page = dp_ret4;
            break;
        }
        a_hi1 = a_all4 >> 8;
        x1 = (uint16_t)(value14 + 3);
        y1 = y_ret4;
        carry1 = carry_ret4;
        overflow1 = overflow_ret4;
        data_bank = db_ret4;
        direct_page = dp_ret4;
        continue;
    }
    uint8_t value16 = RAM8(0x0000 + sp0 - 9);
    uint8_t value17 = RAM8(0x0000 + sp0 - 2);
    uint8_t value18 = RAM8(0x0000 + sp0 - 1);
    uint8_t value19 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
    r->y = y1;
    r->c = value17 & 0x01;
    r->v = value17 & 0x40;
    r->mf = value17 & 0x20;
    r->xf = value17 & 0x10;
    r->db = value16;
    r->dp = (value19 << 8) | value18;
    r->i = value17 & 0x04;
    r->d = value17 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1302E, SOM_RTS, "gen", build_spell_entity_script_transfers, 0, L_B | L_Y | L_C | L_V, 12, 0, 0, 180, 96)
