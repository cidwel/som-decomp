#include "som_c.h"

/* C2578A test_whether_either_linked_boss_child_has_state_word_81   [class A, 20 bytes, 10 instructions]
 * Source: src/rom/test_whether_either_linked_boss_child_has_state_word_81.s
 * Documented in docs/boss-native-target-animation.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void test_whether_either_linked_boss_child_has_state_word_81(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    uint16_t value2 = RAM16(0x0081 + value);
    if (value2 != 0) {
        r->a = value2;
        r->y = value;
        r->c = 1;
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(0x00B2 + x);
    uint16_t value4 = RAM16(0x0081 + value3);
    if (value4 != 0) {
        r->a = value4;
        r->y = value3;
        r->c = 1;
        RETURN_RTS(c);
    }
    r->a = value4;
    r->y = value3;
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2578A, SOM_RTS, "gen", test_whether_either_linked_boss_child_has_state_word_81, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 20, 10)
