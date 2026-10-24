#include "som_c.h"

/* C08A4B service_ui_scene_scanline_irq_and_restore_interrupted_context   [class D, 46 bytes, 25 instructions]
 * Source: src/rom/service_ui_scene_scanline_irq_and_restore_interrupted_context.s
 * Documented in docs/ui-native-scene-interrupts.md
 * Entry: M=any X=any DB=$00 D=any.  Callers read: ABXYCZNV.
 */
static void service_ui_scene_scanline_irq_and_restore_interrupted_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, -1)) return;
    uint8_t value = BUS8(c, 0x004211);
    if (!(RAM8(0x00F2) & 0x80)) {
        uint8_t value3 = RAM8(0x003A);
        uint8_t value4 = RAM8(0x003B);
        BUS8_SET(c, 0x002105, 7);
        BUS8_SET(c, 0x00210D, value3);
        BUS8_SET(c, 0x00210D, value4);
    }
    RETURN_RTI(c);
}
SOM_REGISTER(0xC08A4B, SOM_RTI, "gen", service_ui_scene_scanline_irq_and_restore_interrupted_context, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, -1, -1, 46, 25)
