#include "som_c.h"
#include "som_hand_b.h"

/* C294BE consume_native7f_request_and_choose_upper_or_lower_entrance   [class B, 123 bytes, 45 instructions]
 * Source: src/rom/consume_native7f_request_and_choose_upper_or_lower_entrance.s
 * Documented in docs/boss-native7f-frame-requests.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void consume_native7f_request_and_choose_upper_or_lower_entrance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t request = RAM16(0x0364);
    hand_nz16(r, request);
    if (request != 0) {
        r->a = 0x001F;
        JSR_CHK(c, 0x94C8, 0xC224C3); /* prepare_boss_loader_resource_expansion */
        RAM16_SET(0x0364, 0);
    }
    uint16_t x = RAM16(BATTLE_DEFENCE_WORK);
    r->x = x;
    hand_nz16(r, x);
    uint16_t age = RAM16(OBJECT_AGE + x);
    r->a = age;
    hand_cmp16(r, age, 9);
    if (age < 9) {
        JSR_CHK(c, 0x9536, 0xC295A0); /* publish_native7f_single_mode7_frame_dma_request */
        r->c = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(OBJECT_AGE + x, 0);
    RAM16_SET(0x00B0 + x, 0x0080);
    r->a = 0x0110;
    JSR_CHK(c, 0x94E4, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x000B + r->x, 2);
    RAM16_SET(0x00B6 + r->x, 1);
    RAM16_SET(0x02D5, 0x0040);
    RAM16_SET(0x02D7, 0x0040);
    r->a = 0x0010;
    JSR_CHK(c, 0x9502, 0xC2300B); /* draw_boss_frame_random_number */
    bool low_entrance = r->a < 7;
    hand_cmp16(r, r->a, 7);
    x = RAM16(BATTLE_DEFENCE_WORK);
    r->x = x;
    hand_nz16(r, x);
    if (low_entrance) {
        r->a = 0x0006;
        RAM16_SET(OBJECT_PHASE + x, 0x0006);
        r->a = 0x0128;
        RAM16_SET(0x002B + x, 0x0128);
        r->a = 0x0070;
        RAM16_SET(0x0032 + x, 0x0070);
    } else {
        r->a = 0x000D;
        RAM16_SET(OBJECT_PHASE + x, 0x000D);
        r->a = 0x0128;
        RAM16_SET(0x002B + x, 0x0128);
        r->a = 0x0250;
        RAM16_SET(0x0032 + x, 0x0250);
    }
    hand_nz16(r, r->a);
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC294BE, SOM_RTS, "hand", consume_native7f_request_and_choose_upper_or_lower_entrance, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 123, 45)
