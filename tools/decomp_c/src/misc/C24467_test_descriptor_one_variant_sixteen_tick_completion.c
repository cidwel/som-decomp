#include "som_c.h"

/* C24467 test_descriptor_one_variant_sixteen_tick_completion   [class B, 16 bytes, 8 instructions]
 * Source: src/rom/test_descriptor_one_variant_sixteen_tick_completion.s
 * Documented in docs/boss-descriptor-one-palette.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void test_descriptor_one_variant_sixteen_tick_completion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0042 + x);
    if (value == 0) {
        r->a = value;
        r->c = 1;
        r->z = value == 0;
        r->n = value & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value2 = RAM16(OBJECT_AGE + x);
    if (value2 >= 0x10) {
        r->a = value2;
        r->c = 1;
        r->z = value2 == 0x10;
        r->n = (uint16_t)(value2 - 0x10) & 0x8000;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->c = value2 >= 0x10;
    r->z = value2 == 0x10;
    r->n = (uint16_t)(value2 - 0x10) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24467, SOM_RTS, "gen", test_descriptor_one_variant_sixteen_tick_completion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 16, 8)
