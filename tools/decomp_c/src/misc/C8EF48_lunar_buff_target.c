#include "som_c.h"

/* C8EF48 lunar_buff_target   [class A, 22 bytes, 9 instructions]
 * Source: src/rom/lunar_buff_target.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void lunar_buff_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x85));
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0x9C));
    BUS8_SET(c, (db << 0x10) + 0xE1B7 + value, value2);
    BUS8_SET(c, (db << 0x10) + 0xE1BA + value, value2);
    BUS8_SET(c, (db << 0x10) + 0xE1BB + value, value2);
    BUS8_SET(c, (db << 0x10) + 0xE1BC + value, value2);
    BUS8_SET(c, (db << 0x10) + 0xE1B0 + value, 0x55);
    SET_A8(r, 0x55);
    r->x = value;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EF48, SOM_RTS, "gen", lunar_buff_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 22, 9)
