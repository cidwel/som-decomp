#include "som_c.h"

/* C26183 select_boss_attack_row_25_or_26_by_variant   [class A, 23 bytes, 9 instructions]
 * Source: src/rom/select_boss_attack_row_25_or_26_by_variant.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void select_boss_attack_row_25_or_26_by_variant(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    if (RAM16(0x0042 + value) != 0) {
        r->a = 0x26;
        r->x = value;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6198, 0xC0006C); GUARD_JSL(c, sp_call, 0x6198); } /* boss_attack_row_public_jump */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->a = 0x25;
    r->x = value;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6190, 0xC0006C); GUARD_JSL(c, sp_call, 0x6190); } /* boss_attack_row_public_jump */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26183, SOM_RTS, "gen", select_boss_attack_row_25_or_26_by_variant, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 23, 9)
