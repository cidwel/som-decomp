#include "som_c.h"
#include "som_hand_b.h"

/* C64604 append_five_byte_mode_seven_scene_object   [class A, 39 bytes, 22 instructions]
 * Source: src/rom/append_five_byte_mode_seven_scene_object.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$C7 D=$0000.  Callers read: BY.
 */
static void append_five_byte_mode_seven_scene_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0xC7, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t count = RAM16(0x004E);
    uint16_t slot = (uint16_t)((uint16_t)((count << 2) + count) + 0x1100); /* count * 5 + $1100 */
    RAM16_SET(0x004E, (uint16_t)(count + 1));
    /* Direct page,X is addressed in bank 0 with a 16-bit wrap: a large count leaves WRAM. */
    BUS8_SET(c, (uint16_t)(slot + 0), RAM8(0x0021));
    BUS8_SET(c, (uint16_t)(slot + 1), RAM8(0x0020));
    BUS8_SET(c, (uint16_t)(slot + 2), RAM8(0x0022));
    BUS8_SET(c, (uint16_t)(slot + 3), RAM8(0x0024));
    BUS8_SET(c, (uint16_t)(slot + 4), RAM8(0x0025));
    r->x = slot;
    r->a = (uint16_t)((slot & 0xFF00) | RAM8(0x0025));
    RETURN_RTL(c);
}
SOM_REGISTER(0xC64604, SOM_RTL, "hand", append_five_byte_mode_seven_scene_object, 0, L_B | L_Y, 1, 1, 0, 39, 22)
