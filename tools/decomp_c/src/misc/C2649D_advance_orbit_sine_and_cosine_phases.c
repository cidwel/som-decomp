#include "som_c.h"

/* C2649D advance_orbit_sine_and_cosine_phases   [class A, 33 bytes, 14 instructions]
 * Source: src/rom/advance_orbit_sine_and_cosine_phases.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void advance_orbit_sine_and_cosine_phases(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x00B0 + x);
    RAM16_SET(0x00B0 + x, (uint16_t)(value + 0x2A));
    r->a = (uint16_t)(value + 0x2A);
    r->c = value + 0x2A > 0xFFFF;
    r->z = (uint16_t)(value + 0x2A) == 0;
    r->n = (uint16_t)(value + 0x2A) & 0x8000;
    r->v = ((value ^ (uint16_t)(value + 0x2A)) & ((uint16_t)(value + 0x2A) ^ 0x2A) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x64A9, 0xC22A60); GUARD_JSR(c, sp_call, 0x64A9); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    BUS16_SET(c, (uint16_t)(dp_ret + 0x95), a_all);
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 0xB2 + value2);
        BUS16_SET(c, (db_ret << 0x10) + 0xB2 + value2, (uint16_t)(value3 + 0x20));
        r->a = (uint16_t)(value3 + 0x20);
        r->x = value2;
        r->y = (uint8_t)y;
        r->c = value3 + 0x20 > 0xFFFF;
        r->z = (uint16_t)(value3 + 0x20) == 0;
        r->n = (uint16_t)(value3 + 0x20) & 0x8000;
        r->v = ((value3 ^ (uint16_t)(value3 + 0x20)) & ((uint16_t)(value3 + 0x20) ^ 0x20) & 0x8000) != 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x64BA, 0xC22A59); GUARD_JSR(c, sp_call, 0x64BA); } /* derive_cosine_by_adding_quarter_turn */
        uint16_t a_all2 = r->a;
        BUS16_SET(c, (uint16_t)(dp_ret + 0x97), a_all2);
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0xB2 + value4);
        BUS16_SET(c, (db_ret << 0x10) + 0xB2 + value4, (uint16_t)(value5 + 0x20));
        r->a = (uint16_t)(value5 + 0x20);
        r->x = value4;
        r->c = value5 + 0x20 > 0xFFFF;
        r->z = (uint16_t)(value5 + 0x20) == 0;
        r->n = (uint16_t)(value5 + 0x20) & 0x8000;
        r->v = ((value5 ^ (uint16_t)(value5 + 0x20)) & ((uint16_t)(value5 + 0x20) ^ 0x20) & 0x8000) != 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x64BA, 0xC22A59); GUARD_JSR(c, sp_call, 0x64BA); } /* derive_cosine_by_adding_quarter_turn */
        uint16_t a_all3 = r->a;
        BUS16_SET(c, (uint16_t)(dp_ret + 0x97), a_all3);
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC2649D, SOM_RTS, "gen", advance_orbit_sine_and_cosine_phases, 0, L_B | L_Y | L_C | L_V, 1, 0, 0, 33, 14)
