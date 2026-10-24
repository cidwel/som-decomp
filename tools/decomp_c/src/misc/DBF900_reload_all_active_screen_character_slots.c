#include "som_c.h"

/* DBF900 reload_all_active_screen_character_slots   [class D, 54 bytes, 26 instructions]
 * Source: src/rom/reload_all_active_screen_character_slots.s
 * Documented in docs/event-screen-tile-reload.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XY.
 */
static void reload_all_active_screen_character_slots(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    BUS8_SET(c, 0x004360, 1);
    BUS8_SET(c, 0x004370, 1);
    BUS8_SET(c, 0x004361, 0x18);
    BUS8_SET(c, 0x004371, 0x18);
    BUS8_SET(c, 0x004364, 0x7F);
    BUS8_SET(c, 0x004374, 0x7F);
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 0;
    uint8_t y1 = (uint8_t)y;
    for (;;) {
        uint8_t value = RAM8(0x0F55 + x1);
        uint8_t a_hi2;
        if (value & 0x80) {
            a_hi2 = a_hi1;
        } else {
            RAM8(0x0268) = value;
            r->a = (a_hi1 << 8) | x1;
            r->y = y1;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0x0200;
            r->sp -= 1;
            JSR(c, 0xF92C, 0xDBF936); /* reload_screen_character_slot_two_plane_groups */
            r->sp += 1;
            uint16_t a_all = r->a;
            a_hi2 = a_all >> 8;
        }
        a_hi1 = a_hi2;
        x1 = (uint8_t)(x1 + 1);
        if (!(x1 != 0x4D)) break;
    }
    r->x = x1;
    r->y = y1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = 0x0200;
    RETURN_RTL(c);
}
SOM_REGISTER(0xDBF900, SOM_RTL, "gen", reload_all_active_screen_character_slots, 0, L_X | L_Y, 1, 0, 0, 54, 26)
