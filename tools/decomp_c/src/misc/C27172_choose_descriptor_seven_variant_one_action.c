#include "som_c.h"

/* C27172 choose_descriptor_seven_variant_one_action   [class B, 129 bytes, 59 instructions]
 * Source: src/rom/choose_descriptor_seven_variant_one_action.s
 * Documented in docs/boss-descriptor-seven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_seven_variant_one_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x0032 + value);
    uint16_t value3 = RAM16(0x0004 + y);
    if ((uint16_t)(value2 - value3) & 0x8000) {
        if ((RAM16(0x01B0 + value) & 0xFF) != 0) {
            uint16_t value5 = RAM16(0x002B + value);
            uint16_t value6 = RAM16(0x0002 + y);
            if (value5 >= value6) {
                r->a = value5;
                r->c = value5 >= value6;
                r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
                JSR(c, 0x71D9, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
                uint16_t a_all = r->a;
                if (a_all < 2) {
                    uint16_t value7 = BUS16(c, 0xDCE511);
                    r->a = value7;
                    r->c = 0;
                    r->z = value7 == 0;
                    r->n = value7 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 1;
                r->c = a_all >= 2;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x71E4, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all2 = r->a;
                uint16_t value8 = BUS16(c, 0xDCE511 + (uint16_t)(a_all2 << 1));
                r->a = value8;
                r->x = (uint16_t)(a_all2 << 1);
                r->c = 0;
                r->z = value8 == 0;
                r->n = value8 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = value5;
            r->c = value5 >= value6;
            r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
            JSR(c, 0x71BD, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all3 = r->a;
            if (a_all3 < 2) {
                uint16_t value9 = BUS16(c, 0xDCE50D);
                r->a = value9;
                r->c = 0;
                r->z = value9 == 0;
                r->n = value9 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 1;
            r->c = a_all3 >= 2;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x71C8, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all4 = r->a;
            uint16_t value10 = BUS16(c, 0xDCE50D + (uint16_t)(a_all4 << 1));
            r->a = value10;
            r->x = (uint16_t)(a_all4 << 1);
            r->c = 0;
            r->z = value10 == 0;
            r->n = value10 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xEB99;
        r->x = value;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value2 - value3) >= 0x20) {
        if ((RAM16(0x01B0 + value) & 0xFF) != 0) {
            uint16_t value12 = RAM16(0x002B + value);
            uint16_t value13 = RAM16(0x0002 + y);
            if (value12 >= value13) {
                r->a = value12;
                r->c = value12 >= value13;
                r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
                JSR(c, 0x71D9, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
                uint16_t a_all5 = r->a;
                if (a_all5 < 2) {
                    uint16_t value14 = BUS16(c, 0xDCE511);
                    r->a = value14;
                    r->c = 0;
                    r->z = value14 == 0;
                    r->n = value14 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 1;
                r->c = a_all5 >= 2;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x71E4, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all6 = r->a;
                uint16_t value15 = BUS16(c, 0xDCE511 + (uint16_t)(a_all6 << 1));
                r->a = value15;
                r->x = (uint16_t)(a_all6 << 1);
                r->c = 0;
                r->z = value15 == 0;
                r->n = value15 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = value12;
            r->c = value12 >= value13;
            r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
            JSR(c, 0x71BD, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all7 = r->a;
            if (a_all7 < 2) {
                uint16_t value16 = BUS16(c, 0xDCE50D);
                r->a = value16;
                r->c = 0;
                r->z = value16 == 0;
                r->n = value16 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 1;
            r->c = a_all7 >= 2;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x71C8, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all8 = r->a;
            uint16_t value17 = BUS16(c, 0xDCE50D + (uint16_t)(a_all8 << 1));
            r->a = value17;
            r->x = (uint16_t)(a_all8 << 1);
            r->c = 0;
            r->z = value17 == 0;
            r->n = value17 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xEB99;
        r->x = value;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value18 = RAM16(0x002B + value);
    uint16_t value19 = RAM16(0x0002 + y);
    if (value18 >= value19) {
        r->a = 2;
        r->x = value;
        r->c = value18 >= value19;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        JSR(c, 0x719D, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all9 = r->a;
        uint16_t value20 = BUS16(c, 0xDCE507 + (uint16_t)(a_all9 << 1));
        r->a = value20;
        r->x = (uint16_t)(a_all9 << 1);
        r->c = 0;
        r->z = value20 == 0;
        r->n = value20 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 2;
    r->x = value;
    r->c = value18 >= value19;
    r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
    JSR(c, 0x718F, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all10 = r->a;
    uint16_t value21 = BUS16(c, 0xDCE501 + (uint16_t)(a_all10 << 1));
    r->a = value21;
    r->x = (uint16_t)(a_all10 << 1);
    r->c = 0;
    r->z = value21 == 0;
    r->n = value21 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27172, SOM_RTS, "gen", choose_descriptor_seven_variant_one_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 129, 59)
