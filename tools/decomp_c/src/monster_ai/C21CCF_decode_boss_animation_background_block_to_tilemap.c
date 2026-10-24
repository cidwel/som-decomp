#include "som_c.h"

/* C21CCF decode_boss_animation_background_block_to_tilemap   [class B, 311 bytes, 150 instructions]
 * Source: src/rom/decode_boss_animation_background_block_to_tilemap.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0200.  Callers read: B.
 */
static void decode_boss_animation_background_block_to_tilemap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x026C);
    RAM16_SET(0x0272, (value & 0xFF00) >> 2);
    uint16_t value2 = RAM16(0x0272);
    RAM16_SET(0x027C, (uint16_t)((uint16_t)(((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F)) + 0xBC00 + (((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F) > 0xFFFF)));
    RAM8(0x0278) = 0xC1;
    RAM8(0x027E) = 0x7F;
    RAM8(0x0246) = RAM8(0x026E);
    uint8_t value4 = RAM8(0x026F);
    RAM8(0x024E) = value4;
    r->a = ((uint16_t)((uint16_t)(((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F)) + 0xBC00 + (((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F) > 0xFFFF)) >> 8 << 8) | value4;
    r->c = (uint16_t)(((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F)) + 0xBC00 + (((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F) > 0xFFFF) > 0xFFFF;
    r->v = (((uint16_t)(((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F)) ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F)) + 0xBC00 + (((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F) > 0xFFFF))) & ((uint16_t)((uint16_t)(((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F)) + 0xBC00 + (((value & 0xFF) << 1) + value2 + ((value & 0xFF) >> 0x0F) > 0xFFFF)) ^ 0xBC00) & 0x8000) != 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1CF9, 0xC22AA6); GUARD_JSR(c, sp_call, 0x1CF9); } /* multiply_boss_terrain_row_stride */
    uint16_t value5 = RAM16(0x0287);
    uint16_t value6 = RAM16(0x0098 + value5);
    uint8_t a1;
    if ((value6 & 4) != 0) {
        RAM16_SET(0x0272, RAM16(0x026E) & 0xFF);
        RAM16_SET(0x0274, RAM16(0x0256));
        a1 = 2;
    } else {
        RAM16_SET(0x0272, (RAM16(0x026E) & 0xFF) << 1);
        RAM16_SET(0x0274, (uint16_t)(RAM16(0x0256) << 1));
        a1 = 1;
    }
    RAM16_SET(0x0FAE, a1);
    uint16_t value11 = RAM16(0x0098 + value5);
    uint16_t value12 = RAM16(0x0FB0);
    uint16_t value13 = RAM16(0x0FB4);
    uint16_t value14 = RAM16(0x00A8);
    RAM16_SET(0x00B0 + ((value11 & 4) ^ 4), (uint16_t)(((uint16_t)((uint16_t)(value12 + value13) - value14) ^ 0xFFFF) + 1));
    RAM16_SET(0x0FBE, (uint16_t)(((uint16_t)((uint16_t)(value12 + value13) - value14) ^ 0xFFFF) + 1));
    uint16_t value15 = RAM16(0x00AA);
    RAM16_SET(0x0295, value15);
    uint16_t value16 = RAM16(0x00C2);
    uint16_t value17 = RAM16(0x0295);
    uint8_t a_hi1;
    if ((uint16_t)(value16 - 0xE0) >= value17) {
        a_hi1 = (uint16_t)(value16 - 0xE0) >> 8;
    } else {
        RAM16_SET(0x0295, (uint16_t)(value15 - value16));
        a_hi1 = (uint16_t)(value15 - value16) >> 8;
    }
    uint16_t value18 = RAM16(0x0FB2);
    uint16_t value19 = RAM16(0x0FB6);
    uint16_t value20 = RAM16(0x0295);
    RAM16_SET(0x0FBC, (uint16_t)((uint16_t)(value18 + value19) - value20));
    RAM16_SET(0x00B2 + ((value11 & 4) ^ 4), (uint16_t)(((uint16_t)((uint16_t)(value18 + value19) - value20) ^ 0xFFFF) + 1));
    uint16_t value21 = RAM16(0x0287);
    r->a = (uint16_t)(((uint16_t)((uint16_t)(value18 + value19) - value20) ^ 0xFFFF) + 1);
    r->x = value21;
    r->v = (((uint16_t)(value18 + value19) ^ value20) & ((uint16_t)(value18 + value19) ^ (uint16_t)((uint16_t)(value18 + value19) - value20)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1D79, 0xC22005); GUARD_JSR(c, sp_call, 0x1D79); } /* prepare_boss_sprite_screen_position */
    uint16_t a_all2 = r->a;
    RAM16_SET(0x0295, 0);
    uint8_t value22 = BUS8_RDL(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276), RAM8(0x0278));
    if (value22 != 0) {
        RAM8(0x0276)++;
        if (RAM8(0x0276) == 0) {
            RAM8(0x0277)++;
        }
        uint8_t a_hi2 = a_all2 >> 8;
        uint8_t y1 = 0;
        for (;;) {
            uint8_t value23 = BUS8_RDL(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276), RAM8(0x0278));
            RAM8(0x0297) = value23;
            RAM8(0x0276)++;
            if (RAM8(0x0276) == 0) {
                RAM8(0x0277)++;
            }
            RAM8(0x0298) = 8;
            uint8_t a_hi3 = a_hi2;
            uint8_t y2 = y1;
            for (;;) {
                uint8_t value24 = RAM8(0x0297);
                RAM8(0x0297) <<= 1;
                uint8_t a2;
                if (!(value24 & 0x80)) {
                    a2 = RAM8(0x0296);
                } else {
                    uint8_t value26 = BUS8_RDL(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276), RAM8(0x0278));
                    RAM8(0x0276)++;
                    if (RAM8(0x0276) == 0) {
                        RAM8(0x0277)++;
                    }
                    a2 = value26;
                }
                RAM8(0x0296) = RAM8(0x0295);
                RAM8(0x0295) = a2;
                BUS8_SET(c, (RAM8(0x027E) << 0x10) + RAM16(0x027C) + y2, a2);
                RAM16_SET(0x0274, (uint16_t)(RAM16(0x0274) - 1));
                if (RAM16(0x0274) != 0) {
                    uint8_t value28 = RAM8(0x0272);
                    uint8_t y3;
                    if ((uint8_t)(y2 + 1) != value28) {
                        y3 = (uint8_t)(y2 + 1);
                    } else {
                        uint8_t value29 = RAM8(0x027C);
                        RAM8(0x027C) = (uint8_t)(value29 + 0x40);
                        RAM8(0x027D) = (uint8_t)(RAM8(0x027D) + (value29 + 0x40 > 0xFF));
                        y3 = 0;
                    }
                    RAM8(0x0298)--;
                    if (RAM8(0x0298) != 0) {
                        y2 = y3;
                        continue;
                    }
                    y2 = y3;
                    break;
                }
                a_hi2 = a_hi3;
                y1 = y2;
                goto leave_loop_C21DBB;
            }
            a_hi2 = a_hi3;
            y1 = y2;
        }
        leave_loop_C21DBB:;
        r->a = (a_hi2 << 8) | (uint8_t)a;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    }
    RAM8(0x0276)++;
    if (RAM8(0x0276) == 0) {
        RAM8(0x0277)++;
    }
    uint8_t a_hi4 = a_all2 >> 8;
    for (;;) {
        uint8_t a_hi5 = a_hi4;
        uint8_t y4 = 0;
        for (;;) {
            uint8_t value31 = BUS8_RDL(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276), RAM8(0x0278));
            RAM8(0x0276)++;
            if (RAM8(0x0276) == 0) {
                RAM8(0x0277)++;
            }
            BUS8_SET(c, (RAM8(0x027E) << 0x10) + RAM16(0x027C) + y4, value31);
            RAM16_SET(0x0274, (uint16_t)(RAM16(0x0274) - 1));
            if (RAM16(0x0274) != 0) {
                if ((uint8_t)(y4 + 1) != RAM8(0x0272)) {
                    y4 = (uint8_t)(y4 + 1);
                    continue;
                }
                y4 = (uint8_t)(y4 + 1);
                break;
            }
            a_hi4 = a_hi5;
            goto leave_loop_C21D88;
        }
        uint8_t value33 = RAM8(0x027C);
        RAM8(0x027C) = (uint8_t)(value33 + 0x40);
        RAM8(0x027D) = (uint8_t)(RAM8(0x027D) + (value33 + 0x40 > 0xFF));
        a_hi4 = a_hi5;
    }
    leave_loop_C21D88:;
    r->a = (a_hi4 << 8) | (uint8_t)a;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21CCF, SOM_RTS, "gen", decode_boss_animation_background_block_to_tilemap, 0, L_B, 1, 0, 1, 311, 150)
