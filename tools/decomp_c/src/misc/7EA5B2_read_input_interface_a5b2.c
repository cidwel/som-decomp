#include "som_c.h"

/* 7EA5B2 read_input_interface_a5b2   [class B, 81 bytes, 46 instructions]
 * Source: src/boot/read_input_interface_a5b2.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void read_input_interface_a5b2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 8) + 0x5 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 8) = db;
    RAM8(0x0000 + sp0 - 9) = 0;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 8), 0);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 8), 0);
    BUS8_SET(c, 0x004201, 0xBF);
    RAM8(0x0001 + (uint16_t)(sp0 - 8)) = 0x10;
    uint8_t a_hi1 = (uint16_t)(sp0 - 8) >> 8;
    bool carry1 = (uint16_t)(sp0 - 3) >= 5;
    do {
        uint8_t value = BUS8(c, 0x004016);
        uint16_t value2 = RAM16(0x0002 + (uint16_t)(sp0 - 8));
        RAM16_SET(0x0002 + (uint16_t)(sp0 - 8), (uint16_t)(RAM16(0x0002 + (uint16_t)(sp0 - 8)) << 1 | (value & 1)));
        uint16_t value3 = RAM16(0x0004 + (uint16_t)(sp0 - 8));
        RAM16_SET(0x0004 + (uint16_t)(sp0 - 8), (uint16_t)(RAM16(0x0004 + (uint16_t)(sp0 - 8)) << 1 | (((a_hi1 << 8) | ((value >> 1) | (carry1 << 7))) & 1)));
        RAM8(0x0001 + (uint16_t)(sp0 - 8))--;
        uint8_t a_hi1_next = ((((a_hi1 << 8) | ((value >> 1) | (carry1 << 7))) >> 1) | (value2 >> 0x0F << 0x0F)) >> 8;
        bool carry1_next = value3 & 0x8000;
        a_hi1 = a_hi1_next;
        carry1 = carry1_next;
    } while (RAM8(0x0001 + (uint16_t)(sp0 - 8)) != 0);
    BUS8_SET(c, 0x004201, 0xFF);
    RAM16_SET(0x0094, RAM16(0x0004 + (uint16_t)(sp0 - 8)));
    uint16_t value5 = RAM16(0x0002 + (uint16_t)(sp0 - 8));
    uint8_t value6 = RAM8(0x0000 + sp0 - 8);
    RAM16_SET(0x0000 + sp0 - 4, value5);
    uint8_t value7 = RAM8(0x0000 + sp0 - 4);
    uint8_t value8 = RAM8(0x0000 + sp0 - 3);
    uint8_t value9 = RAM8(0x0000 + sp0 - 2);
    uint8_t value10 = RAM8(0x0000 + sp0 - 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    r->a = (value8 << 8) | value7;
    r->x = x;
    r->y = y;
    r->c = value9 & 0x01;
    r->z = ((value11 << 8) | value10) == 0;
    r->n = ((value11 << 8) | value10) & 0x8000;
    r->v = value9 & 0x40;
    r->mf = value9 & 0x20;
    r->xf = value9 & 0x10;
    r->db = value6;
    r->dp = (value11 << 8) | value10;
    r->i = value9 & 0x04;
    r->d = value9 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA5B2, SOM_RTS, "gen", read_input_interface_a5b2, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 10, 1, 0, 81, 46)
