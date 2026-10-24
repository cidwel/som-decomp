#include "som_c.h"

/* C2102B align_boss_camera_scroll_and_screen_position   [class B, 129 bytes, 57 instructions]
 * Source: src/rom/align_boss_camera_scroll_and_screen_position.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: YV.
 */
static void align_boss_camera_scroll_and_screen_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0FB0, RAM16(0x002B + x));
    RAM16_SET(0x0FB2, (uint16_t)((uint16_t)(((RAM16(0x0066 + x) >> 1) ^ RAM16(0x02C7)) + 1) + RAM16(0x0032 + x)));
    uint16_t value5 = RAM16(0x028D);
    uint16_t value6 = RAM16(0x0FB0);
    uint16_t value7 = RAM16(0x0FB4);
    uint16_t value8 = RAM16(0x00A8);
    RAM16_SET(0x00B0 + ((value5 & 4) ^ 4), (uint16_t)(((uint16_t)((uint16_t)(value6 + value7) - value8) ^ 0xFFFF) + 1));
    RAM16_SET(0x0FBE, (uint16_t)(((uint16_t)((uint16_t)(value6 + value7) - value8) ^ 0xFFFF) + 1));
    uint16_t value9 = RAM16(0x028D);
    uint8_t a_hi3;
    if ((value9 & 4) != 0) {
        a_hi3 = value9 >> 8;
    } else {
        uint16_t value10 = RAM16(0x0FBE);
        uint8_t a_hi2;
        if ((uint16_t)(value10 + 0x0110) & 0x8000) {
            RAM16_SET(0x00B0 + ((value5 & 4) ^ 4), 0xFEF0);
            a_hi2 = 0xFE;
        } else {
            uint8_t a_hi1;
            if ((uint16_t)((uint16_t)(value10 + 0x0110) - 0x01A0) & 0x8000) {
                a_hi1 = (uint16_t)((uint16_t)(value10 + 0x0110) - 0x01A0) >> 8;
            } else {
                RAM16_SET(0x00B0 + ((value5 & 4) ^ 4), 0xFEF0);
                a_hi1 = 0xFE;
            }
            a_hi2 = a_hi1;
        }
        a_hi3 = a_hi2;
    }
    uint16_t value11 = RAM16(0x00AA);
    RAM16_SET(0x0295, value11);
    uint16_t value12 = RAM16(0x00C2);
    uint16_t value13 = RAM16(0x0295);
    uint8_t a_hi4;
    if ((uint16_t)(value12 - 0xE0) >= value13) {
        a_hi4 = (uint16_t)(value12 - 0xE0) >> 8;
    } else {
        RAM16_SET(0x0295, (uint16_t)(value11 - value12));
        a_hi4 = (uint16_t)(value11 - value12) >> 8;
    }
    uint16_t value14 = RAM16(0x0FB2);
    uint16_t value15 = RAM16(0x0FB6);
    uint16_t value16 = RAM16(0x0295);
    RAM16_SET(0x0FBC, (uint16_t)((uint16_t)(value14 + value15) - value16));
    RAM16_SET(0x00B2 + ((value5 & 4) ^ 4), (uint16_t)(((uint16_t)((uint16_t)(value14 + value15) - value16) ^ 0xFFFF) + 1));
    uint16_t value17 = RAM16(0x0287);
    r->a = (uint16_t)(((uint16_t)((uint16_t)(value14 + value15) - value16) ^ 0xFFFF) + 1);
    r->x = value17;
    r->v = (((uint16_t)(value14 + value15) ^ value16) & ((uint16_t)(value14 + value15) ^ (uint16_t)((uint16_t)(value14 + value15) - value16)) & 0x8000) != 0;
    JSR(c, 0x10AA, 0xC22005); /* prepare_boss_sprite_screen_position */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2102B, SOM_RTS, "gen", align_boss_camera_scroll_and_screen_position, 0, L_Y | L_V, 1, 0, 0, 129, 57)
