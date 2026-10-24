#include "som_c.h"

/* C25E9D consume_linked_child_request_and_select_native_definition   [class A, 38 bytes, 17 instructions]
 * Source: src/rom/consume_linked_child_request_and_select_native_definition.s
 * Documented in docs/boss-native-linked-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void consume_linked_child_request_and_select_native_definition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x0081 + value);
    if (value2 != 0) {
        RAM16_SET(0x00C2 + x, 0);
        RAM16_SET(0x0090 + x, 0);
        RAM16_SET(0x0081 + value, 0);
        uint16_t value3 = BUS16(c, 0xC259E9 + (uint16_t)(value2 << 1));
        RAM16_SET(0x008E + value, value3);
        RAM16_SET(OBJECT_PHASE + value, value3);
        r->a = value3;
        r->x = (uint16_t)(value2 << 1);
        JSR(c, 0x5EC0, 0xC25E8C); /* clear_linked_child_strip_piece_attribute_bit_40 */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->y = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25E9D, SOM_RTS, "gen", consume_linked_child_request_and_select_native_definition, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 38, 17)
