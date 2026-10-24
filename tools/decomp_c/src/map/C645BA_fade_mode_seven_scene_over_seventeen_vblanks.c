#include "som_c.h"

/* C645BA fade_mode_seven_scene_over_seventeen_vblanks   [class D, 25 bytes, 12 instructions]
 * Source: src/rom/fade_mode_seven_scene_over_seventeen_vblanks.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void fade_mode_seven_scene_over_seventeen_vblanks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    JSR(c, 0x45BC, 0xC6459C); /* await_next_mode_seven_scene_vblank */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x45BF, 0xC6459C); /* await_next_mode_seven_scene_vblank */
    uint16_t a_all2 = r->a;
    BUS8_SET(c, 0x002100, 0x0F);
    uint8_t a1 = 0x0E;
    uint8_t a_hi1 = a_all2 >> 8;
    uint16_t y1 = y;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->y = y1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        r->sp -= 1;
        JSR(c, 0x45CA, 0xC6459C); /* await_next_mode_seven_scene_vblank */
        r->sp += 1;
        uint16_t a_all3 = r->a;
        BUS8_SET(c, 0x002100, a1);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = a_all3 >> 8;
        if (!(!(a1 & 0x80))) break;
    }
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC645BA, SOM_RTS, "gen", fade_mode_seven_scene_over_seventeen_vblanks, 0, 0, 1, 1, 0, 25, 12)
