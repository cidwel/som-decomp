#include "som_c.h"

/* C7579F pack_menu_word_into_two_copies_and_advance_cursor   [class A, 18 bytes, 8 instructions]
 * Source: src/rom/pack_menu_word_into_two_copies_and_advance_cursor.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void pack_menu_word_into_two_copies_and_advance_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0xA25A);
    BUS16_SET(c, 0x306000 + x, value);
    BUS16_SET(c, 0x307000 + x, value);
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    r->x = (uint16_t)(x + 2);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7579F, SOM_RTS, "gen", pack_menu_word_into_two_copies_and_advance_cursor, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 18, 8)
