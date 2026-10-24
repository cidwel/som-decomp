#include "som_c.h"

/* C1412A queue_spell_entity_oam_transfer   [class B, 55 bytes, 28 instructions]
 * Source: src/rom/queue_spell_entity_oam_transfer.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$01B4.  Callers read: BXYCV.
 */
static void queue_spell_entity_oam_transfer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01B4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xB4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    uint16_t value = RAM16(0x841E);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value == 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a_hi;
        x1 = value;
        y1 = y;
        data_bank = 0x7E;
        direct_page = 0x01B4;
    } else {
        r->a = 0xFF04;
        r->x = value;
        r->z = 0;
        r->n = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4141, 0xC12896); GUARD_JSR(c, sp_call, 0x4141); } /* allocate_spell_entity_actor_slot */
        r->sp += 4;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t x_ret2 = r->x;
        BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret2, 0x7E);
        uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x841E);
        BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret2, value2);
        BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret2, 0x0220);
        BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret2, 0);
        r->a = 0x0220;
        r->z = 0;
        r->n = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x415C, 0xC12997); GUARD_JSR(c, sp_call, 0x415C); } /* publish_spell_entity_record_or_dma_channel */
        r->sp += 4;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        m_flag = m_ret;
        x_flag = x_ret3;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret4;
        y1 = y_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = value4 & 0x01;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value3;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1412A, SOM_RTS, "gen", queue_spell_entity_oam_transfer, 0, L_B | L_X | L_Y | L_C | L_V, 5, 1, 0, 55, 28)
