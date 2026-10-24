#include "som_c.h"

/* C2712D choose_descriptor_seven_variant_zero_action   [class B, 69 bytes, 31 instructions]
 * Source: src/rom/choose_descriptor_seven_variant_zero_action.s
 * Documented in docs/boss-descriptor-seven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_seven_variant_zero_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x0032 + value);
    uint16_t value3 = RAM16(0x0004 + y);
    if ((uint16_t)(value2 - value3) & 0x8000) {
        if ((RAM16(0x01B0 + value) & 0xFF) != 0) {
            if (RAM16(0x002B + value) >= RAM16(0x0002 + y)) {
                uint16_t value7 = BUS16(c, 0xDCE4FF);
                r->a = value7;
                r->x = value;
                r->c = 0;
                r->z = value7 == 0;
                r->n = value7 & 0x8000;
                r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
                RETURN_RTS(c);
            }
            uint16_t value8 = BUS16(c, 0xDCE4FD);
            r->a = value8;
            r->x = value;
            r->c = 0;
            r->z = value8 == 0;
            r->n = value8 & 0x8000;
            r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        r->a = 0xEB99;
        r->x = value;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value2 - value3) >= 0x20) {
        if ((RAM16(0x01B0 + value) & 0xFF) != 0) {
            if (RAM16(0x002B + value) >= RAM16(0x0002 + y)) {
                uint16_t value12 = BUS16(c, 0xDCE4FF);
                r->a = value12;
                r->x = value;
                r->c = 0;
                r->z = value12 == 0;
                r->n = value12 & 0x8000;
                r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
                RETURN_RTS(c);
            }
            uint16_t value13 = BUS16(c, 0xDCE4FD);
            r->a = value13;
            r->x = value;
            r->c = 0;
            r->z = value13 == 0;
            r->n = value13 & 0x8000;
            r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        r->a = 0xEB99;
        r->x = value;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if (RAM16(0x002B + value) >= RAM16(0x0002 + y)) {
        uint16_t value16 = BUS16(c, 0xDCE4FB);
        r->a = value16;
        r->x = value;
        r->c = 0;
        r->z = value16 == 0;
        r->n = value16 & 0x8000;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value17 = BUS16(c, 0xDCE4F9);
    r->a = value17;
    r->x = value;
    r->c = 0;
    r->z = value17 == 0;
    r->n = value17 & 0x8000;
    r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2712D, SOM_RTS, "gen", choose_descriptor_seven_variant_zero_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 69, 31)
