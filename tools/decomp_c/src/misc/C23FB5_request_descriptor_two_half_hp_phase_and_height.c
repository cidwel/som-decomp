#include "som_c.h"

/* C23FB5 request_descriptor_two_half_hp_phase_and_height   [class B, 36 bytes, 15 instructions]
 * Source: src/rom/request_descriptor_two_half_hp_phase_and_height.s
 * Documented in docs/boss-descriptor-two.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void request_descriptor_two_half_hp_phase_and_height(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0184 + x);
    uint16_t value2 = RAM16(0x0182 + x);
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    if (value >> 1 < value2) {
        a1 = (uint8_t)(value >> 1);
        a_hi1 = value >> 1 >> 8;
        carry1 = value >> 1 >= value2;
    } else {
        RAM16_SET(0x007E + x, 8);
        if (RAM16(0x0042 + x) != 0) {
            RAM16_SET(0x0066 + x, 0x20);
        } else {
            RAM16_SET(0x0066 + x, 0x20);
        }
        a1 = 0x20;
        a_hi1 = 0;
        carry1 = 1;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = carry1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23FB5, SOM_RTS, "gen", request_descriptor_two_half_hp_phase_and_height, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 36, 15)
