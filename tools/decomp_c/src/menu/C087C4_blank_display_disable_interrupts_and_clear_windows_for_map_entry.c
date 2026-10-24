#include "som_c.h"

/* C087C4 blank_display_disable_interrupts_and_clear_windows_for_map_entry   [class D, 28 bytes, 11 instructions]
 * Source: src/rom/blank_display_disable_interrupts_and_clear_windows_for_map_entry.s
 * Documented in docs/ui-native-map-entry-requests.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void blank_display_disable_interrupts_and_clear_windows_for_map_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    BUS8_SET(c, 0x002100, 0x8F);
    BUS8_SET(c, 0x004200, 1);
    BUS8_SET(c, 0x00420C, 0);
    BUS8_SET(c, 0x002123, 0);
    BUS8_SET(c, 0x002124, 0);
    BUS8_SET(c, 0x002125, 0);
    BUS8_SET(c, 0x002125, 0);
    SET_A8(r, 1);
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->z = 0;
    r->n = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC087C4, SOM_RTS, "gen", blank_display_disable_interrupts_and_clear_windows_for_map_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 28, 11)
