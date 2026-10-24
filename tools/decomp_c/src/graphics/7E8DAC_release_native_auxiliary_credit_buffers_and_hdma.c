#include "som_c.h"

/* 7E8DAC release_native_auxiliary_credit_buffers_and_hdma   [class B, 33 bytes, 15 instructions]
 * Source: src/boot/release_native_auxiliary_credit_buffers_and_hdma.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$06ED.  Callers read: BXYCZNV.
 */
static void release_native_auxiliary_credit_buffers_and_hdma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x06ED) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0xED;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->x = 0x4A;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8DB7, 0x7E88CF); GUARD_JSR(c, sp_call, 0x8DB7); } /* release_title_auxiliary_hdma */
    r->sp += 3;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x46;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8DBD, 0x7E88CF); GUARD_JSR(c, sp_call, 0x8DBD); } /* release_title_auxiliary_hdma */
    r->sp += 3;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x42;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8DC3, 0x7E88CF); GUARD_JSR(c, sp_call, 0x8DC3); } /* release_title_auxiliary_hdma */
    r->sp += 3;
    uint8_t db_ret3 = r->db;
    bool x_ret3 = r->xf;
    uint16_t y_ret3 = r->y;
    if (x_ret3) {
        uint8_t value = BUS8_RDP(c, (db_ret3 << 0x10) + 0x40);
        r->x = value;
        r->y = (uint8_t)y_ret3;
        r->z = value == 0;
        r->n = value & 0x80;
        r->xf = 1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DC9, 0x7E9066); GUARD_JSR(c, sp_call, 0x8DC9); } /* release_transfer_descriptor */
        r->sp += 3;
        uint8_t value2 = RAM8(0x0000 + sp0 - 2);
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        r->c = value2 & 0x01;
        r->z = ((value4 << 8) | value3) == 0;
        r->n = ((value4 << 8) | value3) & 0x8000;
        r->v = value2 & 0x40;
        r->mf = value2 & 0x20;
        r->xf = value2 & 0x10;
        r->dp = (value4 << 8) | value3;
        r->i = value2 & 0x04;
        r->d = value2 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value5 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x40);
        r->x = value5;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->xf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DC9, 0x7E9066); GUARD_JSR(c, sp_call, 0x8DC9); } /* release_transfer_descriptor */
        r->sp += 3;
        uint8_t value6 = RAM8(0x0000 + sp0 - 2);
        uint8_t value7 = RAM8(0x0000 + sp0 - 1);
        uint8_t value8 = RAM8(0x0000 + sp0);
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
}
SOM_REGISTER(0x7E8DAC, SOM_RTS, "gen", release_native_auxiliary_credit_buffers_and_hdma, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 33, 15)
