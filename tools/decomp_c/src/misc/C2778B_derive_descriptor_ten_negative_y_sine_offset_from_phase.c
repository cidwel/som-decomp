#include "som_c.h"

/* C2778B derive_descriptor_ten_negative_y_sine_offset_from_phase   [class A, 28 bytes, 12 instructions]
 * Source: src/rom/derive_descriptor_ten_negative_y_sine_offset_from_phase.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void derive_descriptor_ten_negative_y_sine_offset_from_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7790, 0xC22A60); GUARD_JSR(c, sp_call, 0x7790); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    BUS16_SET(c, (uint16_t)(dp_ret + 0x46), a_all);
    BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), 8);
    r->a = 8;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x779A, 0xC22B94); GUARD_JSR(c, sp_call, 0x779A); } /* multiply_signed_words_to_double_word */
    bool x_ret3 = r->xf;
    if (x_ret3) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 0x035C);
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        BUS16_SET(c, (db_ret << 0x10) + 0x32 + value2, (uint16_t)(value3 - value4));
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0x035C);
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        BUS16_SET(c, (db_ret << 0x10) + 0x32 + value5, (uint16_t)(value6 - value7));
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC2778B, SOM_RTS, "gen", derive_descriptor_ten_negative_y_sine_offset_from_phase, 0, 0, 1, 0, 0, 28, 12)
