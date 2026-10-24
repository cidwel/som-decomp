#include "som_c.h"

/* 7E94BF construct_warm_scene_colour_hdma_records   [class B, 153 bytes, 75 instructions]
 * Source: src/boot/construct_warm_scene_colour_hdma_records.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$02E4.  Callers read: XYCZNV.
 */
static void construct_warm_scene_colour_hdma_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x02E4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xE4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = (uint16_t)(sp0 - 0x0D);
    r->x = 0x31;
    r->c = (uint16_t)(sp0 - 3) >= 0x0A;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
    r->mf = 1;
    r->dp = (uint16_t)(sp0 - 0x0D);
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0x94D1, 0x7EB081); GUARD_JSR(c, sp_call, 0x94D1); } /* allocate_boot_heap_bytes_without_fill */
    r->sp += 13;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    BUS16_SET(c, (uint16_t)(dp_ret + 3), x_ret);
    BUS16_SET(c, (uint16_t)(dp_ret + 5), 0x5ECD);
    BUS8_SET(c, (uint16_t)(dp_ret + 7), 0x7E);
    BUS16_SET(c, (uint16_t)(dp_ret + 8), 0x51C0);
    BUS8_SET(c, (uint16_t)(dp_ret + 0x0A), 0x7E);
    BUS8_SET(c, (uint16_t)(dp_ret + 1), 0x10);
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = x_ret;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp_ret + 7)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp_ret + 5)) + y1, BUS8_RDP(c, (uint16_t)(dp_ret + 7)));
        BUS8_SET(c, (db_ret << 0x10) + x1, value);
        uint16_t value2 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(dp_ret + 0x0A)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp_ret + 8)) + y1, BUS8_RDP(c, (uint16_t)(dp_ret + 0x0A)));
        BUS16_SET(c, (db_ret << 0x10) + 1 + x1, value2);
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value3 - 1));
        a_hi1 = value2 >> 8;
        x1 = (uint16_t)(x1 + 3);
        y1 = (uint16_t)(y1 + 2);
        if (!((uint8_t)(value3 - 1) != 0)) break;
    }
    BUS8_SET(c, (db_ret << 0x10) + x1, 0);
    r->a = 5;
    r->x = x1;
    r->y = y1;
    r->c = carry_ret;
    r->z = 0;
    r->n = 0;
    r->v = overflow_ret;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9510, 0x7E8FC7); GUARD_JSR(c, sp_call, 0x9510); } /* allocate_transfer_descriptor */
    r->sp += 13;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret2 = r->xf;
    uint16_t x_ret3 = r->x;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    BUS8_SET(c, (db_ret2 << 0x10) + x_ret3, 2);
    BUS8_SET(c, (db_ret2 << 0x10) + 1 + x_ret3, 0x22);
    BUS8_SET(c, (db_ret2 << 0x10) + 4 + x_ret3, 0x7F);
    RAM8(0x0000 + sp0 - 0x0D) = ((((overflow_ret2 << 6) | 0x20) | (x_ret2 << 4)) | (d_entry << 3)) | (i_entry << 2) | carry_ret2;
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
    BUS16_SET(c, (db_ret2 << 0x10) + 2 + x_ret3, value4);
    r->a = value4;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->mf = 0;
    r->i = 1;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0x952B, 0x7E90DA); GUARD_JSR(c, sp_call, 0x952B); } /* submit_transfer_or_program_hdma */
    r->sp += 14;
    if (r->mf != 0) { c->fail = 3; return; }
    r->a = 5;
    r->z = 0;
    r->n = 0;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9531, 0x7E8FC7); GUARD_JSR(c, sp_call, 0x9531); } /* allocate_transfer_descriptor */
    r->sp += 14;
    uint8_t db_ret4 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t x_ret7 = r->x;
    BUS16_SET(c, (db_ret4 << 0x10) + 2 + x_ret7, 0x5ECD);
    BUS8_SET(c, (db_ret4 << 0x10) + x_ret7, 0);
    BUS8_SET(c, (db_ret4 << 0x10) + 1 + x_ret7, 0x21);
    BUS8_SET(c, (db_ret4 << 0x10) + 4 + x_ret7, 0x7E);
    r->a = 0x5E7E;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0x954B, 0x7E90DA); GUARD_JSR(c, sp_call, 0x954B); } /* submit_transfer_or_program_hdma */
    r->sp += 14;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret5 = r->y;
    uint8_t value5 = RAM8(0x0000 + sp0 - 0x0D);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->x = x_ret9 & 0xFFFF - ((value5 >> 4) & 1) * 0xFF00;
    r->y = y_ret5 & 0xFFFF - ((value5 >> 4) & 1) * 0xFF00;
    r->c = value6 & 0x01;
    r->z = ((value8 << 8) | value7) == 0;
    r->n = ((value8 << 8) | value7) & 0x8000;
    r->v = value6 & 0x40;
    r->mf = value6 & 0x20;
    r->xf = value6 & 0x10;
    r->dp = (value8 << 8) | value7;
    r->i = value6 & 0x04;
    r->d = value6 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E94BF, SOM_RTS, "gen", construct_warm_scene_colour_hdma_records, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 14, 0, 0, 153, 75)
