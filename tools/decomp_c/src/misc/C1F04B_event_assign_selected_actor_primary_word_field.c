#include "som_c.h"

/* C1F04B event_assign_selected_actor_primary_word_field   [class A, 36 bytes, 19 instructions]
 * Source: src/rom/event_assign_selected_actor_primary_word_field.s
 * Documented in docs/event-vm-actor-fields-and-bindings.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_assign_selected_actor_primary_word_field(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value;
    BUS16_OK(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, value);
    RAM16_SET(0x0000, value);
    uint16_t value2 = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value2 + 4));
    uint16_t value3 = RAM16(0x00D4);
    uint16_t value4 = RAM16(0x0005);
    uint8_t a_hi1;
    uint16_t x1;
    bool carry1;
    if ((value4 & 0xFF) == 0) {
        a_hi1 = 0;
        x1 = value3;
        carry1 = value2 + 4 > 0xFFFF;
    } else {
        a_hi1 = (uint8_t)((uint16_t)((value4 & 0xFF) - 1) << 1);
        x1 = ((uint8_t)((uint16_t)((value4 & 0xFF) - 1) << 1) << 8) | ((uint16_t)((uint16_t)((value4 & 0xFF) - 1) << 1) >> 8);
        carry1 = (uint16_t)((value4 & 0xFF) - 1) & 0x8000;
    }
    uint16_t value5 = RAM16(0x0000);
    RAM16_SET(0xE040 + x1, value5);
    r->a = value5;
    r->x = x1;
    r->y = 2;
    r->c = carry1;
    r->z = value5 == 0;
    r->n = value5 & 0x8000;
    r->v = ((value2 ^ (uint16_t)(value2 + 4)) & ((uint16_t)(value2 + 4) ^ 4) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F04B, SOM_RTS, "hand", event_assign_selected_actor_primary_word_field, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 36, 19)
