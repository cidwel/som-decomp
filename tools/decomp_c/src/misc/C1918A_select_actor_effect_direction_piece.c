#include "som_c.h"

/* C1918A select_actor_effect_direction_piece   [class B, 87 bytes, 45 instructions]
 * Source: src/rom/select_actor_effect_direction_piece.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYV.
 */
static void select_actor_effect_direction_piece(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    if (a >= 0x10) {
        if (a >= 0x30) {
            if (a >= 0x50) {
                if (a >= 0x70) {
                    if (a >= 0x90) {
                        if (a >= 0xB0) {
                            if (a >= 0xD0) {
                                uint8_t a1;
                                if (a >= 0xF0) {
                                    a1 = 0x18;
                                } else {
                                    a1 = 0x0C;
                                }
                                RAM16_SET(0x0000, ((a_hi << 8) | a1) & 0xFF);
                                uint16_t value = RAM16(0x0000);
                                r->a = x | value;
                                r->x = x | value;
                                r->mf = 0;
                                RETURN_RTS(c);
                            }
                            RETURN_RTS(c);
                        }
                        RAM16_SET(0x0000, ((a_hi << 8) | 0x30) & 0xFF);
                        uint16_t value2 = RAM16(0x0000);
                        r->a = x | value2;
                        r->x = x | value2;
                        r->mf = 0;
                        RETURN_RTS(c);
                    }
                    RAM16_SET(0x0000, ((a_hi << 8) | 0x3C) & 0xFF);
                    uint16_t value3 = RAM16(0x0000);
                    r->a = x | value3;
                    r->x = x | value3;
                    r->mf = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0x0000, ((a_hi << 8) | 0x54) & 0xFF);
                uint16_t value4 = RAM16(0x0000);
                r->a = x | value4;
                r->x = x | value4;
                r->mf = 0;
                RETURN_RTS(c);
            }
            RAM16_SET(0x0000, ((a_hi << 8) | 0x24) & 0xFF);
            uint16_t value5 = RAM16(0x0000);
            r->a = x | value5;
            r->x = x | value5;
            r->mf = 0;
            RETURN_RTS(c);
        }
        RAM16_SET(0x0000, ((a_hi << 8) | 0x48) & 0xFF);
        uint16_t value6 = RAM16(0x0000);
        r->a = x | value6;
        r->x = x | value6;
        r->mf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0000, ((a_hi << 8) | 0x18) & 0xFF);
    uint16_t value7 = RAM16(0x0000);
    r->a = x | value7;
    r->x = x | value7;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1918A, SOM_RTS, "gen", select_actor_effect_direction_piece, 0, L_A | L_B | L_X | L_Y | L_V, 1, 1, 0, 87, 45)
