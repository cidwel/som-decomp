#include "som_c.h"

/* C253BD refresh_descriptor_fourteen_child_variant_parent_mode_animation   [class B, 52 bytes, 22 instructions]
 * Source: src/rom/refresh_descriptor_fourteen_child_variant_parent_mode_animation.s
 * Documented in docs/boss-descriptor-fourteen-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void refresh_descriptor_fourteen_child_variant_parent_mode_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    if (RAM16(0x00B2 + x) != 0) {
        uint16_t value3 = BUS16(c, 0xDCE21C + (uint16_t)(RAM16(0x007A + y) << 1));
        uint16_t value4 = RAM16(0x0287);
        uint16_t value5 = RAM16(0x00B4 + value4);
        if (value3 != value5) {
            RAM16_SET(0x00B4 + value4, value3);
            r->a = value3;
            r->x = value4;
            r->c = value3 >= value5;
            JSR(c, 0x53EF, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        }
    } else {
        uint16_t value7 = BUS16(c, 0xDCE1EA + (uint16_t)(RAM16(0x007A + y) << 1));
        uint16_t value8 = RAM16(0x0287);
        uint16_t value9 = RAM16(0x00B4 + value8);
        if (value7 != value9) {
            RAM16_SET(0x00B4 + value8, value7);
            r->a = value7;
            r->x = value8;
            r->c = value7 >= value9;
            JSR(c, 0x53D7, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        }
    }
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC253BD, SOM_RTS, "gen", refresh_descriptor_fourteen_child_variant_parent_mode_animation, 0, 0, 1, 0, 0, 52, 22)
