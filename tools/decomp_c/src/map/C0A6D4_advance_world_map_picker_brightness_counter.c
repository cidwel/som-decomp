#include "som_c.h"

/* C0A6D4 advance_world_map_picker_brightness_counter   [class D, 33 bytes, 20 instructions]
 * Source: src/rom/advance_world_map_picker_brightness_counter.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void advance_world_map_picker_brightness_counter(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    if ((uint8_t)((a_hi << 8) | a) & 0x80) {
        RAM8(0x000C) = (uint8_t)(a + 1);
        if ((uint8_t)(a + 1) != 0) {
            uint8_t a1;
            if ((uint8_t)((a_hi << 8) | a) < 0x80) {
                a1 = (uint8_t)((a_hi << 8) | a);
            } else {
                a1 = (uint8_t)((a_hi << 8) | a) ^ 0xFF;
            }
            bool carry1;
            if (a1 >= 0x40) {
                carry1 = a1 >= 0x40;
            } else {
                BUS8_SET(c, 0x002100, a1 >> 2);
                carry1 = a1 >> 1 & 0x01;
            }
            r->c = carry1;
            RETURN_RTS(c);
        }
        RETURN_RTS(c);
    }
    RAM8(0x000C) = (uint8_t)(a + 1) & 0x3F;
    uint8_t a2;
    if ((uint8_t)((a_hi << 8) | a) < 0x80) {
        a2 = (uint8_t)((a_hi << 8) | a);
    } else {
        a2 = (uint8_t)((a_hi << 8) | a) ^ 0xFF;
    }
    bool carry2;
    if (a2 >= 0x40) {
        carry2 = a2 >= 0x40;
    } else {
        BUS8_SET(c, 0x002100, a2 >> 2);
        carry2 = a2 >> 1 & 0x01;
    }
    r->c = carry2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0A6D4, SOM_RTS, "gen", advance_world_map_picker_brightness_counter, 0, L_C | L_V, 1, 1, 1, 33, 20)
