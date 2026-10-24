#include "som_c.h"

/* C25C61 install_linked_child_return_callback_and_timer   [class A, 31 bytes, 12 instructions]
 * Source: src/rom/install_linked_child_return_callback_and_timer.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void install_linked_child_return_callback_and_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0090 + x, 0x5C80);
    RAM16_SET(0x008E + x, 0x5C70);
    RAM16_SET(OBJECT_AGE + x, 0);
    uint16_t value = RAM16(OBJECT_AGE + x);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value < 0x10) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        zero1 = value == 0x10;
        negative1 = (uint16_t)(value - 0x10) & 0x8000;
    } else {
        RAM16_SET(0x008E + x, 0x5CC8);
        a1 = 0xC8;
        a_hi1 = 0x5C;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25C61, SOM_RTS, "gen", install_linked_child_return_callback_and_timer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 31, 12)
