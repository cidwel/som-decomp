#include "som_c.h"

/* 7EBFDA queue_thirty_eight_native_boot_ppu_defaults_from_loaded_descriptor   [class B, 68 bytes, 40 instructions]
 * Source: src/boot/queue_thirty_eight_native_boot_ppu_defaults_from_loaded_descriptor.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: XYCZNV.
 */
static void queue_thirty_eight_native_boot_ppu_defaults_from_loaded_descriptor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 8) = 0x7F;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 7), 0x6072);
    RAM8(0x0004 + (uint16_t)(sp0 - 7)) = 0x7E;
    RAM8(0x0001 + (uint16_t)(sp0 - 7)) = 0x26;
    uint8_t a_hi1 = (uint16_t)(sp0 - 7) >> 8;
    uint16_t x1 = 0x6072;
    uint16_t y1 = y;
    bool carry1 = (uint16_t)(sp0 - 3) >= 4;
    bool overflow1 = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    uint8_t data_bank = 0x7F;
    uint16_t direct_page = (uint16_t)(sp0 - 7);
    for (;;) {
        uint8_t value = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page + 4)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page + 2)), BUS8_RDP(c, (uint16_t)(direct_page + 4)));
        r->a = (a_hi1 << 8) | value;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = value == 0;
        r->n = value & 0x80;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBFFD, 0x7EC030); GUARD_JSR(c, sp_call, 0xBFFD); } /* allocate_ppu_register_entry */
        r->sp += 8;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint8_t value2 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp_ret + 4)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp_ret + 2)) + 1, BUS8_RDP(c, (uint16_t)(dp_ret + 4)));
        BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret, value2);
        BUS8_SET(c, (db_ret << 0x10) + 3 + x_ret, 0);
        r->a = (a_all >> 8 << 8) | value2;
        r->y = 1;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC00B, 0x7EC097); GUARD_JSR(c, sp_call, 0xC00B); } /* append_oneshot_ppu_entry */
        r->sp += 8;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
        BUS16_SET(c, (uint16_t)(dp_ret2 + 2), (uint16_t)(value3 + 2));
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
        BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value4 - 1));
        a_hi1 = a_all2 >> 8;
        x1 = (uint16_t)(value3 + 2);
        y1 = y_ret2;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret2;
        if (!((uint8_t)(value4 - 1) != 0)) break;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 7);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->x = x1;
    r->y = y1;
    r->c = value10 & 0x01;
    r->z = ((value12 << 8) | value11) == 0;
    r->n = ((value12 << 8) | value11) & 0x8000;
    r->v = value10 & 0x40;
    r->mf = value10 & 0x20;
    r->xf = value10 & 0x10;
    r->db = value5;
    r->dp = (value12 << 8) | value11;
    r->i = value10 & 0x04;
    r->d = value10 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EBFDA, SOM_RTS, "gen", queue_thirty_eight_native_boot_ppu_defaults_from_loaded_descriptor, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 0, 0, 68, 40)
