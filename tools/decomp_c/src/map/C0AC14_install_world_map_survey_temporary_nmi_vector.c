#include "som_c.h"

/* C0AC14 install_world_map_survey_temporary_nmi_vector   [class A, 14 bytes, 7 instructions]
 * Source: src/rom/install_world_map_survey_temporary_nmi_vector.s
 * Documented in docs/ui-native-world-map-picker-composition.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYV.
 */
static void install_world_map_survey_temporary_nmi_vector(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = 3;
    for (;;) {
        RAM8(0x0100 + x1) = RAM8(0xAC22 + x1);
        x1 = (uint8_t)(x1 - 1);
        if (!(!(x1 & 0x80))) break;
    }
    r->x = x1;
    r->y = (uint8_t)y;
    r->v = overflow;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0AC14, SOM_RTS, "gen", install_world_map_survey_temporary_nmi_vector, 0, L_X | L_Y | L_V, 1, 1, 0, 14, 7)
