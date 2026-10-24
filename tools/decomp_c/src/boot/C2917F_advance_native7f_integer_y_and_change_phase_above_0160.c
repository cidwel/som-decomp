#include "som_c.h"

/* C2917F advance_native7f_integer_y_and_change_phase_above_0160   [class A, 37 bytes, 15 instructions]
 * Source: src/rom/advance_native7f_integer_y_and_change_phase_above_0160.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void advance_native7f_integer_y_and_change_phase_above_0160(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(0x0032 + value);
    RAM16_SET(0x0032 + value, (uint16_t)(value2 + 2));
    uint16_t value3 = RAM16(0x0032 + value);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value3 <= 0x0160) {
        a1 = 0x60;
        a_hi1 = 1;
        zero1 = value3 == 0x0160;
        negative1 = (uint16_t)(0x0160 - value3) & 0x8000;
    } else {
        RAM16_SET(OBJECT_AGE + value, 0);
        RAM16_SET(OBJECT_PHASE + value, 0x0B);
        RAM16_SET(OBJECT_AGE + value, 0);
        a1 = 0x0B;
        a_hi1 = 0;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->c = value3 <= 0x0160;
    r->z = zero1;
    r->n = negative1;
    r->v = ((value2 ^ (uint16_t)(value2 + 2)) & ((uint16_t)(value2 + 2) ^ 2) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x91A1, 0xC2979F); GUARD_JSR(c, sp_call, 0x91A1); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2917F, SOM_RTS, "gen", advance_native7f_integer_y_and_change_phase_above_0160, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 37, 15)
