#include "som_c.h"

/* C24330 request_descriptor_one_phase_eight_at_half_hp   [class A, 17 bytes, 8 instructions]
 * Source: src/rom/request_descriptor_one_phase_eight_at_half_hp.s
 * Documented in docs/boss-descriptor-one.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYC.
 */
static void request_descriptor_one_phase_eight_at_half_hp(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0184 + x);
    uint16_t value2 = RAM16(0x0182 + x);
    uint8_t a_hi1;
    bool carry1;
    if (value >> 1 < value2) {
        a_hi1 = value >> 1 >> 8;
        carry1 = value >> 1 >= value2;
    } else {
        RAM16_SET(0x007E + x, 8);
        a_hi1 = 0;
        carry1 = 1;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->c = carry1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24330, SOM_RTS, "gen", request_descriptor_one_phase_eight_at_half_hp, 0, L_B | L_X | L_Y | L_C, 1, 0, 0, 17, 8)
