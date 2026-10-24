#include "som_c.h"

/* C248F1 complete_auxiliary_recoil_or_accelerate   [class B, 59 bytes, 25 instructions]
 * Source: src/rom/complete_auxiliary_recoil_or_accelerate.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void complete_auxiliary_recoil_or_accelerate(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(0xF811 + y);
    if (value2 < 0xC200) {
        r->a = value2;
        r->x = value;
        r->c = value2 >= 0xC200;
        r->z = value2 == 0xC200;
        r->n = (uint16_t)(value2 - 0xC200) & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4929, 0xC2492C); GUARD_JSR(c, sp_call, 0x4929); } /* accelerate_native54_auxiliary_recoil */
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(OBJECT_PHASE + value, 7);
    RAM16_SET(0x0076 + value, 7);
    RAM16_SET(OBJECT_AGE + value, 0);
    RAM8(0xF812 + y) = 0xC1;
    RAM8(0xF80E + y) = 0xDE;
    RAM8(0xF813 + y) = 0x40;
    uint16_t value3 = RAM16(0x0190 + value);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (!(value3 & 0x8000)) {
        a1 = (uint8_t)value3;
        a_hi1 = value3 >> 8;
        zero1 = value3 == 0;
        negative1 = value3 & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value, 0x0E);
        a1 = 0x0E;
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
SOM_REGISTER(0xC248F1, SOM_RTS, "gen", complete_auxiliary_recoil_or_accelerate, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 59, 25)
