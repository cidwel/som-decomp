#include "som_c.h"

/* C7503D publish_four_native_name_entry_cursor_corners   [class B, 66 bytes, 26 instructions]
 * Source: src/rom/publish_four_native_name_entry_cursor_corners.s
 * Documented in docs/event-menu-name-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void publish_four_native_name_entry_cursor_corners(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0xA173, RAM16(0xA159));
    r->x = 0;
    r->y = 0xB021;
    JSR(c, 0x504B, 0xC75148); /* append_native_name_entry_oam_corner */
    uint16_t a_all = r->a;
    uint8_t value2 = RAM8(0xA173);
    RAM8(0xA173) = (uint8_t)(value2 + 0x0E);
    r->a = (a_all >> 8 << 8) | (uint8_t)(value2 + 0x0E);
    r->y = 0xF021;
    r->c = value2 + 0x0E > 0xFF;
    r->v = ((value2 ^ (uint8_t)(value2 + 0x0E)) & ((uint8_t)(value2 + 0x0E) ^ 0x0E) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x505A, 0xC75148); /* append_native_name_entry_oam_corner */
    uint16_t a_all2 = r->a;
    uint8_t value3 = RAM8(0xA174);
    RAM8(0xA174) = (uint8_t)(value3 + 8);
    r->a = (a_all2 >> 8 << 8) | (uint8_t)(value3 + 8);
    r->y = 0x7021;
    r->c = value3 + 8 > 0xFF;
    r->v = ((value3 ^ (uint8_t)(value3 + 8)) & ((uint8_t)(value3 + 8) ^ 8) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5069, 0xC75148); /* append_native_name_entry_oam_corner */
    uint16_t a_all3 = r->a;
    uint8_t value4 = RAM8(0xA173);
    RAM8(0xA173) = (uint8_t)(value4 - 0x0E);
    r->a = (a_all3 >> 8 << 8) | (uint8_t)(value4 - 0x0E);
    r->y = 0x3021;
    r->c = value4 >= 0x0E;
    r->v = ((value4 ^ 0x0E) & (value4 ^ (uint8_t)(value4 - 0x0E)) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5078, 0xC75148); /* append_native_name_entry_oam_corner */
    RAM8(0xA20A) |= 4;
    SET_A8(r, 4);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC7503D, SOM_RTL, "gen", publish_four_native_name_entry_cursor_corners, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 66, 26)
