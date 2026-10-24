#include "som_c.h"

/* C1D285 record_contact_presentation_byte_and_volume   [class A, 49 bytes, 24 instructions]
 * Source: src/rom/record_contact_presentation_byte_and_volume.s
 * Documented in docs/actor-party-map-contacts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void record_contact_presentation_byte_and_volume(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x0095);
    if (value & 0x80) {
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    RAM8(0x0095) = a;
    uint8_t value2 = RAM8(0xE020 + x);
    RAM8(0x0118) = value2 & 0xF0;
    uint8_t value3 = RAM8(0x0118);
    RAM8(0x0119) = ((value2 & 0xF0) >> 4) | value3;
    SET_A8(r, ((value2 & 0xF0) >> 4) | value3);
    r->c = (value2 & 0xF0) >> 3 & 0x01;
    r->v = value & 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1D285, SOM_RTS, "gen", record_contact_presentation_byte_and_volume, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 677, 24)
