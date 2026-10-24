#include "som_c.h"

/* C0AFA3 await_world_map_survey_nmi_acknowledgement   [class A, 11 bytes, 6 instructions]
 * Source: src/rom/await_world_map_survey_nmi_acknowledgement.s
 * Documented in docs/ui-native-world-map-picker-composition.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: XY.
 */
static void await_world_map_survey_nmi_acknowledgement(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x000E) = 1;
    for (;;) {
        if (!((RAM8(0x000E) & 1) != 0)) break;
    }
    r->x = x;
    r->y = y;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0AFA3, SOM_RTS, "gen", await_world_map_survey_nmi_acknowledgement, 0, L_X | L_Y, 1, 0, 0, 11, 6)
