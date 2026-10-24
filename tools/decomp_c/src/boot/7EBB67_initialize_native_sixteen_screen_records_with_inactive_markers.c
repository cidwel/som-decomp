#include "som_c.h"

/* 7EBB67 initialize_native_sixteen_screen_records_with_inactive_markers   [class B, 47 bytes, 26 instructions]
 * Source: src/boot/initialize_native_sixteen_screen_records_with_inactive_markers.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: BYCZNV.
 */
static void initialize_native_sixteen_screen_records_with_inactive_markers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = 0;
    r->x = 0x0400;
    r->z = 1;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBB7C, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xBB7C); } /* allocate_and_fill_bytes */
    r->sp += 4;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x102D2, x_ret);
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = x_ret;
    uint16_t y1 = 0x10;
    for (;;) {
        BUS16_SET(c, 0x7F0000 + x1, 0x8000);
        uint8_t a_hi1_next = (uint16_t)(x1 + 0x20) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 0x20);
        uint16_t y1_next = (uint16_t)(y1 - 1);
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        if (!(y1 != 0)) break;
    }
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->y = y1;
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
}
SOM_REGISTER(0x7EBB67, SOM_RTS, "gen", initialize_native_sixteen_screen_records_with_inactive_markers, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 47, 26)
