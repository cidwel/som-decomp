#include "som_c.h"

/* C09DFC advance_and_publish_automatic_ui_party_icons   [class B, 41 bytes, 23 instructions]
 * Source: src/rom/advance_and_publish_automatic_ui_party_icons.s
 * Documented in docs/ui-native-ui-frame-sprites.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_and_publish_automatic_ui_party_icons(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x00F4);
    bool carry1;
    bool overflow1;
    if ((value & 3) != 0) {
        carry1 = carry;
        overflow1 = overflow;
    } else {
        uint8_t value2 = RAM8(0x009C);
        uint8_t a1;
        if ((uint8_t)(value2 + 0x30) < 0xC0) {
            a1 = (uint8_t)(value2 + 0x30);
        } else {
            a1 = 0;
        }
        RAM8(0x009C) = a1;
        carry1 = (uint8_t)(value2 + 0x30) >= 0xC0;
        overflow1 = ((value2 ^ (uint8_t)(value2 + 0x30)) & ((uint8_t)(value2 + 0x30) ^ 0x30) & 0x80) != 0;
    }
    RAM8(0x009D) = 0xE7;
    RAM8(0x007C) = 0;
    RAM8(RING_OPEN) = 0;
    r->a = (a_hi << 8) | 0xE7;
    r->xf = 0;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0x9E22, 0xC09E25); /* select_active_ui_party_icon_composition */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09DFC, SOM_RTS, "gen", advance_and_publish_automatic_ui_party_icons, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 41, 23)
