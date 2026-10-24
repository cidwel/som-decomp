#include "som_c.h"

/* C215B7 prepare_boss_object_terrain   [class B, 204 bytes, 93 instructions]
 * Source: src/rom/prepare_boss_object_terrain.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void prepare_boss_object_terrain(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM16_SET(0x028D, RAM16(0x0098 + x));
    uint16_t value2 = RAM16(0x002B + x);
    uint16_t value3 = RAM16(0x00C0);
    if (value2 >= value3) {
        r->a = value2;
        r->c = value2 >= value3;
        RETURN_RTS(c);
    }
    RAM16_SET(0x023C, value2);
    uint16_t value4 = RAM16(0x0032 + x);
    uint16_t value5 = RAM16(0x00A5 + x);
    uint16_t value6 = RAM16(0x00C2);
    if ((uint16_t)(value4 + value5) < value6) {
        RAM16_SET(0x023E, (uint16_t)(value4 + value5));
        uint16_t value7 = RAM16(0x001E + x);
        uint16_t value8 = BUS16(c, 0xD97EE5 + (uint16_t)(value7 << 1));
        RAM16_SET(0x0240, value8 & 0xFF);
        uint16_t value9 = BUS16(c, 0xD97EE6 + (uint16_t)(value7 << 1));
        RAM16_SET(0x0242, value9 & 0xFF);
        RAM16_SET(0x027A, 0x7F00);
        RAM16_SET(0x027D, 0x7F00);
        RAM16_SET(0x0279, 0);
        RAM16_SET(0x027C, 0xB800);
        uint16_t value10 = RAM16(0x028D);
        uint8_t a_hi1;
        bool overflow1;
        if ((value10 & 2) == 0) {
            a_hi1 = value10 >> 8;
            overflow1 = ((value4 ^ (uint16_t)(value4 + value5)) & (value5 ^ (uint16_t)(value4 + value5)) & 0x8000) != 0;
        } else {
            RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 0x4000));
            uint16_t value12 = RAM16(0x027C);
            RAM16_SET(0x027C, (uint16_t)(value12 + 0x0400));
            a_hi1 = (uint16_t)(value12 + 0x0400) >> 8;
            overflow1 = (((uint16_t)(value12 + 0x0400) ^ 0x0400) & (value12 ^ (uint16_t)(value12 + 0x0400)) & 0x8000) != 0;
        }
        uint16_t value13 = RAM16(0xE00B);
        uint8_t a_hi2;
        bool overflow2;
        if (!(value13 & 0x8000)) {
            a_hi2 = value13 >> 8;
            overflow2 = overflow1;
        } else {
            RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 0x4000));
            uint16_t value15 = RAM16(0x027C);
            RAM16_SET(0x027C, (uint16_t)(value15 + 0x0400));
            a_hi2 = (uint16_t)(value15 + 0x0400) >> 8;
            overflow2 = ((value15 ^ (uint16_t)(value15 + 0x0400)) & ((uint16_t)(value15 + 0x0400) ^ 0x0400) & 0x8000) != 0;
        }
        r->x = RAM16(0x0287);
        r->v = overflow2;
        JSR(c, 0x162D, 0xC21683); /* read_boss_object_terrain_layer */
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint16_t value17 = RAM16(0x028D);
        uint8_t a_hi6;
        uint16_t y4;
        bool carry4;
        bool overflow6;
        if ((value17 & 0x0400) == 0) {
            a_hi6 = value17 >> 8;
            y4 = y_ret;
            carry4 = 0;
            overflow6 = overflow_ret;
        } else {
            RAM16_SET(0x0270, 1);
            uint16_t value18 = RAM16(0x023C);
            uint16_t value19 = RAM16(0x0240);
            RAM16_SET(0x026C, (uint16_t)(value18 + value19));
            RAM16_SET(0x026E, RAM16(0x023E));
            r->v = ((value18 ^ (uint16_t)(value18 + value19)) & (value19 ^ (uint16_t)(value18 + value19)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x1648, 0xC216B6); /* probe_boss_object_terrain_boundary */
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            uint8_t a_hi5;
            uint16_t y3;
            bool carry3;
            bool overflow5;
            if (carry_ret2) {
                a_hi5 = a_all2 >> 8;
                y3 = y_ret2;
                carry3 = carry_ret2;
                overflow5 = overflow_ret2;
            } else {
                RAM16_SET(0x0270, 4);
                uint16_t value21 = RAM16(0x023C);
                uint16_t value22 = RAM16(0x0240);
                RAM16_SET(0x026C, (uint16_t)(value21 - value22));
                r->v = ((value21 ^ value22) & (value21 ^ (uint16_t)(value21 - value22)) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x1659, 0xC216B6); /* probe_boss_object_terrain_boundary */
                uint16_t a_all3 = r->a;
                uint16_t y_ret3 = r->y;
                bool carry_ret3 = r->c;
                bool overflow_ret3 = r->v;
                uint8_t a_hi4;
                uint16_t y2;
                bool carry2;
                bool overflow4;
                if (carry_ret3) {
                    a_hi4 = a_all3 >> 8;
                    y2 = y_ret3;
                    carry2 = carry_ret3;
                    overflow4 = overflow_ret3;
                } else {
                    RAM16_SET(0x0270, 2);
                    RAM16_SET(0x026C, RAM16(0x023C));
                    uint16_t value24 = RAM16(0x023E);
                    uint16_t value25 = RAM16(0x0242);
                    RAM16_SET(0x026E, (uint16_t)(value24 + value25));
                    r->v = ((value24 ^ (uint16_t)(value24 + value25)) & (value25 ^ (uint16_t)(value24 + value25)) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    JSR(c, 0x166E, 0xC216B6); /* probe_boss_object_terrain_boundary */
                    uint16_t a_all4 = r->a;
                    uint16_t y_ret4 = r->y;
                    bool carry_ret4 = r->c;
                    bool overflow_ret4 = r->v;
                    uint8_t a_hi3;
                    uint16_t y1;
                    bool carry1;
                    bool overflow3;
                    if (carry_ret4) {
                        a_hi3 = a_all4 >> 8;
                        y1 = y_ret4;
                        carry1 = carry_ret4;
                        overflow3 = overflow_ret4;
                    } else {
                        RAM16_SET(0x0270, 8);
                        uint16_t value26 = RAM16(0x023E);
                        uint16_t value27 = RAM16(0x0242);
                        RAM16_SET(0x026E, (uint16_t)(value26 - value27));
                        r->v = ((value26 ^ value27) & (value26 ^ (uint16_t)(value26 - value27)) & 0x8000) != 0;
                        r->mf = 0;
                        r->xf = 0;
                        JSR(c, 0x167F, 0xC216B6); /* probe_boss_object_terrain_boundary */
                        uint16_t a_all5 = r->a;
                        uint16_t y_ret5 = r->y;
                        bool carry_ret5 = r->c;
                        bool overflow_ret5 = r->v;
                        a_hi3 = a_all5 >> 8;
                        y1 = y_ret5;
                        carry1 = carry_ret5;
                        overflow3 = overflow_ret5;
                    }
                    a_hi4 = a_hi3;
                    y2 = y1;
                    carry2 = carry1;
                    overflow4 = overflow3;
                }
                a_hi5 = a_hi4;
                y3 = y2;
                carry3 = carry2;
                overflow5 = overflow4;
            }
            a_hi6 = a_hi5;
            y4 = y3;
            carry4 = carry3;
            overflow6 = overflow5;
        }
        uint16_t value28 = RAM16(0x0287);
        r->a = (a_hi6 << 8) | (uint8_t)a;
        r->x = value28;
        r->y = y4;
        r->c = carry4;
        r->v = overflow6;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (uint16_t)(value4 + value5);
    r->c = (uint16_t)(value4 + value5) >= value6;
    r->v = ((value4 ^ (uint16_t)(value4 + value5)) & (value5 ^ (uint16_t)(value4 + value5)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC215B7, SOM_RTS, "gen", prepare_boss_object_terrain, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 204, 93)
