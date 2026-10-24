#include "som_c.h"

/* C2602D terminate_descriptor_five_parent_after_final_tick24   [class A, 14 bytes, 8 instructions]
 * Source: src/rom/terminate_descriptor_five_parent_after_final_tick24.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void terminate_descriptor_five_parent_after_final_tick24(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x96 + value);
    if (value2 < 0x18) {
        r->a = value2;
        r->x = value;
        r->c = 0;
        r->z = value2 == 0x18;
        r->n = (uint16_t)(value2 - 0x18) & 0x8000;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->x = value;
    r->c = 1;
    r->z = value2 == 0x18;
    r->n = (uint16_t)(value2 - 0x18) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2602D, SOM_RTS, "gen", terminate_descriptor_five_parent_after_final_tick24, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 8)
