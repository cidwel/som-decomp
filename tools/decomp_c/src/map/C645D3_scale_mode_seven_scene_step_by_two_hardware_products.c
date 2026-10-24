#include "som_c.h"

/* C645D3 scale_mode_seven_scene_step_by_two_hardware_products   [class B, 49 bytes, 27 instructions]
 * Source: src/rom/scale_mode_seven_scene_step_by_two_hardware_products.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: Y.
 */
static void scale_mode_seven_scene_step_by_two_hardware_products(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS8_SET(c, 0x004202, RAM8(0x0033));
    BUS8_SET(c, 0x004203, RAM8(0x0030));
    uint16_t value3 = BUS16(c, 0x004216);
    BUS8_SET(c, 0x004203, RAM8(0x0031));
    RAM16_SET(0x0030, value3);
    uint8_t value5 = BUS8(c, 0x004216);
    uint8_t value6 = RAM8(0x0031);
    RAM8(0x0031) = (uint8_t)(value5 + value6);
    uint8_t value7 = BUS8(c, 0x004217);
    RAM8(0x0032) = (uint8_t)(value7 + (value5 + value6 > 0xFF));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC645D3, SOM_RTS, "gen", scale_mode_seven_scene_step_by_two_hardware_products, 0, L_Y, 2, 1, 0, 49, 27)
