#include "som_c.h"
#include "som_hand_b.h"

/* C6462B pack_mode_seven_scene_objects_into_complete_oam_buffer   [class B, 154 bytes, 82 instructions]
 * Source: src/rom/pack_mode_seven_scene_objects_into_complete_oam_buffer.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BY.
 */
static void pack_mode_seven_scene_objects_into_complete_oam_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    /* Data bank 0: absolute,X/Y accesses are bank 0 plus index (24-bit, no wrap); direct page,X wraps at 16 bits. */
    uint16_t x = 0x15E0;
    uint16_t y;
    for (y = 0x80; y != 0; y--) { /* 128 hidden sprites: Y = $E0, high-table bits clear */
        BUS16_SET(c, x, 0xE000);
        BUS16_SET(c, (uint32_t)x + 2, 0);
        x = (uint16_t)(x + 4);
    }
    for (y = 8; y != 0; y--) { /* the 32-byte high table */
        BUS16_SET(c, x, 0);
        BUS16_SET(c, (uint32_t)x + 2, 0);
        x = (uint16_t)(x + 4);
    }
    uint16_t count = RAM16(0x004E);
    uint16_t a16 = count;
    y = 0;
    if (count != 0) {
        RAM16_SET(0x0030, count);
        RAM16_SET(0x0032, 0x17E0);
        RAM16_SET(0x0034, 0);
        x = 0x15E0;
        y = 0x1100;
        do {
            if ((uint32_t)y + 5 > 0x2000) { c->fail = 3; return; } /* the five source bytes must be WRAM: unmapped reads return the open bus */
            BUS16_SET(c, x, BUS16(c, 0x000001u + y));
            BUS16_SET(c, (uint32_t)x + 2, BUS16(c, 0x000003u + y));
            r->x = x;
            i_phx(c);
            uint16_t high = RAM16(0x0032);
            uint8_t phase = RAM8(0x0034);
            uint8_t bits;
            if (phase != 0 && high >= 0x2000) { c->fail = 3; return; } /* read-modify-write of an unmapped address depends on the open bus */
            if (phase == 0) {
                bits = BUS8(c, y);
            } else if (phase == 1) {
                bits = (uint8_t)((uint8_t)(BUS8(c, y) << 2) | BUS8(c, high));
            } else if (phase == 2) {
                bits = (uint8_t)((uint8_t)(BUS8(c, y) << 4) | BUS8(c, high));
            } else {
                uint8_t v = BUS8(c, y);
                bool carry = true; /* CMP #$02 with A above 2 */
                for (int k = 0; k < 3; k++) { /* ROR A three times */
                    bool next = v & 1;
                    v = (uint8_t)((v >> 1) | (carry << 7));
                    carry = next;
                }
                bits = (uint8_t)((v & 0xC0) | BUS8(c, high));
            }
            BUS8_SET(c, high, bits);
            if (phase >= 3) {
                RAM16_SET(0x0032, (uint16_t)(high + 1));
                RAM8(0x0034) = 0;
            } else {
                RAM8(0x0034) = (uint8_t)(phase + 1);
            }
            i_plx(c);
            x = (uint16_t)(r->x + 4);
            y = (uint16_t)(y + 5);
            a16 = y;
            RAM16_SET(0x0030, (uint16_t)(RAM16(0x0030) - 1));
        } while (RAM16(0x0030) != 0);
    }
    r->a = (uint16_t)((a16 & 0xFF00) | (r->a & 0xFF));
    r->y = y;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC6462B, SOM_RTL, "hand", pack_mode_seven_scene_objects_into_complete_oam_buffer, 0, L_B | L_Y, 2, 1, 0, 154, 82)
