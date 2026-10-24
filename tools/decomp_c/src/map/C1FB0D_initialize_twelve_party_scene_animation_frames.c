#include "som_c.h"

/* C1FB0D initialize_twelve_party_scene_animation_frames   [class B, 108 bytes, 52 instructions]
 * Source: src/rom/initialize_twelve_party_scene_animation_frames.s
 * Documented in docs/ui-native-scene-constructor.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void initialize_twelve_party_scene_animation_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    uint8_t a1 = RAM8(0x00F4) & 0x0F;
    uint8_t a_hi1 = a_hi;
    for (;;) {
        if (a1 >= 3) {
            a1 = (uint8_t)(a1 - 3 - (a1 >= 3 ^ 1));
            continue;
        }
        break;
    }
    RAM8(0xE040) = (uint8_t)((uint8_t)(a1 << 2) + 0x86);
    uint8_t a2;
    if ((uint8_t)((uint8_t)(a1 << 2) + 4) < 0x0C) {
        a2 = (uint8_t)((uint8_t)(a1 << 2) + 4);
    } else {
        a2 = (uint8_t)((uint8_t)((uint8_t)(a1 << 2) + 4) - 0x0C - ((uint8_t)((uint8_t)(a1 << 2) + 4) >= 0x0C ^ 1));
    }
    RAM8(0xE240) = (uint8_t)(a2 + 0x86);
    uint8_t a3;
    if ((uint8_t)(a2 + 4) < 0x0C) {
        a3 = (uint8_t)(a2 + 4);
    } else {
        a3 = (uint8_t)((uint8_t)(a2 + 4) - 0x0C - ((uint8_t)(a2 + 4) >= 0x0C ^ 1));
    }
    RAM8(0xE440) = (uint8_t)(a3 + 0x86);
    RAM16_SET(0xE08A, 0x3A00);
    RAM16_SET(0xE28A, 0x3C08);
    RAM16_SET(0xE48A, 0x3E20);
    RAM16_SET(0x001E, 4);
    RAM16_SET(0x001C, 0);
    uint8_t a_hi2 = 0;
    uint16_t y1 = y;
    bool carry1 = a3 + 0x86 > 0xFF;
    bool overflow1 = ((a3 ^ (uint8_t)(a3 + 0x86)) & ((uint8_t)(a3 + 0x86) ^ 0x86) & 0x80) != 0;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            r->a = (a_hi2 << 8) | a;
            r->x = 0;
            r->y = y1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            JSR(c, 0xFB65, 0xC1FB79); /* decode_upload_and_advance_party_scene_frame */
            r->x = 0x0200;
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0xFB6B, 0xC1FB79); /* decode_upload_and_advance_party_scene_frame */
            r->x = 0x0400;
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0xFB71, 0xC1FB79); /* decode_upload_and_advance_party_scene_frame */
            uint16_t a_all3 = r->a;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            RAM8(0x001E)--;
            if (RAM8(0x001E) != 0) {
                a_hi2 = a_all3 >> 8;
                y1 = y_ret3;
                carry1 = carry_ret3;
                overflow1 = overflow_ret3;
                first_pass = false;
                continue;
            }
            a_hi2 = a_all3 >> 8;
            y1 = y_ret3;
            carry1 = carry_ret3;
            overflow1 = overflow_ret3;
            break;
        } else {
            r->a = (a_hi2 << 8) | a;
            r->x = 0;
            r->y = y1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            JSR(c, 0xFB65, 0xC1FB79); /* decode_upload_and_advance_party_scene_frame */
            r->x = 0x0200;
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0xFB6B, 0xC1FB79); /* decode_upload_and_advance_party_scene_frame */
            r->x = 0x0400;
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0xFB71, 0xC1FB79); /* decode_upload_and_advance_party_scene_frame */
            uint16_t a_all6 = r->a;
            uint16_t y_ret6 = r->y;
            bool carry_ret6 = r->c;
            bool overflow_ret6 = r->v;
            RAM8(0x001E)--;
            if (RAM8(0x001E) != 0) {
                a_hi2 = a_all6 >> 8;
                y1 = y_ret6;
                carry1 = carry_ret6;
                overflow1 = overflow_ret6;
                continue;
            }
            a_hi2 = a_all6 >> 8;
            y1 = y_ret6;
            carry1 = carry_ret6;
            overflow1 = overflow_ret6;
            break;
        }
    }
    r->a = (a_hi2 << 8) | a;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FB0D, SOM_RTS, "gen", initialize_twelve_party_scene_animation_frames, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 108, 52)
