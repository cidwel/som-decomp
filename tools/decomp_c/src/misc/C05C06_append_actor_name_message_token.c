#include "som_c.h"

/* C05C06 append_actor_name_message_token   [class A, 36 bytes, 18 instructions]
 * Source: src/rom/append_actor_name_message_token.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABYCV.
 */
static void append_actor_name_message_token(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    if (RAM8(ACTOR_KIND_FLAGS + x) & 0x80) {
        RAM8(0xFE00 + y) = 0x57;
        uint8_t value2 = RAM8(0xE1E7 + x);
        RAM8(0xFE00 + (uint16_t)(y + 1)) = (uint8_t)(value2 - 0x80);
        SET_A8(r, (uint8_t)(value2 - 0x80));
        r->y = (uint16_t)(y + 2);
        r->c = value2 >= 0x80;
        r->v = ((value2 ^ 0x80) & (value2 ^ (uint8_t)(value2 - 0x80)) & 0x80) != 0;
        RETURN_RTS(c);
    }
    RAM8(0xFE00 + y) = 0x54;
    uint8_t value3 = RAM8(0xE1E7 + x);
    RAM8(0xFE00 + (uint16_t)(y + 1)) = value3;
    SET_A8(r, value3);
    r->y = (uint16_t)(y + 2);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05C06, SOM_RTS, "gen", append_actor_name_message_token, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 0, 36, 18)
