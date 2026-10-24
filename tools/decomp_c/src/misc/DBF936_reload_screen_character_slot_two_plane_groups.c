#include "som_c.h"

/* DBF936 reload_screen_character_slot_two_plane_groups   [class D, 114 bytes, 54 instructions]
 * Source: src/rom/reload_screen_character_slot_two_plane_groups.s
 * Documented in docs/event-screen-tile-reload.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0200.  Callers read: Y.
 */
static void reload_screen_character_slot_two_plane_groups(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    RAM8(0x026A) = a;
    uint16_t value = RAM16(0x0268);
    RAM16_SET(0x026C, (value & 0xF8) << 1 << 1);
    uint16_t value2 = RAM16(0x026C);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)((uint16_t)(((value & 7) << 1) + value2) << 5) < 0x2000) {
        a1 = (uint8_t)((uint16_t)(((value & 7) << 1) + value2) << 5);
        a_hi1 = (uint16_t)((uint16_t)(((value & 7) << 1) + value2) << 5) >> 8;
    } else {
        a1 = (uint8_t)((uint16_t)((uint16_t)(((value & 7) << 1) + value2) << 5) + 0x2000);
        a_hi1 = (uint16_t)((uint16_t)((uint16_t)(((value & 7) << 1) + value2) << 5) + 0x2000) >> 8;
    }
    RAM16_SET(0x0E7D, (uint16_t)(((a_hi1 << 8) | a1) + 0x2000));
    uint16_t value4 = BUS16(c, 0xD97F35 + (uint8_t)(RAM16(0x026A) << 1));
    RAM16_SET(0x0E7F, (uint16_t)((uint16_t)(value4 << 4) + 0x6000));
    BUS16_SET(c, 0x004365, 0x40);
    BUS16_SET(c, 0x004375, 0x40);
    uint16_t value5 = RAM16(0x0E7D);
    BUS16_SET(c, 0x004362, value5);
    BUS16_SET(c, 0x004372, (uint16_t)(value5 + 0x0200));
    uint16_t value6 = RAM16(0x0E7F);
    BUS16_SET(c, 0x002116, value6);
    BUS8_SET(c, 0x00420B, 0x40);
    BUS16_SET(c, 0x002116, (uint16_t)(value6 + 0x0100));
    BUS8_SET(c, 0x00420B, 0x80);
    RETURN_RTS(c);
}
SOM_REGISTER(0xDBF936, SOM_RTS, "gen", reload_screen_character_slot_two_plane_groups, 0, L_Y, 1, 1, 1, 114, 54)
