#include "som_c.h"

/* C2AA17 initialize_ui_transition_state_from_saved_map_flags   [class B, 69 bytes, 33 instructions]
 * Source: src/rom/initialize_ui_transition_state_from_saved_map_flags.s
 * Documented in docs/ui-native-ui-to-map-reset.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void initialize_ui_transition_state_from_saved_map_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x00D0, 0);
    RAM16_SET(0x00D2, 0);
    RAM16_SET(0x00D4, 0);
    RAM16_SET(0x00D6, 0);
    RAM16_SET(0x00D7, 0);
    RAM16_SET(0x00E0, 0);
    RAM16_SET(0x00E2, 0);
    RAM16_SET(0x00E4, 0);
    RAM16_SET(0x00E6, 0);
    RAM16_SET(0x00E8, 0);
    RAM16_SET(0x00EA, 0);
    RAM16_SET(0x00F1, 0);
    RAM16_SET(0x00FE, 0);
    RAM16_SET(0x00F6, 0);
    RAM16_SET(0x00F8, 0x44);
    RAM16_SET(0x00F2, 0x80);
    RAM16_SET(0x00FA, 0x0200);
    RAM16_SET(0x00FC, 0x0208);
    uint8_t value = RAM8(0xCF02);
    RAM8(0x00E3) = ((((value >> 2) | ((value & 1) << 7)) >> 1) | (((value >> 1) & 1) << 7)) & 0xC0;
    r->c = ((value >> 2) | ((value & 1) << 7)) & 0x01;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2AA17, SOM_RTL, "gen", initialize_ui_transition_state_from_saved_map_flags, 0, L_X | L_Y | L_C | L_V, 1, 1, 1, 69, 33)
