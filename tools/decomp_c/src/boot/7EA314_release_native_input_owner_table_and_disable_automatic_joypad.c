#include "som_c.h"

/* 7EA314 release_native_input_owner_table_and_disable_automatic_joypad   [class D, 33 bytes, 18 instructions]
 * Source: src/boot/release_native_input_owner_table_and_disable_automatic_joypad.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void release_native_input_owner_table_and_disable_automatic_joypad(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint16_t value = RAM16(0x10092);
    r->a = (a_hi << 8) | 0x7F;
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->db = 0x7F;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA324, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xA324); } /* release_native_heap_suffix_through_bank_7f_api */
    r->sp += 4;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x90);
    BUS8_SET(c, (db_ret << 0x10) + 0x90, value2 & 0xFE);
    BUS8_SET(c, 0x004200, value2 & 0xFE);
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = a_all >> 8 << 8 | (value2 & 0xFE);
    r->c = value4 & 0x01;
    r->z = ((value6 << 8) | value5) == 0;
    r->n = ((value6 << 8) | value5) & 0x8000;
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
SOM_REGISTER(0x7EA314, SOM_RTS, "gen", release_native_input_owner_table_and_disable_automatic_joypad, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 33, 18)
