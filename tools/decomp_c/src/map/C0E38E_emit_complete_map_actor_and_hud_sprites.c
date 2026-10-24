#include "som_c.h"

/* C0E38E emit_complete_map_actor_and_hud_sprites   [class B, 65 bytes, 36 instructions]
 * Source: src/rom/emit_complete_map_actor_and_hud_sprites.s
 * Documented in docs/actor-cast-sprite-publication.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void emit_complete_map_actor_and_hud_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    JSL(c, 0xE391, 0xC1E61D); /* emit_party_hud_sprites_long */
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    uint16_t value = RAM16(0x057E);
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    bool carry2;
    if (value == 0) {
        a2 = 0x7E;
        a_hi2 = a_all >> 8;
        x2 = x;
        carry2 = carry_ret;
    } else {
        uint8_t a1 = 0x7E;
        uint8_t a_hi1 = a_all >> 8;
        uint16_t x1 = x;
        uint16_t y1 = (uint16_t)(value - 2);
        bool carry1 = carry_ret;
        for (;;) {
            uint16_t value2 = RAM16(0x0540 + y1);
            r->a = (a_hi1 << 8) | a1;
            r->x = value2;
            r->y = y1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 3;
            JSR(c, 0xE3A8, 0xC0E3CF); /* emit_one_actor_or_boss_sprite */
            r->sp += 3;
            uint16_t a_all2 = r->a;
            uint16_t x_ret = r->x;
            bool carry_ret2 = r->c;
            a1 = (uint8_t)a_all2;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret;
            y1 = (uint16_t)(y1 - 2);
            carry1 = carry_ret2;
            if (!(!(y1 & 0x8000))) break;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        carry2 = carry1;
    }
    uint16_t value3 = RAM16(0x053E);
    uint8_t a4;
    uint8_t a_hi4;
    uint16_t x4;
    uint16_t y3;
    bool carry4;
    if (value3 == 0) {
        a4 = a2;
        a_hi4 = a_hi2;
        x4 = x2;
        y3 = value3;
        carry4 = carry2;
    } else {
        uint8_t a3 = a2;
        uint8_t a_hi3 = a_hi2;
        uint16_t x3 = x2;
        uint16_t y2 = (uint16_t)(value3 - 2);
        bool carry3 = carry2;
        for (;;) {
            uint16_t value4 = RAM16(0x0500 + y2);
            r->a = (a_hi3 << 8) | a3;
            r->x = value4;
            r->y = y2;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 3;
            JSR(c, 0xE3BB, 0xC0E3CF); /* emit_one_actor_or_boss_sprite */
            r->sp += 3;
            uint16_t a_all3 = r->a;
            uint16_t x_ret2 = r->x;
            bool carry_ret3 = r->c;
            a3 = (uint8_t)a_all3;
            a_hi3 = a_all3 >> 8;
            x3 = x_ret2;
            y2 = (uint16_t)(y2 - 2);
            carry3 = carry_ret3;
            if (!(!(y2 & 0x8000))) break;
        }
        a4 = a3;
        a_hi4 = a_hi3;
        x4 = x3;
        y3 = y2;
        carry4 = carry3;
    }
    uint8_t value5 = RAM8(0x005C);
    bool m_flag;
    uint8_t a_hi5;
    uint16_t x5;
    uint16_t y4;
    bool carry5;
    bool overflow1;
    if (!(value5 & 0x80)) {
        m_flag = 1;
        a_hi5 = a_hi4;
        x5 = x4;
        y4 = y3;
        carry5 = carry4;
        overflow1 = value5 & 0x40;
    } else {
        r->a = (a_hi4 << 8) | a4;
        r->x = x4;
        r->y = y3;
        r->c = carry4;
        r->z = (a4 & value5) == 0;
        r->n = value5 & 0x80;
        r->v = value5 & 0x40;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        r->sp -= 1;
        JSL(c, 0xE3CC, 0xC2000C); /* boss_alternating_object_emission_public_jump */
        r->sp += 1;
        uint16_t a_all4 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        m_flag = 0;
        a_hi5 = a_all4 >> 8;
        x5 = x_ret3;
        y4 = y_ret4;
        carry5 = carry_ret4;
        overflow1 = overflow_ret4;
    }
    r->a = (a_hi5 << 8) | (uint8_t)a;
    r->x = x5;
    r->y = y4;
    r->c = carry5;
    r->v = overflow1;
    r->mf = m_flag; /* SEP #$20 stays in force unless the boss emission ran REP #$20 */
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0E38E, SOM_RTS, "hand", emit_complete_map_actor_and_hud_sprites, 0, L_B | L_X | L_Y | L_C | L_V, 3, -1, 0, 65, 36)
