#include "som_c.h"

/* C28BF7 update_descriptor_eleven_facing_phase_or_return_transition_abort   [class B, 41 bytes, 21 instructions]
 * Source: src/rom/update_descriptor_eleven_facing_phase_or_return_transition_abort.s
 * Documented in docs/boss-descriptor-eleven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XC.
 */
static void update_descriptor_eleven_facing_phase_or_return_transition_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    uint16_t value2 = RAM16(0x002B + x);
    uint16_t value3 = RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value2 - value3) & 0x8000)) {
        a1 = 1;
        a_hi1 = 0;
    } else {
        uint16_t value4 = RAM16(0x02C5);
        a1 = (uint8_t)value4;
        a_hi1 = value4 >> 8;
    }
    if (((a_hi1 << 8) | a1) == RAM16(0x007E + x)) {
        r->c = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x007E + x, (a_hi1 << 8) | a1);
    r->c = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28BF7, SOM_RTS, "gen", update_descriptor_eleven_facing_phase_or_return_transition_abort, 0, L_X | L_C, 1, 0, 0, 41, 21)
