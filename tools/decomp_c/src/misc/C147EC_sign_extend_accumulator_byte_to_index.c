#include "som_c.h"

/* C147EC sign_extend_accumulator_byte_to_index   [class A, 21 bytes, 12 instructions]
 * Source: src/rom/sign_extend_accumulator_byte_to_index.s
 * Documented in docs/runtime-stack-copy.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void sign_extend_accumulator_byte_to_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint8_t a1;
    uint8_t a_hi1;
    if ((((a_hi << 8) | a) & 0x80) == 0) {
        a1 = ((a_hi << 8) | a) & 0xFF;
        a_hi1 = 0;
    } else {
        a1 = (uint8_t)((a_hi << 8) | a | 0xFF00);
        a_hi1 = ((a_hi << 8) | a | 0xFF00) >> 8;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = (a_hi1 << 8) | a1;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC147EC, SOM_RTS, "gen", sign_extend_accumulator_byte_to_index, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 21, 12)
