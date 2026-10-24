#include "som_c.h"

/* 7E87DF initialize_colour_workspace   [class B, 65 bytes, 32 instructions]
 * Source: src/boot/initialize_colour_workspace.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BXYCZNV.
 */
static void initialize_colour_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x10020) = (uint8_t)a;
    RAM8(0x10021) = 0;
    if (((uint8_t)a & 0x80) != 0) {
        RAM8(0x10021)--;
    }
    RAM8(0x1001E) = a >> 8;
    RAM8(0x1001F) = 0;
    if (((a >> 8) & 0x80) != 0) {
        RAM8(0x1001F)--;
    }
    RAM16_SET(0x10024, x);
    RAM16_SET(0x10022, y);
    RAM8(0x10026) = 0;
    RAM8(0x10034) = 0;
    r->a = ((uint8_t)a & 0x80) << 8 | ((a >> 8) & 0x80);
    r->x = 0x20;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8818, 0x7EB081); GUARD_JSR(c, sp_call, 0x8818); } /* allocate_boot_heap_bytes_without_fill */
    r->sp += 4;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        BUS8_SET(c, (db_ret << 0x10) + 0x30, (uint8_t)x_ret2);
        uint8_t value = RAM8(0x0000 + sp0 - 3);
        uint8_t value2 = RAM8(0x0000 + sp0 - 2);
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)y_ret;
        r->c = value2 & 0x01;
        r->z = ((value4 << 8) | value3) == 0;
        r->n = ((value4 << 8) | value3) & 0x8000;
        r->v = value2 & 0x40;
        r->mf = value2 & 0x20;
        r->xf = value2 & 0x10;
        r->db = value;
        r->dp = (value4 << 8) | value3;
        r->i = value2 & 0x04;
        r->d = value2 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        BUS16_SET(c, (db_ret << 0x10) + 0x30, x_ret2);
        uint8_t value5 = RAM8(0x0000 + sp0 - 3);
        uint8_t value6 = RAM8(0x0000 + sp0 - 2);
        uint8_t value7 = RAM8(0x0000 + sp0 - 1);
        uint8_t value8 = RAM8(0x0000 + sp0);
        r->c = value6 & 0x01;
        r->z = ((value8 << 8) | value7) == 0;
        r->n = ((value8 << 8) | value7) & 0x8000;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = value6 & 0x10;
        r->db = value5;
        r->dp = (value8 << 8) | value7;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7E87DF, SOM_RTS, "gen", initialize_colour_workspace, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 0, 0, 65, 32)
