#include "som_c.h"

/* C08566 compute_scene_attribute_scroll_weights_with_multiplier   [class B, 50 bytes, 27 instructions]
 * Source: src/rom/compute_scene_attribute_scroll_weights_with_multiplier.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void compute_scene_attribute_scroll_weights_with_multiplier(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x00F6);
    RAM16_SET(0x00F6, value & 0x03FC);
    BUS8_SET(c, 0x004202, ((value & 0x03FC) ^ 0x03FF) >> 2);
    BUS8_SET(c, 0x004203, 0xE0);
    uint8_t value2 = BUS8(c, 0x004217);
    RAM8(0x00BC) = value2;
    BUS8_SET(c, 0x004203, 0xA0);
    uint8_t value3 = BUS8(c, 0x004217);
    RAM8(0x00BD) = value3;
    r->a = (r->a & 0x00FF) | (0 << 8);
    r->c = ((value & 0x03FC) ^ 0x03FF) >> 1 & 0x01;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08566, SOM_RTS, "gen", compute_scene_attribute_scroll_weights_with_multiplier, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 50, 27)
