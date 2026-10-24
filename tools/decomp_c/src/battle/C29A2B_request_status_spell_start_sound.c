#include "som_c.h"

/* C29A2B request_status_spell_start_sound   [class A, 20 bytes, 9 instructions]
 * Source: src/rom/request_status_spell_start_sound.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYV.
 */
static void request_status_spell_start_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x00B4 + x);
    uint16_t value2 = BUS16(c, 0xDCE77B + (uint16_t)(value << 1));
    uint16_t y1;
    bool overflow1;
    if (value2 == 0) {
        y1 = y;
        overflow1 = overflow;
    } else {
        r->a = value2;
        r->x = 0x0F;
        r->c = value & 0x8000;
        JSR(c, 0x9A3B, 0xC230E3); /* request_boss_sound_with_parameter_word */
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    r->x = RAM16(0x0287);
    r->y = y1;
    r->v = overflow1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29A2B, SOM_RTS, "gen", request_status_spell_start_sound, 0, L_X | L_Y | L_V, 1, 0, 0, 20, 9)
