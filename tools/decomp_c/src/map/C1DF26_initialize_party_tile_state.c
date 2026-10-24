#include "som_c.h"

static void initialize_actor_tile_state(SomCtx *c);
static void initialize_actor_tile_state_v2(SomCtx *c);

/* C1DF26 initialize_party_tile_state   [class B, 112 bytes, 54 instructions]
 * Source: src/rom/initialize_party_tile_state.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void initialize_party_tile_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    r->x = 0;
    r->z = 1;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDF2D, initialize_actor_tile_state, sp_in, 2); GUARD_JSR(c, sp_call, 0xDF2D); }
    r->x = 0x0200;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDF33, initialize_actor_tile_state_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xDF33); }
    r->x = 0x0400;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    initialize_actor_tile_state_v2(c); return;
}
SOM_REGISTER(0xC1DF26, SOM_RTS, "gen", initialize_party_tile_state, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 9, 1, 0, 112, 54)

/* C1DF37 initialize_actor_tile_state   [class A, 95 bytes, 48 instructions]
 * Source: src/rom/initialize_party_tile_state.s
 * Subroutine of initialize_party_tile_state, translated in place.
 * Entry: M=any X=any DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_actor_tile_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0000, RAM16(0xE002 + x) >> 4);
    uint16_t value2 = RAM16(0xE004 + x);
    uint16_t value3 = RAM16(0x0000);
    RAM8(0x0006) = 0x7F;
    RAM8(0x0009) = 0x7F;
    uint8_t value4 = RAM8(0xE00B + x);
    uint8_t a_hi1;
    if (!(value4 & 0x80)) {
        RAM16_SET(0x0004, 0);
        RAM16_SET(0x0007, 0xB800);
        a_hi1 = 0xB8;
    } else {
        RAM16_SET(0x0004, 0x4000);
        RAM16_SET(0x0007, 0xBC00);
        a_hi1 = 0xBC;
    }
    uint16_t value5 = BUS16_RDL(c, (RAM8(0x0006) << 0x10) + RAM16(0x0004) + (((value2 & 0x0FF0) << 1 << 1 << 1) | value3), RAM8(0x0006));
    RAM16_SET(0x0000, value5);
    uint16_t value6 = BUS16_RDL(c, (RAM8(0x0009) << 0x10) + RAM16(0x0007) + ((value5 & 0xFF) << 1 << 1), RAM8(0x0009));
    uint8_t value7 = RAM8(0xE00B + x);
    RAM8(0xE00B + x) = ((uint8_t)value6 & 3) | value7;
    RAM8(0xE08E + x) = (value6 >> 8) & 7;
    uint8_t value8 = RAM8(0x0000);
    RAM8(0xE04C + x) = value8;
    r->a = ((((uint8_t)value6 & 3) | value7) << 8) | value8;
    r->y = (value5 & 0xFF) << 1 << 1;
    r->c = (value5 & 0xFF) << 1 & 0x8000;
    r->z = value8 == 0;
    r->n = value8 & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}

/* C1DF37 initialize_actor_tile_state_v2   [class A, 95 bytes, 48 instructions]
 * Source: src/rom/initialize_party_tile_state.s
 * Subroutine of initialize_party_tile_state, translated in place.
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void initialize_actor_tile_state_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0xE002 + x);
    BUS16_SET(c, dp, value >> 4);
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0xE004 + x);
    uint16_t value3 = BUS16_RDP(c, dp);
    BUS8_SET(c, (uint16_t)(dp + 6), 0x7F);
    BUS8_SET(c, (uint16_t)(dp + 9), 0x7F);
    uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0xE00B + x);
    uint8_t a_hi1;
    if (!(value4 & 0x80)) {
        BUS16_SET(c, (uint16_t)(dp + 4), 0);
        BUS16_SET(c, (uint16_t)(dp + 7), 0xB800);
        a_hi1 = 0xB8;
    } else {
        BUS16_SET(c, (uint16_t)(dp + 4), 0x4000);
        BUS16_SET(c, (uint16_t)(dp + 7), 0xBC00);
        a_hi1 = 0xBC;
    }
    uint16_t value5 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 6)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 4)) + (((value2 & 0x0FF0) << 1 << 1 << 1) | value3), BUS8_RDP(c, (uint16_t)(dp + 6)));
    BUS16_SET(c, dp, value5);
    uint16_t value6 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 9)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 7)) + ((value5 & 0xFF) << 1 << 1), BUS8_RDP(c, (uint16_t)(dp + 9)));
    uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0xE00B + x);
    BUS8_SET(c, (db << 0x10) + 0xE00B + x, ((uint8_t)value6 & 3) | value7);
    BUS8_SET(c, (db << 0x10) + 0xE08E + x, (value6 >> 8) & 7);
    uint8_t value8 = BUS8_RDP(c, dp);
    BUS8_SET(c, (db << 0x10) + 0xE04C + x, value8);
    r->a = ((((uint8_t)value6 & 3) | value7) << 8) | value8;
    r->y = (value5 & 0xFF) << 1 << 1;
    r->c = (value5 & 0xFF) << 1 & 0x8000;
    r->z = value8 == 0;
    r->n = value8 & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
