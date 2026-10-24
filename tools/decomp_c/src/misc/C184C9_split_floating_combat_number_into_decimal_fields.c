#include "som_c.h"

static void read_floating_number_division_remainder(SomCtx *c);

/* C184C9 split_floating_combat_number_into_decimal_fields   [class C, 69 bytes, 30 instructions]
 * Source: src/rom/split_floating_combat_number_into_decimal_fields.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void split_floating_combat_number_into_decimal_fields(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    const uint16_t x = r->x;
    RAM16_SET(0x0002, 0xCB00);
    RAM16_SET(0x0004, 0xCB00);
    uint16_t value = RAM16(0x001E);
    BUS16_SET(c, 0x004204, value);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x84DC, read_floating_number_division_remainder, sp_in, 2); GUARD_JSR(c, sp_call, 0x84DC); }
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t a_all = r->a;
    BUS8_SET(c, dp_ret, (uint8_t)a_all);
    BUS8_SET(c, (uint16_t)(dp_ret + 1), 0);
    uint8_t value2 = BUS8(c, 0x004214);
    if (value2 == 0) {
        uint16_t value3 = BUS16_RDP(c, dp_ret);
        BUS16_SET(c, (uint16_t)(dp_ret + 2), value3);
        BUS16_SET(c, dp_ret, 0xCB00);
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (a_all >> 8 << 8) | value2;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x84E9, 0xC184F9); GUARD_JSR(c, sp_call, 0x84E9); } /* divide_floating_number_byte_by_ten */
    uint16_t a_all2 = r->a;
    BUS8_SET(c, (uint16_t)(dp_ret + 2), (uint8_t)a_all2);
    BUS8_SET(c, (uint16_t)(dp_ret + 3), 0);
    uint8_t value4 = BUS8(c, 0x004214);
    if (value4 == 0) {
        BUS16_SET(c, (db_ret << 0x10) + 0xE118 + x, 0xFFFC);
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (uint16_t)(dp_ret + 4), value4);
    BUS8_SET(c, (uint16_t)(dp_ret + 5), 0);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC184C9, SOM_RTS, "gen", split_floating_combat_number_into_decimal_fields, 0, L_X | L_Y | L_C | L_V, 5, 0, 0, 98, 30)

/* C18503 read_floating_number_division_remainder   [class A, 19 bytes, 12 instructions]
 * Source: src/rom/split_floating_combat_number_into_decimal_fields.s
 * Subroutine of split_floating_combat_number_into_decimal_fields, translated in place.
 * Entry: M=8 bit X=any DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void read_floating_number_division_remainder(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS8_SET(c, 0x004206, 0x0A);
    uint8_t value = BUS8(c, 0x004216);
    SET_A8(r, value);
    r->z = value == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
}
