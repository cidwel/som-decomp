#include "som_c.h"

/* C1F8A7 choose_shared_or_party_character_graphics_upload   [class D, 55 bytes, 24 instructions]
 * Source: src/rom/choose_shared_or_party_character_graphics_upload.s
 * Documented in docs/ui-native-scene-constructor.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void choose_shared_or_party_character_graphics_upload(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x002101, 3);
    if (RAM8(0x008C) == 0) {
        BUS8_SET(c, 0x002115, 0x80);
        BUS8_SET(c, 0x002116, 0);
        BUS8_SET(c, 0x002117, 0x60);
        uint8_t a_hi1 = a_hi;
        uint8_t x1 = 0;
        bool carry1 = carry;
        for (;;) {
            uint8_t value2 = BUS8(c, 0x01F8DE + x1);
            BUS8_SET(c, 0x004370 + x1, value2);
            uint8_t x1_next = (uint8_t)(x1 + 1);
            bool carry1_next = (uint8_t)(x1 + 1) >= 7;
            x1 = x1_next;
            carry1 = carry1_next;
            if (!(x1 < 7)) break;
        }
        BUS8_SET(c, 0x00420B, 0x80);
        r->a = (a_hi1 << 8) | 0x80;
        r->y = y;
        r->c = carry1;
        r->v = overflow;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0x00E3);
    if ((value3 & 0x0F) != 0) {
        BUS8_SET(c, 0x002115, 0x80);
        BUS8_SET(c, 0x002116, 0);
        BUS8_SET(c, 0x002117, 0x60);
        uint8_t a_hi2 = a_hi;
        uint8_t x2 = 0;
        bool carry2 = carry;
        for (;;) {
            uint8_t value4 = BUS8(c, 0x01F8DE + x2);
            BUS8_SET(c, 0x004370 + x2, value4);
            uint8_t x2_next = (uint8_t)(x2 + 1);
            bool carry2_next = (uint8_t)(x2 + 1) >= 7;
            x2 = x2_next;
            carry2 = carry2_next;
            if (!(x2 < 7)) break;
        }
        BUS8_SET(c, 0x00420B, 0x80);
        r->a = (a_hi2 << 8) | 0x80;
        r->y = y;
        r->c = carry2;
        r->v = overflow;
        RETURN_RTS(c);
    }
    r->a = a_hi << 8 | (value3 & 0x0F);
    TAIL_CALL(c, 0xC1FB01, SOM_RTS); /* load_party_scene_frames_with_saved_data_bank */
}
SOM_REGISTER(0xC1F8A7, SOM_RTS, "gen", choose_shared_or_party_character_graphics_upload, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 55, 24)
