#include "som_c.h"

/* C1F010 event_assign_selected_actor_secondary_byte_field   [class B, 59 bytes, 30 instructions]
 * Source: src/rom/event_assign_selected_actor_secondary_byte_field.s
 * Documented in docs/event-vm-actor-fields-and-bindings.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_assign_selected_actor_secondary_byte_field(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value;
    BUS16_OK(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, value);
    RAM16_SET(0x0000, value);
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 4));
    uint16_t value3 = RAM16(0x00D4);
    uint16_t value4 = RAM16(0x0005);
    uint8_t a_hi2;
    uint16_t x2;
    if ((value4 & 0xFF) == 0) {
        a_hi2 = 0;
        x2 = value3;
    } else {
        uint16_t value5 = RAM16(0x003A);
        uint8_t a_hi1;
        uint16_t x1;
        if ((value4 & 0x80) != 0) {
            a_hi1 = 0;
            x1 = value5;
        } else {
            a_hi1 = (uint8_t)((uint16_t)((value4 & 0xFF) - 1) << 1);
            x1 = ((uint8_t)((uint16_t)((value4 & 0xFF) - 1) << 1) << 8) | ((uint16_t)((uint16_t)((value4 & 0xFF) - 1) << 1) >> 8);
        }
        a_hi2 = a_hi1;
        x2 = x1;
    }
    RAM16_SET(0x0002, x2);
    uint16_t value6 = RAM16(0x0000);
    uint16_t value7 = RAM16(0x0002);
    uint8_t value8 = RAM8(0x0001);
    RAM8(0xE000 + ((value6 & 0xFF) + 0x0100 | value7)) = value8;
    r->a = (((value6 & 0xFF) + 0x0100 | value7) >> 8 << 8) | value8;
    r->x = (value6 & 0xFF) + 0x0100 | value7;
    r->y = 2;
    r->c = (value6 & 0xFF) + 0x0100 > 0xFFFF;
    r->z = value8 == 0;
    r->n = value8 & 0x80;
    r->v = (((value6 & 0xFF) ^ (value6 & 0xFF) + 0x0100) & ((value6 & 0xFF) + 0x0100 ^ 0x0100) & 0x8000) != 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F010, SOM_RTS, "hand", event_assign_selected_actor_secondary_byte_field, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 59, 30)
