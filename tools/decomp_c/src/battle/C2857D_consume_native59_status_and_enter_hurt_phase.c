#include "som_c.h"

/* C2857D consume_native59_status_and_enter_hurt_phase   [class A, 26 bytes, 11 instructions]
 * Source: src/rom/consume_native59_status_and_enter_hurt_phase.s
 * Documented in docs/boss-native59-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void consume_native59_status_and_enter_hurt_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x857F, 0xC2051C); /* consume_boss_byte35_request */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8582, 0xC20501); /* consume_boss_byte34_bit0_or_return_negative_status */
    uint16_t a_all2 = r->a;
    bool carry_ret2 = r->c;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    bool carry1;
    if (!carry_ret2) {
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x;
        carry1 = carry_ret2;
    } else {
        uint16_t value = RAM16(0x0287);
        RAM16_SET(OBJECT_PHASE + value, 3);
        uint16_t value2 = RAM16(0x02C7);
        RAM16_SET(0x00B2 + value, value2);
        RAM16_SET(OBJECT_AGE + value, 0);
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = value;
        carry1 = 1;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->c = carry1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2857D, SOM_RTS, "gen", consume_native59_status_and_enter_hurt_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 26, 11)
