#include "som_c.h"

/* C0D5ED move_live_hero_through_ground_terrain_and_camera   [class B, 112 bytes, 50 instructions]
 * Source: src/rom/move_live_hero_through_ground_terrain_and_camera.s
 * Documented in docs/map-hero-motion.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void move_live_hero_through_ground_terrain_and_camera(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->mf = 1; /* sep #$20 / rep #$10 at the entry */
    r->xf = 0;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0010, x);
    uint8_t value = RAM8(0xE00F + x);
    if (value == 0) {
        uint8_t value2 = RAM8(0xE000 + x);
        if (value2 == 0) {
            SET_A8(r, value2);
            r->mf = 1;
            RETURN_RTS(c);
        }
        if (value2 & 0x80) {
            SET_A8(r, value2);
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value3 = RAM8(0xE036 + x);
        if (value3 == 0) {
            uint8_t value4 = RAM8(0xE060 + x);
            uint8_t a_hi2;
            bool carry2;
            bool overflow2;
            if (value4 & 0x80) {
                a_hi2 = a >> 8;
                carry2 = carry;
                overflow2 = overflow;
            } else {
                uint8_t value5 = RAM8(0xE008 + x);
                uint8_t a_hi1;
                bool carry1;
                bool overflow1;
                if (value5 == 0) {
                    a_hi1 = a >> 8;
                    carry1 = carry;
                    overflow1 = overflow;
                } else {
                    r->a = (a >> 8 << 8) | value5;
                    r->n = value5 & 0x80;
                    r->mf = 1;
                    JSR(c, 0xD61C, 0xC0D2C2); /* advance_and_clamp_actor_vertical_motion */
                    uint16_t a_all = r->a;
                    bool carry_ret = r->c;
                    bool overflow_ret = r->v;
                    a_hi1 = a_all >> 8;
                    carry1 = carry_ret;
                    overflow1 = overflow_ret;
                }
                a_hi2 = a_hi1;
                carry2 = carry1;
                overflow2 = overflow1;
            }
            RAM8(0x001E) = RAM8(0xE006 + x);
            RAM8(0x001F) = RAM8(0xE007 + x);
            RAM16_SET(0x0016, RAM16(0x00A8));
            uint16_t value9 = RAM16(0x00AA);
            RAM16_SET(0x0018, value9);
            RAM8(0x001A) = 0x0C;
            uint8_t value10 = RAM8(0xE00B + x);
            RAM8(0x001B) = value10;
            uint16_t y1;
            if (!(value10 & 0x80)) {
                y1 = value9;
            } else {
                RAM16_SET(0x0016, RAM16(0x00AC));
                uint16_t value12 = RAM16(0x00AE);
                RAM16_SET(0x0018, value12);
                y1 = value12;
            }
            RAM16_SET(0x0012, RAM16(0xE002 + x));
            uint16_t value14 = RAM16(0xE004 + x);
            RAM16_SET(0x0014, value14);
            r->a = value14;
            r->y = y1;
            r->v = overflow2;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0xD650, 0xC0D2E0); /* apply_actor_ground_contact_effect_to_live_motion */
            uint16_t a_all2 = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            r->mf = 1; /* sep #$20 */
            uint8_t value15 = RAM8(0x001F);
            uint8_t value16 = RAM8(0x001E);
            uint8_t a1;
            uint8_t a_hi3;
            uint16_t x1;
            uint16_t y2;
            bool carry3;
            bool overflow3;
            if ((value15 | value16) == 0) {
                a1 = value15 | value16;
                a_hi3 = a_all2 >> 8;
                x1 = x_ret;
                y2 = y_ret;
                carry3 = carry_ret2;
                overflow3 = overflow_ret2;
            } else {
                r->a = (a_all2 >> 8 << 8) | (value15 | value16);
                r->mf = 1;
                r->xf = 0;
                JSR(c, 0xD65B, 0xC0D65D); /* resolve_hero_party_window_terrain_and_publish_motion */
                uint16_t a_all3 = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret2 = r->y;
                bool carry_ret3 = r->c;
                bool overflow_ret3 = r->v;
                a1 = (uint8_t)a_all3;
                a_hi3 = a_all3 >> 8;
                x1 = x_ret2;
                y2 = y_ret2;
                carry3 = carry_ret3;
                overflow3 = overflow_ret3;
            }
            r->a = (a_hi3 << 8) | a1;
            r->x = x1;
            r->y = y2;
            r->c = carry3;
            r->v = overflow3;
            RETURN_RTS(c);
        }
        RAM8(0xE037 + x)--;
        if (RAM8(0xE037 + x) & 0x80) {
            RAM8(0xE037 + x) = value3;
            uint8_t value18 = RAM8(0xE060 + x);
            uint8_t a_hi5;
            bool carry5;
            bool overflow5;
            if (value18 & 0x80) {
                a_hi5 = a >> 8;
                carry5 = carry;
                overflow5 = overflow;
            } else {
                uint8_t value19 = RAM8(0xE008 + x);
                uint8_t a_hi4;
                bool carry4;
                bool overflow4;
                if (value19 == 0) {
                    a_hi4 = a >> 8;
                    carry4 = carry;
                    overflow4 = overflow;
                } else {
                    r->a = (a >> 8 << 8) | value19;
                    r->n = value19 & 0x80;
                    r->mf = 1;
                    JSR(c, 0xD61C, 0xC0D2C2); /* advance_and_clamp_actor_vertical_motion */
                    uint16_t a_all4 = r->a;
                    bool carry_ret4 = r->c;
                    bool overflow_ret4 = r->v;
                    a_hi4 = a_all4 >> 8;
                    carry4 = carry_ret4;
                    overflow4 = overflow_ret4;
                }
                a_hi5 = a_hi4;
                carry5 = carry4;
                overflow5 = overflow4;
            }
            RAM8(0x001E) = RAM8(0xE006 + x);
            RAM8(0x001F) = RAM8(0xE007 + x);
            RAM16_SET(0x0016, RAM16(0x00A8));
            uint16_t value23 = RAM16(0x00AA);
            RAM16_SET(0x0018, value23);
            RAM8(0x001A) = 0x0C;
            uint8_t value24 = RAM8(0xE00B + x);
            RAM8(0x001B) = value24;
            uint16_t y3;
            if (!(value24 & 0x80)) {
                y3 = value23;
            } else {
                RAM16_SET(0x0016, RAM16(0x00AC));
                uint16_t value26 = RAM16(0x00AE);
                RAM16_SET(0x0018, value26);
                y3 = value26;
            }
            RAM16_SET(0x0012, RAM16(0xE002 + x));
            uint16_t value28 = RAM16(0xE004 + x);
            RAM16_SET(0x0014, value28);
            r->a = value28;
            r->y = y3;
            r->v = overflow5;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0xD650, 0xC0D2E0); /* apply_actor_ground_contact_effect_to_live_motion */
            uint16_t a_all5 = r->a;
            uint16_t x_ret3 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret5 = r->c;
            bool overflow_ret5 = r->v;
            r->mf = 1; /* sep #$20 */
            uint8_t value29 = RAM8(0x001F);
            uint8_t value30 = RAM8(0x001E);
            uint8_t a2;
            uint8_t a_hi6;
            uint16_t x2;
            uint16_t y4;
            bool carry6;
            bool overflow6;
            if ((value29 | value30) == 0) {
                a2 = value29 | value30;
                a_hi6 = a_all5 >> 8;
                x2 = x_ret3;
                y4 = y_ret3;
                carry6 = carry_ret5;
                overflow6 = overflow_ret5;
            } else {
                r->a = (a_all5 >> 8 << 8) | (value29 | value30);
                r->mf = 1;
                r->xf = 0;
                JSR(c, 0xD65B, 0xC0D65D); /* resolve_hero_party_window_terrain_and_publish_motion */
                uint16_t a_all6 = r->a;
                uint16_t x_ret4 = r->x;
                uint16_t y_ret4 = r->y;
                bool carry_ret6 = r->c;
                bool overflow_ret6 = r->v;
                a2 = (uint8_t)a_all6;
                a_hi6 = a_all6 >> 8;
                x2 = x_ret4;
                y4 = y_ret4;
                carry6 = carry_ret6;
                overflow6 = overflow_ret6;
            }
            r->a = (a_hi6 << 8) | a2;
            r->x = x2;
            r->y = y4;
            r->c = carry6;
            r->v = overflow6;
            RETURN_RTS(c);
        }
        SET_A8(r, value3);
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (value & 0x80) {
        uint8_t value31 = RAM8(0xE000 + x);
        if (value31 == 0) {
            SET_A8(r, value31);
            r->mf = 1;
            RETURN_RTS(c);
        }
        if (value31 & 0x80) {
            SET_A8(r, value31);
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value32 = RAM8(0xE036 + x);
        if (value32 == 0) {
            uint8_t value33 = RAM8(0xE060 + x);
            uint8_t a_hi8;
            bool carry8;
            bool overflow8;
            if (value33 & 0x80) {
                a_hi8 = a >> 8;
                carry8 = carry;
                overflow8 = overflow;
            } else {
                uint8_t value34 = RAM8(0xE008 + x);
                uint8_t a_hi7;
                bool carry7;
                bool overflow7;
                if (value34 == 0) {
                    a_hi7 = a >> 8;
                    carry7 = carry;
                    overflow7 = overflow;
                } else {
                    r->a = (a >> 8 << 8) | value34;
                    r->n = value34 & 0x80;
                    r->mf = 1;
                    JSR(c, 0xD61C, 0xC0D2C2); /* advance_and_clamp_actor_vertical_motion */
                    uint16_t a_all7 = r->a;
                    bool carry_ret7 = r->c;
                    bool overflow_ret7 = r->v;
                    a_hi7 = a_all7 >> 8;
                    carry7 = carry_ret7;
                    overflow7 = overflow_ret7;
                }
                a_hi8 = a_hi7;
                carry8 = carry7;
                overflow8 = overflow7;
            }
            RAM8(0x001E) = RAM8(0xE006 + x);
            RAM8(0x001F) = RAM8(0xE007 + x);
            RAM16_SET(0x0016, RAM16(0x00A8));
            uint16_t value38 = RAM16(0x00AA);
            RAM16_SET(0x0018, value38);
            RAM8(0x001A) = 0x0C;
            uint8_t value39 = RAM8(0xE00B + x);
            RAM8(0x001B) = value39;
            uint16_t y5;
            if (!(value39 & 0x80)) {
                y5 = value38;
            } else {
                RAM16_SET(0x0016, RAM16(0x00AC));
                uint16_t value41 = RAM16(0x00AE);
                RAM16_SET(0x0018, value41);
                y5 = value41;
            }
            RAM16_SET(0x0012, RAM16(0xE002 + x));
            uint16_t value43 = RAM16(0xE004 + x);
            RAM16_SET(0x0014, value43);
            r->a = value43;
            r->y = y5;
            r->v = overflow8;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0xD650, 0xC0D2E0); /* apply_actor_ground_contact_effect_to_live_motion */
            uint16_t a_all8 = r->a;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret5 = r->y;
            bool carry_ret8 = r->c;
            bool overflow_ret8 = r->v;
            r->mf = 1; /* sep #$20 */
            uint8_t value44 = RAM8(0x001F);
            uint8_t value45 = RAM8(0x001E);
            uint8_t a3;
            uint8_t a_hi9;
            uint16_t x3;
            uint16_t y6;
            bool carry9;
            bool overflow9;
            if ((value44 | value45) == 0) {
                a3 = value44 | value45;
                a_hi9 = a_all8 >> 8;
                x3 = x_ret5;
                y6 = y_ret5;
                carry9 = carry_ret8;
                overflow9 = overflow_ret8;
            } else {
                r->a = (a_all8 >> 8 << 8) | (value44 | value45);
                r->mf = 1;
                r->xf = 0;
                JSR(c, 0xD65B, 0xC0D65D); /* resolve_hero_party_window_terrain_and_publish_motion */
                uint16_t a_all9 = r->a;
                uint16_t x_ret6 = r->x;
                uint16_t y_ret6 = r->y;
                bool carry_ret9 = r->c;
                bool overflow_ret9 = r->v;
                a3 = (uint8_t)a_all9;
                a_hi9 = a_all9 >> 8;
                x3 = x_ret6;
                y6 = y_ret6;
                carry9 = carry_ret9;
                overflow9 = overflow_ret9;
            }
            r->a = (a_hi9 << 8) | a3;
            r->x = x3;
            r->y = y6;
            r->c = carry9;
            r->v = overflow9;
            RETURN_RTS(c);
        }
        RAM8(0xE037 + x)--;
        if (RAM8(0xE037 + x) & 0x80) {
            RAM8(0xE037 + x) = value32;
            uint8_t value47 = RAM8(0xE060 + x);
            uint8_t a_hi11;
            bool carry11;
            bool overflow11;
            if (value47 & 0x80) {
                a_hi11 = a >> 8;
                carry11 = carry;
                overflow11 = overflow;
            } else {
                uint8_t value48 = RAM8(0xE008 + x);
                uint8_t a_hi10;
                bool carry10;
                bool overflow10;
                if (value48 == 0) {
                    a_hi10 = a >> 8;
                    carry10 = carry;
                    overflow10 = overflow;
                } else {
                    r->a = (a >> 8 << 8) | value48;
                    r->n = value48 & 0x80;
                    r->mf = 1;
                    JSR(c, 0xD61C, 0xC0D2C2); /* advance_and_clamp_actor_vertical_motion */
                    uint16_t a_all10 = r->a;
                    bool carry_ret10 = r->c;
                    bool overflow_ret10 = r->v;
                    a_hi10 = a_all10 >> 8;
                    carry10 = carry_ret10;
                    overflow10 = overflow_ret10;
                }
                a_hi11 = a_hi10;
                carry11 = carry10;
                overflow11 = overflow10;
            }
            RAM8(0x001E) = RAM8(0xE006 + x);
            RAM8(0x001F) = RAM8(0xE007 + x);
            RAM16_SET(0x0016, RAM16(0x00A8));
            uint16_t value52 = RAM16(0x00AA);
            RAM16_SET(0x0018, value52);
            RAM8(0x001A) = 0x0C;
            uint8_t value53 = RAM8(0xE00B + x);
            RAM8(0x001B) = value53;
            uint16_t y7;
            if (!(value53 & 0x80)) {
                y7 = value52;
            } else {
                RAM16_SET(0x0016, RAM16(0x00AC));
                uint16_t value55 = RAM16(0x00AE);
                RAM16_SET(0x0018, value55);
                y7 = value55;
            }
            RAM16_SET(0x0012, RAM16(0xE002 + x));
            uint16_t value57 = RAM16(0xE004 + x);
            RAM16_SET(0x0014, value57);
            r->a = value57;
            r->y = y7;
            r->v = overflow11;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0xD650, 0xC0D2E0); /* apply_actor_ground_contact_effect_to_live_motion */
            uint16_t a_all11 = r->a;
            uint16_t x_ret7 = r->x;
            uint16_t y_ret7 = r->y;
            bool carry_ret11 = r->c;
            bool overflow_ret11 = r->v;
            r->mf = 1; /* sep #$20 */
            uint8_t value58 = RAM8(0x001F);
            uint8_t value59 = RAM8(0x001E);
            uint8_t a4;
            uint8_t a_hi12;
            uint16_t x4;
            uint16_t y8;
            bool carry12;
            bool overflow12;
            if ((value58 | value59) == 0) {
                a4 = value58 | value59;
                a_hi12 = a_all11 >> 8;
                x4 = x_ret7;
                y8 = y_ret7;
                carry12 = carry_ret11;
                overflow12 = overflow_ret11;
            } else {
                r->a = (a_all11 >> 8 << 8) | (value58 | value59);
                r->mf = 1;
                r->xf = 0;
                JSR(c, 0xD65B, 0xC0D65D); /* resolve_hero_party_window_terrain_and_publish_motion */
                uint16_t a_all12 = r->a;
                uint16_t x_ret8 = r->x;
                uint16_t y_ret8 = r->y;
                bool carry_ret12 = r->c;
                bool overflow_ret12 = r->v;
                a4 = (uint8_t)a_all12;
                a_hi12 = a_all12 >> 8;
                x4 = x_ret8;
                y8 = y_ret8;
                carry12 = carry_ret12;
                overflow12 = overflow_ret12;
            }
            r->a = (a_hi12 << 8) | a4;
            r->x = x4;
            r->y = y8;
            r->c = carry12;
            r->v = overflow12;
            RETURN_RTS(c);
        }
        SET_A8(r, value32);
        RETURN_RTS(c);
    }
    SET_A8(r, value);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D5ED, SOM_RTS, "hand", move_live_hero_through_ground_terrain_and_camera, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 112, 50)
