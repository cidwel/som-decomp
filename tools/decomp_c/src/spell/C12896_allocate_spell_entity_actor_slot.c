#include "som_c.h"

/* C12896 allocate_spell_entity_actor_slot   [class B, 141 bytes, 77 instructions]
 * Source: src/rom/allocate_spell_entity_actor_slot.s
 * Documented in docs/actor-cast-entity-slots.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: XYCV.
 */
static void allocate_spell_entity_actor_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = a >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = x;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 5);
    for (;;) {
        uint16_t value = BUS16_RDP(c, (data_bank << 0x10) + 0x8212);
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = value;
        uint16_t y1 = 0x20;
        bool carry1 = 0;
        bool zero1 = 0;
        bool negative1 = 0;
        bool overflow1 = 0;
        for (;;) {
            uint8_t value2 = BUS8_RDP(c, (data_bank << 0x10) + 0x0F + x2);
            if (value2 != 0) {
                if ((uint16_t)(y1 - 1) != 0) {
                    uint8_t a_hi2_next = (uint16_t)(x2 + 0x10) >> 8;
                    uint16_t x2_next = (uint16_t)(x2 + 0x10);
                    uint16_t y1_next = (uint16_t)(y1 - 1);
                    bool carry1_next = x2 + 0x10 > 0xFFFF;
                    bool zero1_next = (uint16_t)(y1 - 1) == 0;
                    bool negative1_next = (uint16_t)(y1 - 1) & 0x8000;
                    bool overflow1_next = ((x2 ^ (uint16_t)(x2 + 0x10)) & ((uint16_t)(x2 + 0x10) ^ 0x10) & 0x8000) != 0;
                    a_hi2 = a_hi2_next;
                    x2 = x2_next;
                    y1 = y1_next;
                    carry1 = carry1_next;
                    zero1 = zero1_next;
                    negative1 = negative1_next;
                    overflow1 = overflow1_next;
                    continue;
                }
                uint8_t a_hi2_next2 = (uint16_t)(x2 + 0x10) >> 8;
                uint16_t x2_next2 = (uint16_t)(x2 + 0x10);
                uint16_t y1_next2 = (uint16_t)(y1 - 1);
                bool carry1_next2 = x2 + 0x10 > 0xFFFF;
                bool zero1_next2 = (uint16_t)(y1 - 1) == 0;
                bool negative1_next2 = (uint16_t)(y1 - 1) & 0x8000;
                bool overflow1_next2 = ((x2 ^ (uint16_t)(x2 + 0x10)) & ((uint16_t)(x2 + 0x10) ^ 0x10) & 0x8000) != 0;
                a_hi2 = a_hi2_next2;
                x2 = x2_next2;
                y1 = y1_next2;
                carry1 = carry1_next2;
                zero1 = zero1_next2;
                negative1 = negative1_next2;
                overflow1 = overflow1_next2;
                break;
            }
            a_hi1 = a_hi2;
            x1 = x2;
            goto leave_loop_C128AD_3;
        }
        r->a = (a_hi2 << 8) | (uint8_t)a;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0x28C7, 0xC12A1E); GUARD_JSR(c, sp_call, 0x28C7); } /* service_pending_spell_entity_transfer_requests */
        r->sp += 8;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        uint16_t x_ret2 = r->x;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0x28CA, 0xC12FE4); GUARD_JSR(c, sp_call, 0x28CA); } /* wait_for_spell_entity_irq_completion */
        r->sp += 8;
        bool m_ret2 = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        if (m_ret2 != 1) { c->fail = 3; return; }
        if (x_ret3 != 0) { c->fail = 3; return; }
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    leave_loop_C128AD_3:;
    uint8_t value3 = RAM8(0x0000 + sp0 - 7);
    uint8_t value4 = RAM8(0x0000 + sp0 - 6);
    BUS8_SET(c, (data_bank << 0x10) + 0x0F + x1, (uint8_t)((value4 << 8) | value3));
    BUS8_SET(c, (data_bank << 0x10) + 0x0D + x1, value4);
    RAM8(0x0000 + sp0 - 6) = x1 >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)x1;
    uint8_t a_hi5;
    if (value4 == 0) {
        a_hi5 = (uint8_t)((value4 << 8) | value3);
    } else {
        uint8_t a_hi4;
        if (value4 == 0x20) {
            uint16_t value5 = BUS16_RDP(c, (data_bank << 0x10) + 0x8216);
            uint8_t value6 = BUS8_RDP(c, (data_bank << 0x10) + (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5));
            BUS8_SET(c, (data_bank << 0x10) + (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5), (uint8_t)(value6 + 1));
            a_hi4 = (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5) >> 8;
        } else {
            uint8_t a_hi3;
            if (value4 >= 0x20) {
                a_hi3 = (uint8_t)((value4 << 8) | value3);
            } else {
                uint16_t value7 = BUS16_RDP(c, (data_bank << 0x10) + 0x8216);
                uint8_t value8 = BUS8_RDP(c, (data_bank << 0x10) + (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value7));
                BUS8_SET(c, (data_bank << 0x10) + (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value7), (uint8_t)(value8 + 1));
                a_hi3 = (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value7) >> 8;
            }
            a_hi4 = a_hi3;
        }
        a_hi5 = a_hi4;
    }
    uint8_t value9 = RAM8(0x0000 + sp0 - 7);
    uint8_t value10 = RAM8(0x0000 + sp0 - 6);
    uint8_t value11 = BUS8_RDP(c, (data_bank << 0x10) + 0x0F + ((value10 << 8) | value9));
    uint8_t value12 = BUS8(c, 0xDCF838 + (uint8_t)((value11 & 7) - 1));
    BUS8_SET(c, (data_bank << 0x10) + ((value10 << 8) | value9), value12);
    uint8_t value13 = BUS8(c, 0xDCF83D + (uint8_t)((value11 & 7) - 1));
    BUS8_SET(c, (data_bank << 0x10) + 9 + ((value10 << 8) | value9), value13);
    uint8_t value14 = BUS8(c, 0xDCF842 + (uint8_t)((value11 & 7) - 1));
    BUS8_SET(c, (data_bank << 0x10) + 1 + ((value10 << 8) | value9), value14);
    uint8_t value15 = BUS8_RDP(c, (data_bank << 0x10) + 0x0F + ((value10 << 8) | value9));
    uint8_t value16 = RAM8(0x0000 + sp0 - 5);
    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
    uint8_t value21 = RAM8(0x0000 + sp0);
    r->x = (value10 << 8) | value9;
    r->y = (value10 << 8) | value9;
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
}
SOM_REGISTER(0xC12896, SOM_RTS, "gen", allocate_spell_entity_actor_slot, 0, L_X | L_Y | L_C | L_V, 8, -1, 0, 141, 77)
