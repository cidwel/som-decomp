#include "som_c.h"

/* 7EA2EB initialize_native_controller_service_and_enable_automatic_polling   [class D, 41 bytes, 21 instructions]
 * Source: src/boot/initialize_native_controller_service_and_enable_automatic_polling.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: BYCZNV.
 */
static void initialize_native_controller_service_and_enable_automatic_polling(SomCtx *c)
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
    r->a = (a >> 8 << 8) | 0;
    r->x = 0x50;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA2FD, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xA2FD); } /* allocate_and_fill_bytes */
    r->sp += 4;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x10092) = (uint8_t)x_ret2;
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)y_ret;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA303, 0x7EA4E9); GUARD_JSR(c, sp_call, 0xA303); } /* detect_controller_interface */
        r->sp += 4;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0x90);
        BUS8_SET(c, (db_ret << 0x10) + 0x90, value | 1);
        BUS8_SET(c, 0x004200, value | 1);
        uint8_t value2 = RAM8(0x0000 + sp0 - 3);
        uint8_t value3 = RAM8(0x0000 + sp0 - 2);
        uint8_t value4 = RAM8(0x0000 + sp0 - 1);
        uint8_t value5 = RAM8(0x0000 + sp0);
        r->c = value3 & 0x01;
        r->z = ((value5 << 8) | value4) == 0;
        r->n = ((value5 << 8) | value4) & 0x8000;
        r->v = value3 & 0x40;
        r->mf = value3 & 0x20;
        r->xf = value3 & 0x10;
        r->db = value2;
        r->dp = (value5 << 8) | value4;
        r->i = value3 & 0x04;
        r->d = value3 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        RAM16_SET(0x10092, x_ret2);
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA303, 0x7EA4E9); GUARD_JSR(c, sp_call, 0xA303); } /* detect_controller_interface */
        r->sp += 4;
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint8_t value6 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x90);
        BUS8_SET(c, (db_ret2 << 0x10) + 0x90, value6 | 1);
        BUS8_SET(c, 0x004200, value6 | 1);
        uint8_t value7 = RAM8(0x0000 + sp0 - 3);
        uint8_t value8 = RAM8(0x0000 + sp0 - 2);
        uint8_t value9 = RAM8(0x0000 + sp0 - 1);
        uint8_t value10 = RAM8(0x0000 + sp0);
        r->c = value8 & 0x01;
        r->z = ((value10 << 8) | value9) == 0;
        r->n = ((value10 << 8) | value9) & 0x8000;
        r->v = value8 & 0x40;
        r->mf = value8 & 0x20;
        r->xf = value8 & 0x10;
        r->db = value7;
        r->dp = (value10 << 8) | value9;
        r->i = value8 & 0x04;
        r->d = value8 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EA2EB, SOM_RTS, "gen", initialize_native_controller_service_and_enable_automatic_polling, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 41, 21)
