#include "som_c.h"

/* C1EEAF set_event_actor_motion_after_charge_and_palette_cleanup   [class B, 59 bytes, 30 instructions]
 * Source: src/rom/set_event_actor_motion_after_charge_and_palette_cleanup.s
 * Documented in docs/event-vm-actor-movement.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void set_event_actor_motion_after_charge_and_palette_cleanup(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    uint8_t value;
    BUS8_OK(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, value);
    RAM8(0x0002) = value;
    uint16_t value2 = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value2 + 3));
    uint16_t value3 = RAM16(0x00D4);
    uint16_t value4 = RAM16(0x0005);
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    bool carry2;
    if ((value4 & 0xFF) == 0) {
        a2 = value4 & 0xFF;
        a_hi2 = 0;
        x2 = value3;
        carry2 = carry;
    } else {
        uint16_t value5 = RAM16(0x003A);
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        bool carry1;
        if ((value4 & 0x80) != 0) {
            a1 = value4 & 0xFF;
            a_hi1 = 0;
            x1 = value5;
            carry1 = carry;
        } else {
            a1 = (uint16_t)((uint16_t)((value4 & 0xFF) - 1) << 1) >> 8;
            a_hi1 = (uint8_t)((uint16_t)((value4 & 0xFF) - 1) << 1);
            x1 = ((uint8_t)((uint16_t)((value4 & 0xFF) - 1) << 1) << 8) | ((uint16_t)((uint16_t)((value4 & 0xFF) - 1) << 1) >> 8);
            carry1 = (uint16_t)((value4 & 0xFF) - 1) & 0x8000;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        carry2 = carry1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->y = (uint16_t)(value2 + 3);
    r->c = carry2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xEED4, 0xC1CA6C); /* clear_actor_movement_charge_and_palette_effects */
    uint16_t x_ret = r->x;
    RAM8(0xE01C + x_ret) = 0x40;
    RAM8(0xE011 + x_ret) = RAM8(0x0002);
    RAM8(0xE030 + x_ret) = 0xFF;
    RAM8(0xE042 + x_ret) = 1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EEAF, SOM_RTS, "hand", set_event_actor_motion_after_charge_and_palette_cleanup, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 59, 30)
