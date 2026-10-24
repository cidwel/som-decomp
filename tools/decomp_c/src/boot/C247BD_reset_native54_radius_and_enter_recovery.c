#include "som_c.h"

/* C247BD reset_native54_radius_and_enter_recovery   [class A, 21 bytes, 9 instructions]
 * Source: src/rom/reset_native54_radius_and_enter_recovery.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void reset_native54_radius_and_enter_recovery(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x9E + value);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value2 != 0) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        zero1 = value2 == 0;
        negative1 = value2 & 0x8000;
    } else {
        BUS16_SET(c, (db << 0x10) + 0x94 + value, 0x0B);
        BUS16_SET(c, (db << 0x10) + 0x1E + value, 0);
        BUS16_SET(c, (db << 0x10) + 0x96 + value, 0);
        a1 = 0x0B;
        a_hi1 = 0;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC247BD, SOM_RTS, "gen", reset_native54_radius_and_enter_recovery, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 21, 9)
