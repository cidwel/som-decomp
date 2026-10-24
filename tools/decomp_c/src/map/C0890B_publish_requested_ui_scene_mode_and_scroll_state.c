#include "som_c.h"

/* C0890B publish_requested_ui_scene_mode_and_scroll_state   [class D, 320 bytes, 144 instructions]
 * Source: src/rom/publish_requested_ui_scene_mode_and_scroll_state.s
 * Documented in docs/ui-native-scene-interrupts.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void publish_requested_ui_scene_mode_and_scroll_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    BUS8_SET(c, 0x00212C, 0x13);
    uint8_t value = RAM8(0x0060);
    RAM8(0x0060) &= 0x7F;
    if ((value & 0x80) != 0) {
        uint8_t value2 = RAM8(0x00F2);
        uint8_t a2;
        if ((value2 & 3) == 0) {
            uint8_t value3 = RAM8(0x00FE);
            uint8_t a1;
            if (value3 == 0) {
                a1 = value3;
            } else {
                BUS8_SET(c, 0x002100, ((value3 >> 2) & 0x0F) ^ 0x0F);
                a1 = ((value3 >> 2) & 0x0F) ^ 0x0F;
            }
            a2 = a1;
        } else {
            uint8_t value4 = RAM8(0x0051);
            BUS8_SET(c, 0x002100, value4);
            a2 = value4;
        }
        BUS8_SET(c, 0x00211A, 0);
        uint8_t a_hi1;
        bool carry1;
        bool overflow1;
        if (!(value2 & 0x80)) {
            uint8_t value5 = RAM8(0x0060);
            RAM8(0x0FE0) = (value5 >> 2) | 0x0C;
            RAM8(0x0FEA) = (value5 >> 2) | 0x0C;
            RAM8(0x0FEA) = (value5 >> 2) | 0x0C;
            RAM8(0x0FFE) = (value5 >> 2) | 0x0C;
            RAM8(0x0FDA) = value5 | 0x10;
            RAM8(0x0FDD) = value5 | 0x10;
            RAM8(0x0FE4) = (uint8_t)((value5 | 0x10) + 1);
            RAM8(0x0FE7) = (uint8_t)((value5 | 0x10) + 1);
            RAM8(0x0FEE) = (uint8_t)((value5 | 0x10) + 2);
            RAM8(0x0FF1) = (uint8_t)((value5 | 0x10) + 2);
            RAM8(0x0FF8) = (uint8_t)((value5 | 0x10) + 3);
            RAM8(0x0FFB) = (uint8_t)((value5 | 0x10) + 3);
            uint8_t value6 = RAM8(0x00F8);
            RAM8(0x0050) = value6 >> 3;
            RAM8(0x0FD8) = ((value6 >> 3) ^ 0x1F) + 0x4C;
            RAM8(0x0FE2) = ((value6 >> 3) ^ 0x1F) + 0x4C;
            RAM8(0x0FEC) = ((value6 >> 3) ^ 0x1F) + 0x4C;
            RAM8(0x0FF6) = ((value6 >> 3) ^ 0x1F) + 0x4C;
            BUS8_SET(c, 0x004209, ((value6 >> 3) ^ 0x1F) + 0x4D);
            RAM8(0x0F00) = RAM8(0x0FD8) & 0x7F;
            BUS8_SET(c, 0x00420C, RAM8(0x002C) | 0x3F);
            BUS8_SET(c, 0x002105, 1);
            uint16_t value9 = RAM16(0x00A9);
            BUS8_SET(c, 0x00210D, (uint8_t)value9);
            BUS8_SET(c, 0x00210D, (uint8_t)(((uint8_t)value9 << 8) | (value9 >> 8)));
            uint16_t value10 = RAM16(0x00AD);
            BUS8_SET(c, 0x00210F, (uint8_t)value10);
            BUS8_SET(c, 0x00210F, value10 >> 8);
            uint8_t value11 = RAM8(0x0050);
            RAM8(0x1300) = value11 ^ 0x1F;
            RAM8(0x1700) = value11 ^ 0x1F;
            RAM8(0x1301) = 0;
            RAM8(0x1701) = 0;
            RAM8(0x0050) = (uint8_t)((uint8_t)((value11 >> 1) + value11) - 1);
            BUS8_SET(c, 0x002110, (uint8_t)((uint8_t)((value11 >> 1) + value11) - 1));
            BUS8_SET(c, 0x002110, 0);
            a_hi1 = (uint8_t)value10;
            carry1 = (value11 >> 1) + value11 > 0xFF;
            overflow1 = (((value11 >> 1) ^ (uint8_t)((value11 >> 1) + value11)) & (value11 ^ (uint8_t)((value11 >> 1) + value11)) & 0x80) != 0;
        } else {
            BUS8_SET(c, 0x00420C, RAM8(0x002C) & 0xC0);
            uint8_t value13 = RAM8(0x0036);
            BUS8_SET(c, 0x00211B, value13);
            uint8_t value14 = RAM8(0x0037);
            BUS8_SET(c, 0x00211B, value14);
            BUS8_SET(c, 0x00211E, value13);
            BUS8_SET(c, 0x00211E, value14);
            uint8_t value15 = RAM8(0x0038);
            BUS8_SET(c, 0x00211C, value15);
            uint8_t value16 = RAM8(0x0039);
            BUS8_SET(c, 0x00211C, value16);
            BUS8_SET(c, 0x00211D, (uint8_t)((value15 ^ 0xFF) + 1));
            BUS8_SET(c, 0x00211D, (uint8_t)((value16 ^ 0xFF) + ((value15 ^ 0xFF) + 1 > 0xFF)));
            BUS8_SET(c, 0x00210D, RAM8(0x003E));
            BUS8_SET(c, 0x00210D, RAM8(0x003F));
            BUS8_SET(c, 0x00210E, RAM8(0x0040));
            BUS8_SET(c, 0x00210E, RAM8(0x0041));
            BUS8_SET(c, 0x002105, 7);
            a_hi1 = a_hi;
            carry1 = (value16 ^ 0xFF) + ((value15 ^ 0xFF) + 1 > 0xFF) > 0xFF;
            overflow1 = ((value16 ^ 0xFF ^ (uint8_t)((value16 ^ 0xFF) + ((value15 ^ 0xFF) + 1 > 0xFF))) & (uint8_t)((value16 ^ 0xFF) + ((value15 ^ 0xFF) + 1 > 0xFF)) & 0x80) != 0;
        }
        BUS8_SET(c, 0x00211F, RAM8(0x00FA));
        BUS8_SET(c, 0x00211F, RAM8(0x00FB) & 3);
        BUS8_SET(c, 0x002120, RAM8(0x00FC));
        BUS8_SET(c, 0x002120, RAM8(0x00FD) & 3);
        RAM8(0x00EC) &= 0xFE;
        r->c = carry1;
        r->v = overflow1;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0890B, SOM_RTS, "gen", publish_requested_ui_scene_mode_and_scroll_state, 0, L_C | L_V, 1, 1, 1, 320, 144)
