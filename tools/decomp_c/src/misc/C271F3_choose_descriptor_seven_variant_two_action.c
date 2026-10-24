#include "som_c.h"

/* C271F3 choose_descriptor_seven_variant_two_action   [class B, 126 bytes, 57 instructions]
 * Source: src/rom/choose_descriptor_seven_variant_two_action.s
 * Documented in docs/boss-descriptor-seven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_seven_variant_two_action(SomCtx *c)
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
        if ((RAM16(0x01B1 + value) & 0x40) != 0) {
            if ((RAM16(0x01B0 + value) & 0xFF) != 0) {
                uint16_t value6 = RAM16(0x002B + value);
                uint16_t value7 = RAM16(0x0002 + y);
                if (value6 >= value7) {
                    r->a = value6;
                    r->c = value6 >= value7;
                    r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
                    JSR(c, 0x725F, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
                    uint16_t a_all = r->a;
                    if (a_all < 2) {
                        uint16_t value8 = BUS16(c, 0xDCE521);
                        r->a = value8;
                        r->c = 0;
                        r->z = value8 == 0;
                        r->n = value8 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint16_t value9 = BUS16(c, 0xDCE523);
                    r->a = value9;
                    r->c = 0;
                    r->z = value9 == 0;
                    r->n = value9 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = value6;
                r->c = value6 >= value7;
                r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
                JSR(c, 0x724B, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
                uint16_t a_all2 = r->a;
                if (a_all2 < 2) {
                    uint16_t value10 = BUS16(c, 0xDCE51D);
                    r->a = value10;
                    r->c = 0;
                    r->z = value10 == 0;
                    r->n = value10 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value11 = BUS16(c, 0xDCE51F);
                r->a = value11;
                r->c = 0;
                r->z = value11 == 0;
                r->n = value11 & 0x8000;
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
        r->a = 0xEB9B;
        r->x = value;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value2 - value3) >= 0x20) {
        if ((RAM16(0x01B1 + value) & 0x40) != 0) {
            if ((RAM16(0x01B0 + value) & 0xFF) != 0) {
                uint16_t value14 = RAM16(0x002B + value);
                uint16_t value15 = RAM16(0x0002 + y);
                if (value14 >= value15) {
                    r->a = value14;
                    r->c = value14 >= value15;
                    r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
                    JSR(c, 0x725F, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
                    uint16_t a_all3 = r->a;
                    if (a_all3 < 2) {
                        uint16_t value16 = BUS16(c, 0xDCE521);
                        r->a = value16;
                        r->c = 0;
                        r->z = value16 == 0;
                        r->n = value16 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint16_t value17 = BUS16(c, 0xDCE523);
                    r->a = value17;
                    r->c = 0;
                    r->z = value17 == 0;
                    r->n = value17 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = value14;
                r->c = value14 >= value15;
                r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
                JSR(c, 0x724B, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
                uint16_t a_all4 = r->a;
                if (a_all4 < 2) {
                    uint16_t value18 = BUS16(c, 0xDCE51D);
                    r->a = value18;
                    r->c = 0;
                    r->z = value18 == 0;
                    r->n = value18 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value19 = BUS16(c, 0xDCE51F);
                r->a = value19;
                r->c = 0;
                r->z = value19 == 0;
                r->n = value19 & 0x8000;
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
        r->a = 0xEB9B;
        r->x = value;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value20 = RAM16(0x002B + value);
    uint16_t value21 = RAM16(0x0002 + y);
    if (value20 >= value21) {
        r->a = 1;
        r->x = value;
        r->c = value20 >= value21;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        JSR(c, 0x721E, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all5 = r->a;
        uint16_t value22 = BUS16(c, 0xDCE519 + (uint16_t)(a_all5 << 1));
        r->a = value22;
        r->x = (uint16_t)(a_all5 << 1);
        r->c = 0;
        r->z = value22 == 0;
        r->n = value22 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 1;
    r->x = value;
    r->c = value20 >= value21;
    r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
    JSR(c, 0x7210, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all6 = r->a;
    uint16_t value23 = BUS16(c, 0xDCE515 + (uint16_t)(a_all6 << 1));
    r->a = value23;
    r->x = (uint16_t)(a_all6 << 1);
    r->c = 0;
    r->z = value23 == 0;
    r->n = value23 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC271F3, SOM_RTS, "gen", choose_descriptor_seven_variant_two_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 126, 57)
