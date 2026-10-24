#include "som_c.h"

/* 7E837E decode_component_ramp   [class B, 47 bytes, 31 instructions]
 * Source: src/boot/decode_component_ramp.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$05E9.  Callers read: BXYCV.
 */
static void decode_component_ramp(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x05E9) { c->fail = 3; return; }
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
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xE9;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0001 + (uint16_t)(sp0 - 5)) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0002 + (uint16_t)(sp0 - 5)) = 0;
    uint8_t a1 = (uint8_t)((a_hi << 8) | a);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = ((a_hi << 8) | a) == 0;
    bool negative1 = ((a_hi << 8) | a) & 0x8000;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7F;
    uint16_t direct_page = (uint16_t)(sp0 - 5);
    for (;;) {
        RAM8(0x0000 + sp0 - 5) = y1 >> 8;
        RAM8(0x0000 + sp0 - 6) = (uint8_t)y1;
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8390, 0x7EA1A7); GUARD_JSR(c, sp_call, 0x8390); } /* decode_signed_delta_or_zero_run */
        r->sp += 7;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint8_t value = RAM8(0x0000 + sp0 - 6);
        uint8_t value2 = RAM8(0x0000 + sp0 - 5);
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
        BUS8_SET(c, (db_ret << 0x10) + ((value2 << 8) | value), (uint8_t)((uint8_t)a_all + value3));
        BUS8_SET(c, (uint16_t)(dp_ret + 2), (uint8_t)((uint8_t)a_all + value3));
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value4 - 1));
        a1 = (uint8_t)(((value2 << 8) | value) + 4);
        a_hi1 = (uint16_t)(((value2 << 8) | value) + 4) >> 8;
        y1 = (uint16_t)(((value2 << 8) | value) + 4);
        carry1 = ((value2 << 8) | value) + 4 > 0xFFFF;
        zero1 = (uint8_t)(value4 - 1) == 0;
        negative1 = (uint8_t)(value4 - 1) & 0x80;
        overflow1 = ((((value2 << 8) | value) ^ (uint16_t)(((value2 << 8) | value) + 4)) & ((uint16_t)(((value2 << 8) | value) + 4) ^ 4) & 0x8000) != 0;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!((uint8_t)(value4 - 1) != 0)) break;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 3);
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value6;
    r->x = x1;
    r->y = y1;
    r->c = value7 & 0x01;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->db = data_bank;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E837E, SOM_RTS, "gen", decode_component_ramp, 0, L_B | L_X | L_Y | L_C | L_V, 7, 1, 0, 47, 31)
