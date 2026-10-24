#include "som_c.h"

/* C0AE96 average_four_world_map_pixels_and_pack_all_eight_bitplanes   [class D, 269 bytes, 138 instructions]
 * Source: src/rom/average_four_world_map_pixels_and_pack_all_eight_bitplanes.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void average_four_world_map_pixels_and_pack_all_eight_bitplanes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0010);
    uint16_t value2 = RAM16(0x0014);
    BUS16_SET(c, 0x002116, (uint16_t)((uint16_t)(value - value2) << 6));
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0x7F;
    uint8_t a_hi1 = (uint16_t)((uint16_t)(value - value2) << 6) >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t value3 = BUS8(c, 0x7FE000 + y1);
            RAM8(0x0000) = RAM8(0x1D800 + value3);
            RAM8(0x0001) = RAM8(0x1D900 + value3);
            RAM8(0x0002) = RAM8(0x1DA00 + value3);
            uint8_t value7 = BUS8(c, 0x7FE001 + y1);
            RAM8(0x0000) = (uint8_t)(RAM8(0x1D800 + value7) + RAM8(0x0000));
            RAM8(0x0001) = (uint8_t)(RAM8(0x1D900 + value7) + RAM8(0x0001));
            RAM8(0x0002) = (uint8_t)(RAM8(0x1DA00 + value7) + RAM8(0x0002));
            uint8_t value14 = BUS8(c, 0x7FE200 + y1);
            RAM8(0x0000) = (uint8_t)(RAM8(0x1D800 + value14) + RAM8(0x0000));
            RAM8(0x0001) = (uint8_t)(RAM8(0x1D900 + value14) + RAM8(0x0001));
            RAM8(0x0002) = (uint8_t)(RAM8(0x1DA00 + value14) + RAM8(0x0002));
            uint8_t value21 = BUS8(c, 0x7FE201 + y1);
            RAM8(0x0000) = (uint8_t)(RAM8(0x1D800 + value21) + RAM8(0x0000)) >> 2;
            RAM8(0x0000) = (((uint8_t)(RAM8(0x1D900 + value21) + RAM8(0x0001)) >> 2) & 0x38) | RAM8(0x0000);
            RAM8(0x0000) = ((uint8_t)(RAM8(0x1DA00 + value21) + RAM8(0x0002)) & 0xC0) | RAM8(0x0000);
            RAM16_SET(0x0002, (y1 & 0x30) << 1 << 1);
            uint16_t value30 = RAM16(0x0002);
            uint8_t value31 = RAM8(0x0000);
            RAM8(0x10000 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30)) = (uint8_t)(RAM8(0x10000 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30)) << 1 | (value31 & 1));
            uint8_t value33 = BUS8(c, 0x7F0001 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30));
            BUS8_SET(c, 0x7F0001 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30), (uint8_t)(BUS8(c, 0x7F0001 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30)) << 1 | ((value31 >> 1) & 1)));
            uint8_t value34 = BUS8(c, 0x7F0010 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30));
            BUS8_SET(c, 0x7F0010 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30), (uint8_t)(BUS8(c, 0x7F0010 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30)) << 1 | ((value31 >> 2) & 1)));
            uint8_t value35 = BUS8(c, 0x7F0011 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30));
            BUS8_SET(c, 0x7F0011 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30), (uint8_t)(BUS8(c, 0x7F0011 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30)) << 1 | ((value31 >> 3) & 1)));
            uint8_t value36 = BUS8(c, 0x7F0020 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30));
            BUS8_SET(c, 0x7F0020 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30), (uint8_t)(BUS8(c, 0x7F0020 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30)) << 1 | ((value31 >> 4) & 1)));
            uint8_t value37 = BUS8(c, 0x7F0021 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30));
            BUS8_SET(c, 0x7F0021 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30), (uint8_t)(BUS8(c, 0x7F0021 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30)) << 1 | ((value31 >> 5) & 1)));
            uint8_t value38 = BUS8(c, 0x7F0030 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30));
            BUS8_SET(c, 0x7F0030 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30), (uint8_t)(BUS8(c, 0x7F0030 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30)) << 1 | ((value31 >> 6) & 1)));
            uint8_t value39 = BUS8(c, 0x7F0031 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30));
            BUS8_SET(c, 0x7F0031 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30), (uint8_t)((BUS8(c, 0x7F0031 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30)) << 1) | (value31 >> 7)));
            if ((uint16_t)(y1 + 0x0400) < 0x2000) {
                uint8_t a_hi1_next = (uint16_t)(y1 + 0x0400) >> 8;
                uint16_t x1_next = (((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30;
                uint16_t y1_next = (uint16_t)(y1 + 0x0400);
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                y1 = y1_next;
                first_pass = false;
                continue;
            }
            if ((((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 & 0x3F) == 0) {
                r->a = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 & 0x3F;
                r->x = (((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30;
                r->y = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2;
                r->c = (uint16_t)(y1 + 0x0400) >= 0x2000;
                r->z = (((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 & 0x3F) == 0;
                r->n = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 & 0x3F & 0x8000;
                r->v = ((y1 ^ (uint16_t)(y1 + 0x0400)) & ((uint16_t)(y1 + 0x0400) ^ 0x0400) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->db = 0x7F;
                r->dp = 0;
                r->sp -= 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAF7E, 0xC0AFA3); GUARD_JSR(c, sp_call, 0xAF7E); } /* await_world_map_survey_nmi_acknowledgement */
                r->sp += 1;
                BUS16_SET(c, 0x004375, 0x0100);
                BUS16_SET(c, 0x004372, 0);
                BUS8_SET(c, 0x00420B, 0x80);
            }
            if (((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 < 0x0200) {
                uint8_t a_hi1_next2 = 0;
                uint16_t x1_next2 = (((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30;
                uint16_t y1_next2 = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2;
                a_hi1 = a_hi1_next2;
                x1 = x1_next2;
                y1 = y1_next2;
                first_pass = false;
                continue;
            }
            uint8_t a_hi1_next3 = 0;
            uint16_t x1_next3 = (((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value30;
            uint16_t y1_next3 = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2;
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            y1 = y1_next3;
            break;
        } else {
            uint8_t value40 = BUS8(c, 0x7FE000 + y1);
            RAM8(0x0000) = RAM8(0x1D800 + value40);
            RAM8(0x0001) = RAM8(0x1D900 + value40);
            RAM8(0x0002) = RAM8(0x1DA00 + value40);
            uint8_t value44 = BUS8(c, 0x7FE001 + y1);
            RAM8(0x0000) = (uint8_t)(RAM8(0x1D800 + value44) + RAM8(0x0000));
            RAM8(0x0001) = (uint8_t)(RAM8(0x1D900 + value44) + RAM8(0x0001));
            RAM8(0x0002) = (uint8_t)(RAM8(0x1DA00 + value44) + RAM8(0x0002));
            uint8_t value51 = BUS8(c, 0x7FE200 + y1);
            RAM8(0x0000) = (uint8_t)(RAM8(0x1D800 + value51) + RAM8(0x0000));
            RAM8(0x0001) = (uint8_t)(RAM8(0x1D900 + value51) + RAM8(0x0001));
            RAM8(0x0002) = (uint8_t)(RAM8(0x1DA00 + value51) + RAM8(0x0002));
            uint8_t value58 = BUS8(c, 0x7FE201 + y1);
            RAM8(0x0000) = (uint8_t)(RAM8(0x1D800 + value58) + RAM8(0x0000)) >> 2;
            RAM8(0x0000) = (((uint8_t)(RAM8(0x1D900 + value58) + RAM8(0x0001)) >> 2) & 0x38) | RAM8(0x0000);
            RAM8(0x0000) = ((uint8_t)(RAM8(0x1DA00 + value58) + RAM8(0x0002)) & 0xC0) | RAM8(0x0000);
            RAM16_SET(0x0002, (y1 & 0x30) << 1 << 1);
            uint16_t value67 = RAM16(0x0002);
            uint8_t value68 = RAM8(0x0000);
            RAM8(0x10000 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67)) = (uint8_t)(RAM8(0x10000 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67)) << 1 | (value68 & 1));
            uint8_t value70 = BUS8(c, 0x7F0001 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67));
            BUS8_SET(c, 0x7F0001 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67), (uint8_t)(BUS8(c, 0x7F0001 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67)) << 1 | ((value68 >> 1) & 1)));
            uint8_t value71 = BUS8(c, 0x7F0010 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67));
            BUS8_SET(c, 0x7F0010 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67), (uint8_t)(BUS8(c, 0x7F0010 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67)) << 1 | ((value68 >> 2) & 1)));
            uint8_t value72 = BUS8(c, 0x7F0011 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67));
            BUS8_SET(c, 0x7F0011 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67), (uint8_t)(BUS8(c, 0x7F0011 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67)) << 1 | ((value68 >> 3) & 1)));
            uint8_t value73 = BUS8(c, 0x7F0020 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67));
            BUS8_SET(c, 0x7F0020 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67), (uint8_t)(BUS8(c, 0x7F0020 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67)) << 1 | ((value68 >> 4) & 1)));
            uint8_t value74 = BUS8(c, 0x7F0021 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67));
            BUS8_SET(c, 0x7F0021 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67), (uint8_t)(BUS8(c, 0x7F0021 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67)) << 1 | ((value68 >> 5) & 1)));
            uint8_t value75 = BUS8(c, 0x7F0030 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67));
            BUS8_SET(c, 0x7F0030 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67), (uint8_t)(BUS8(c, 0x7F0030 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67)) << 1 | ((value68 >> 6) & 1)));
            uint8_t value76 = BUS8(c, 0x7F0031 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67));
            BUS8_SET(c, 0x7F0031 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67), (uint8_t)((BUS8(c, 0x7F0031 + ((((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67)) << 1) | (value68 >> 7)));
            if ((uint16_t)(y1 + 0x0400) < 0x2000) {
                uint8_t a_hi1_next4 = (uint16_t)(y1 + 0x0400) >> 8;
                uint16_t x1_next4 = (((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67;
                uint16_t y1_next4 = (uint16_t)(y1 + 0x0400);
                a_hi1 = a_hi1_next4;
                x1 = x1_next4;
                y1 = y1_next4;
                continue;
            }
            if ((((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 & 0x3F) == 0) {
                r->a = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 & 0x3F;
                r->x = (((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67;
                r->y = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2;
                r->c = (uint16_t)(y1 + 0x0400) >= 0x2000;
                r->z = (((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 & 0x3F) == 0;
                r->n = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 & 0x3F & 0x8000;
                r->v = ((y1 ^ (uint16_t)(y1 + 0x0400)) & ((uint16_t)(y1 + 0x0400) ^ 0x0400) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->db = 0x7F;
                r->dp = 0;
                r->sp -= 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAF7E, 0xC0AFA3); GUARD_JSR(c, sp_call, 0xAF7E); } /* await_world_map_survey_nmi_acknowledgement */
                r->sp += 1;
                BUS16_SET(c, 0x004375, 0x0100);
                BUS16_SET(c, 0x004372, 0);
                BUS8_SET(c, 0x00420B, 0x80);
            }
            if (((uint16_t)(y1 + 0x0400) & 0x03FF) + 2 < 0x0200) {
                uint8_t a_hi1_next5 = 0;
                uint16_t x1_next5 = (((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67;
                uint16_t y1_next5 = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2;
                a_hi1 = a_hi1_next5;
                x1 = x1_next5;
                y1 = y1_next5;
                continue;
            }
            uint8_t a_hi1_next6 = 0;
            uint16_t x1_next6 = (((((uint8_t)y1 << 8) | (y1 >> 8)) >> 1) & 0x0E) | value67;
            uint16_t y1_next6 = ((uint16_t)(y1 + 0x0400) & 0x03FF) + 2;
            a_hi1 = a_hi1_next6;
            x1 = x1_next6;
            y1 = y1_next6;
            break;
        }
    }
    uint8_t value77 = RAM8(0x0000 + sp0);
    r->x = x1;
    r->y = y1;
    r->mf = 0;
    r->xf = 0;
    r->db = value77;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0AE96, SOM_RTS, "gen", average_four_world_map_pixels_and_pack_all_eight_bitplanes, 0, L_X | L_Y, 2, 0, 0, 269, 138)
