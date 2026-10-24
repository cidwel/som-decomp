#include "som_c.h"

/* C2409D initialize_descriptor_two_parent_shape_child   [class B, 166 bytes, 67 instructions]
 * Source: src/rom/initialize_descriptor_two_parent_shape_child.s
 * Documented in docs/boss-descriptor-two-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_two_parent_shape_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x40A1, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0066 + value, 0);
    RAM16_SET(0x00B6 + value, 0x34);
    r->a = 0x34;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x40AD, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x00B2 + value, 0);
    RAM16_SET(0x00AB + value, 0);
    RAM16_SET(0x0090 + value, 0x4143);
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x00B0 + value3);
    uint16_t value5 = RAM16(OBJECT_PHASE + value4);
    if (value5 < 6) {
        RAM16_SET(0x029D, RAM16(0x007A + value4));
        RAM16_SET(0x029F, RAM16(0x00AB + value4));
        uint16_t value8 = RAM16(0x029D);
        if (value8 != RAM16(0x00B2 + value3)) {
            RAM16_SET(0x00B2 + value3, value8);
            RAM16_SET(0x00AB + value3, RAM16(0x029F));
            uint16_t value11 = RAM16(0x0042 + value4);
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            if (value11 != 0) {
                uint16_t value12 = RAM16(0x00B2 + value3);
                uint16_t value13 = BUS16(c, 0xDCE0D0 + value12);
                a1 = (uint8_t)value13;
                a_hi1 = value13 >> 8;
                x1 = value12;
            } else {
                uint16_t value14 = RAM16(0x00B2 + value3);
                uint16_t value15 = BUS16(c, 0xDCE0A8 + value14);
                a1 = (uint8_t)value15;
                a_hi1 = value15 >> 8;
                x1 = value14;
            }
            if ((((a_hi1 << 8) | a1) & 0xFF) == 0) {
                r->a = ((a_hi1 << 8) | a1) & 0xFF;
                r->x = x1;
                r->y = value4;
                r->c = 0;
                r->z = (((a_hi1 << 8) | a1) & 0xFF) == 0;
                r->n = ((a_hi1 << 8) | a1) & 0xFF & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((((a_hi1 << 8) | a1) & 0xFF) != 0xFF) {
                uint16_t value16 = RAM16(0x0287);
                r->a = ((a_hi1 << 8) | a1) & 0xFF;
                r->x = value16;
                r->y = value4;
                r->c = (((a_hi1 << 8) | a1) & 0xFF) >= 0xFF;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x4120, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
                uint16_t value18 = BUS16(c, 0xDCE103 + RAM16(0x00B2 + value16));
                RAM16_SET(0x0295, value18 & 0xC0);
                uint16_t value19 = RAM16(0x0287);
                RAM16_SET(0x0098 + value19, (RAM16(0x0098 + value19) & 0xFF3F) | RAM16(0x0295));
                RAM16_SET(0x0000 + value19, 1);
                r->a = 1;
                r->x = value19;
                r->c = 0;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value22 = RAM16(0x0287);
            RAM16_SET(0x0000 + value22, 0);
            r->a = ((a_hi1 << 8) | a1) & 0xFF;
            r->x = value22;
            r->y = value4;
            r->c = 0;
            r->z = value22 == 0;
            r->n = value22 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value23 = RAM16(0x029F);
        uint16_t value24 = RAM16(0x00AB + value3);
        if (value23 == value24) {
            r->a = value23;
            r->x = value3;
            r->y = value4;
            r->c = 0;
            r->z = value23 == value24;
            r->n = (uint16_t)(value23 - value24) & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM16_SET(0x00B2 + value3, value8);
        RAM16_SET(0x00AB + value3, RAM16(0x029F));
        uint16_t value26 = RAM16(0x0042 + value4);
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        if (value26 != 0) {
            uint16_t value27 = RAM16(0x00B2 + value3);
            uint16_t value28 = BUS16(c, 0xDCE0D0 + value27);
            a2 = (uint8_t)value28;
            a_hi2 = value28 >> 8;
            x2 = value27;
        } else {
            uint16_t value29 = RAM16(0x00B2 + value3);
            uint16_t value30 = BUS16(c, 0xDCE0A8 + value29);
            a2 = (uint8_t)value30;
            a_hi2 = value30 >> 8;
            x2 = value29;
        }
        if ((((a_hi2 << 8) | a2) & 0xFF) == 0) {
            r->a = ((a_hi2 << 8) | a2) & 0xFF;
            r->x = x2;
            r->y = value4;
            r->c = 0;
            r->z = (((a_hi2 << 8) | a2) & 0xFF) == 0;
            r->n = ((a_hi2 << 8) | a2) & 0xFF & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((((a_hi2 << 8) | a2) & 0xFF) != 0xFF) {
            uint16_t value31 = RAM16(0x0287);
            r->a = ((a_hi2 << 8) | a2) & 0xFF;
            r->x = value31;
            r->y = value4;
            r->c = (((a_hi2 << 8) | a2) & 0xFF) >= 0xFF;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x4120, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
            uint16_t value33 = BUS16(c, 0xDCE103 + RAM16(0x00B2 + value31));
            RAM16_SET(0x0295, value33 & 0xC0);
            uint16_t value34 = RAM16(0x0287);
            RAM16_SET(0x0098 + value34, (RAM16(0x0098 + value34) & 0xFF3F) | RAM16(0x0295));
            RAM16_SET(0x0000 + value34, 1);
            r->a = 1;
            r->x = value34;
            r->c = 0;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value37 = RAM16(0x0287);
        RAM16_SET(0x0000 + value37, 0);
        r->a = ((a_hi2 << 8) | a2) & 0xFF;
        r->x = value37;
        r->y = value4;
        r->c = 0;
        r->z = value37 == 0;
        r->n = value37 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value5;
    r->x = value3;
    r->y = value4;
    r->c = 1;
    r->z = value5 == 6;
    r->n = (uint16_t)(value5 - 6) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2409D, SOM_RTS, "gen", initialize_descriptor_two_parent_shape_child, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 166, 67)
