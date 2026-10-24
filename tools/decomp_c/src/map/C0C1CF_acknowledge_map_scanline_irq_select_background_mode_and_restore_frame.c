#include "som_c.h"

/* C0C1CF acknowledge_map_scanline_irq_select_background_mode_and_restore_frame   [class D, 24 bytes, 14 instructions]
 * Source: src/rom/acknowledge_map_scanline_irq_select_background_mode_and_restore_frame.s
 * Documented in docs/map-scanline-irq.md
 * Entry: M=any X=any DB=any D=any.  Callers read: nothing.
 */
static void acknowledge_map_scanline_irq_select_background_mode_and_restore_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    uint8_t value = BUS8(c, 0x004211);
    BUS8_SET(c, 0x002105, 9);
    BUS8_SET(c, 0x00212C, 0x14);
    RETURN_RTI(c);
}
SOM_REGISTER(0xC0C1CF, SOM_RTI, "gen", acknowledge_map_scanline_irq_select_background_mode_and_restore_frame, 0, 0, 3, -1, -1, 24, 14)
