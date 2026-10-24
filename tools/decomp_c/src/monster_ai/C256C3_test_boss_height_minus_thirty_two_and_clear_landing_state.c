#include "som_c.h"

/* C256C3 test_boss_height_minus_thirty_two_and_clear_landing_state   [class B, 24 bytes, 12 instructions]
 * Source: src/rom/test_boss_height_minus_thirty_two_and_clear_landing_state.s
 * Documented in docs/boss-native-rebound-landing.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void test_boss_height_minus_thirty_two_and_clear_landing_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0066 + x);
    if ((uint16_t)(value - 0x20) == 0) {
        RAM16_SET(0x0064 + x, 0);
        RAM16_SET(0x0066 + x, 0);
        RAM16_SET(0x0090 + x, 0);
        r->a = (uint16_t)(value - 0x20);
        r->c = 1;
        r->z = (uint16_t)(value - 0x20) == 0;
        r->n = (uint16_t)(value - 0x20) & 0x8000;
        r->v = ((value ^ 0x20) & (value ^ (uint16_t)(value - 0x20)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if (!((uint16_t)(value - 0x20) & 0x8000)) {
        r->a = (uint16_t)(value - 0x20);
        r->c = 0;
        r->z = (uint16_t)(value - 0x20) == 0;
        r->n = (uint16_t)(value - 0x20) & 0x8000;
        r->v = ((value ^ 0x20) & (value ^ (uint16_t)(value - 0x20)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0064 + x, 0);
    RAM16_SET(0x0066 + x, 0);
    RAM16_SET(0x0090 + x, 0);
    r->a = (uint16_t)(value - 0x20);
    r->c = 1;
    r->z = (uint16_t)(value - 0x20) == 0;
    r->n = (uint16_t)(value - 0x20) & 0x8000;
    r->v = ((value ^ 0x20) & (value ^ (uint16_t)(value - 0x20)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC256C3, SOM_RTS, "gen", test_boss_height_minus_thirty_two_and_clear_landing_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 24, 12)
