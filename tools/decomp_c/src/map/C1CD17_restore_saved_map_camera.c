#include "som_c.h"

/* C1CD17 restore_saved_map_camera   [class B, 55 bytes, 26 instructions]
 * Source: src/rom/restore_saved_map_camera.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void restore_saved_map_camera(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0xCD00);
    RAM16_SET(0x00A8, value);
    RAM16_SET(0x0088, value & 0xFFF0);
    uint16_t value2 = RAM16(0xCD02);
    RAM16_SET(0x00AA, value2);
    RAM16_SET(0x008A, value2 & 0xFFF0);
    uint16_t value3 = RAM16(0xCD04);
    RAM16_SET(0x00AC, value3);
    RAM16_SET(0x008C, value3 & 0xFFF0);
    uint16_t value4 = RAM16(0xCD06);
    RAM16_SET(0x00AE, value4);
    RAM16_SET(0x008E, value4 & 0xFFF0);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1CD17, SOM_RTL, "gen", restore_saved_map_camera, 0, L_C | L_V, 2, 0, 1, 55, 26)
