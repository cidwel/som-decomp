#include "som_c.h"

/* C1D5C0 advance_actor_animation_low_command_pointer   [class C, 819 bytes, 410 instructions]
 * Source: src/rom/advance_actor_animation_low_command_pointer.s
 * Documented in docs/actor-animation-operands.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void advance_actor_animation_low_command_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    RAM8(0x0000 + sp0) = a;
    uint16_t value = RAM16(0x0000);
    RAM16_SET(0x0000, (uint16_t)(value + 1));
    if (a < 0x8F) {
        if (a >= 0x88) {
            if (a != 0x88) {
                if (a >= 0x8D) {
                    if (a != 0x8D) {
                        r->a = (r->a & 0x00FF) | (((uint16_t)(value + 1) >> 8) << 8);
                        r->c = a >= 0x8D;
                        RETURN_RTL(c);
                    }
                    RAM8(0xE047 + x) = 0;
                    RAM8(0x000C) = RAM8(0xE069 + x);
                    if (0) {
                        if (0) {
                            if (1) {
                                if (0) {
                                    uint8_t value3 = RAM8(0x005C);
                                    uint8_t a4;
                                    bool carry2;
                                    if (!(value3 & 0x80)) {
                                        uint8_t value4 = RAM8(0x000C);
                                        RAM8(0x0000 + sp0) = value4;
                                        RAM8(0xE103 + x) = value4 & 0x0F;
                                        uint8_t value5 = RAM8(0x0000 + sp0);
                                        RAM8(0xE101 + x) = value5 >> 4;
                                        uint8_t value6 = RAM8(0xE103 + x);
                                        uint8_t a1;
                                        if (value5 >> 4 >= value6) {
                                            a1 = value5 >> 4;
                                        } else {
                                            a1 = 0xA0;
                                        }
                                        a4 = a1;
                                        carry2 = value5 >> 4 >= value6;
                                    } else {
                                        uint8_t a3;
                                        bool carry1;
                                        if (x < 0x0600) {
                                            uint8_t value7 = RAM8(0x000C);
                                            RAM8(0x0000 + sp0) = value7;
                                            RAM8(0xE103 + x) = value7 & 0x0F;
                                            uint8_t value8 = RAM8(0x0000 + sp0);
                                            RAM8(0xE101 + x) = value8 >> 4;
                                            uint8_t value9 = RAM8(0xE103 + x);
                                            uint8_t a2;
                                            if (value8 >> 4 >= value9) {
                                                a2 = value8 >> 4;
                                            } else {
                                                a2 = 0xA0;
                                            }
                                            a3 = a2;
                                            carry1 = value8 >> 4 >= value9;
                                        } else {
                                            RAM8(0xE101 + x) = RAM8(0x000C);
                                            a3 = 0xB4;
                                            carry1 = x >= 0x0600;
                                        }
                                        a4 = a3;
                                        carry2 = carry1;
                                    }
                                    RAM8(0xE100 + x) = a4;
                                    r->a = ((uint16_t)(value + 1) >> 8 << 8) | a4;
                                    r->c = carry2;
                                    r->v = value3 & 0x40;
                                    RETURN_RTL(c);
                                }
                                if (1) {
                                    uint8_t a6;
                                    if (1) {
                                        a6 = 0x0F;
                                    } else {
                                        uint8_t a5;
                                        if (1) {
                                            a5 = 0;
                                        } else {
                                            a5 = 0x0F;
                                        }
                                        a6 = a5;
                                    }
                                    RAM8(0x00E7) = a6;
                                    uint8_t value11 = RAM8(0x000C);
                                    RAM8(0x00E4) = value11;
                                    RAM8(0x00E5) = value11;
                                    RAM8(0x00E2) |= 1;
                                    r->a = ((uint16_t)(value + 1) >> 8 << 8) | 1;
                                    r->c = 1;
                                    RETURN_RTL(c);
                                }
                                RAM8(0x1057) = RAM8(0x000C);
                                RAM8(0x1058) = RAM8(0x00E6);
                                RAM8(0x00E2) |= 4;
                                r->a = ((uint16_t)(value + 1) >> 8 << 8) | 4;
                                r->c = 1;
                                RETURN_RTL(c);
                            }
                            if (1) {
                                RAM8(0xE104 + x) = 0;
                                r->a = ((uint16_t)(value + 1) >> 8 << 8) | RAM8(0x000C);
                                r->c = 1;
                                { const uint16_t sp_call = r->sp; JSR(c, 0xD749, 0xC1859B); GUARD_JSR(c, sp_call, 0xD749); } /* copy_object_weapon_palette */
                                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                                RETURN_RTL(c);
                            }
                            if (1) {
                                uint8_t value17 = RAM8(0x000C);
                                RAM8(0xE069 + x) = value17;
                                RAM8(0xE104 + x) = 0;
                                r->a = ((uint16_t)(value + 1) >> 8 << 8) | value17;
                                r->c = 1;
                                { const uint16_t sp_call = r->sp; JSR(c, 0xD739, 0xC1859B); GUARD_JSR(c, sp_call, 0xD739); } /* copy_object_weapon_palette */
                                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                                RETURN_RTL(c);
                            }
                            uint8_t value18 = RAM8(0x005C);
                            if (!(value18 & 0x80)) {
                                RAM8(0xE100 + x) = 0;
                                { const uint16_t sp_call = r->sp; JSR(c, 0xD740, 0xC1D90D); GUARD_JSR(c, sp_call, 0xD740); } /* load_actor_fifteen_palette_colors_from_rom */
                                r->mf = 0;
                                r->xf = 0;
                                RETURN_RTL(c);
                            }
                            if (x < 0x0600) {
                                RAM8(0xE100 + x) = 0;
                                { const uint16_t sp_call = r->sp; JSR(c, 0xD740, 0xC1D90D); GUARD_JSR(c, sp_call, 0xD740); } /* load_actor_fifteen_palette_colors_from_rom */
                                r->mf = 0;
                                r->xf = 0;
                                RETURN_RTL(c);
                            }
                            RAM8(0xE100 + x) = 0xC0;
                            RAM8(0xE102 + x) = 0xC0;
                            uint8_t value19 = RAM8(0x000C);
                            RAM8(0xE101 + x) = value19;
                            RAM8(0xE103 + x) = value19;
                            r->a = ((uint16_t)(value + 1) >> 8 << 8) | value19;
                            r->c = x >= 0x0600;
                            r->v = value18 & 0x40;
                            RETURN_RTL(c);
                        }
                        if (1) {
                            if (1) {
                                if (1) {
                                    r->a = ((uint16_t)(value + 1) >> 8 << 8) | 0xC0;
                                    r->c = 1;
                                    RETURN_RTL(c);
                                }
                                uint8_t value20 = RAM8(0x000C);
                                RAM8(0x0049) = value20;
                                r->a = ((uint16_t)(value + 1) >> 8 << 8) | value20;
                                r->c = 1;
                                RETURN_RTL(c);
                            }
                            if (1) {
                                uint8_t a8;
                                bool carry3;
                                if (1) {
                                    a8 = 0xC0;
                                    carry3 = 1;
                                } else {
                                    uint8_t value21 = RAM8(0x000C);
                                    RAM8(0x0000 + sp0) = value21;
                                    RAM8(0xE107 + x) = (uint8_t)((value21 & 0x0F) - 1);
                                    uint8_t value22 = RAM8(0x0000 + sp0);
                                    RAM8(0xE105 + x) = value22 >> 4;
                                    uint8_t value23 = RAM8(0xE107 + x);
                                    uint8_t a7;
                                    if (value22 >> 4 >= value23) {
                                        a7 = value22 >> 4;
                                    } else {
                                        a7 = 0xA0;
                                    }
                                    RAM8(0xE104 + x) = a7;
                                    a8 = a7;
                                    carry3 = value22 >> 4 >= value23;
                                }
                                r->a = ((uint16_t)(value + 1) >> 8 << 8) | a8;
                                r->c = carry3;
                                RETURN_RTL(c);
                            }
                            uint8_t value24 = RAM8(0x000C);
                            RAM8(0xE047 + x) = (uint8_t)(value24 << 4);
                            r->a = ((uint16_t)(value + 1) >> 8 << 8) | (uint8_t)(value24 << 4);
                            r->c = (uint8_t)(value24 << 3) & 0x80;
                            RETURN_RTL(c);
                        }
                        r->a = ((uint16_t)(value + 1) >> 8 << 8) | 0xC0;
                        r->c = 1;
                        RETURN_RTL(c);
                    }
                    if (0) {
                        if (0) {
                            r->a = ((uint16_t)(value + 1) >> 8 << 8) | 0xC0;
                            r->c = 0;
                            RETURN_RTL(c);
                        }
                        if (1) {
                            if (0) {
                                if (1) {
                                    r->a = ((uint16_t)(value + 1) >> 8 << 8) | 0xC0;
                                    r->c = 0;
                                    RETURN_RTL(c);
                                }
                                uint16_t value25 = RAM16(0xE05E + x);
                                uint8_t value26 = RAM8(0xE060 + value25);
                                if (value26 == 0) {
                                    RAM16_SET(0xE002 + value25, RAM16(0xE002 + x));
                                    RAM16_SET(0xE004 + value25, RAM16(0xE004 + x));
                                    RAM16_SET(0xE006 + value25, 0);
                                    RAM8(0xE011 + value25) = RAM8(0x000C);
                                    RAM8(0xE01C + value25) = 0x40;
                                    RAM8(0xE064 + value25) = 0x80;
                                    RAM8(0xE030 + value25) = 0xFF;
                                    r->a = 0xFF;
                                    r->y = value25;
                                    r->c = 0;
                                    RETURN_RTL(c);
                                }
                                if (value26 != 0x40) {
                                    r->a = ((uint16_t)(value + 1) >> 8 << 8) | value26;
                                    r->y = value25;
                                    r->c = value26 >= 0x40;
                                    RETURN_RTL(c);
                                }
                                RAM16_SET(0xE002 + value25, RAM16(0xE002 + x));
                                RAM16_SET(0xE004 + value25, RAM16(0xE004 + x));
                                RAM16_SET(0xE006 + value25, 0);
                                RAM8(0xE011 + value25) = RAM8(0x000C);
                                RAM8(0xE01C + value25) = 0x40;
                                RAM8(0xE064 + value25) = 0x80;
                                RAM8(0xE030 + value25) = 0xFF;
                                r->a = 0xFF;
                                r->y = value25;
                                r->c = value26 >= 0x40;
                                RETURN_RTL(c);
                            }
                            if (0) {
                                uint8_t value33 = RAM8(0x000C);
                                RAM8(0xE008 + x) = value33;
                                r->a = ((uint16_t)(value + 1) >> 8 << 8) | value33;
                                r->c = 0;
                                RETURN_RTL(c);
                            }
                            uint8_t value34 = RAM8(0x000C);
                            uint8_t a_hi1;
                            if (!(value34 & 0x80)) {
                                a_hi1 = (uint16_t)(value + 1) >> 8;
                            } else {
                                uint8_t a9;
                                if (((uint8_t)((value34 ^ 0xFF) + 1) | 0x80) != 0x80) {
                                    a9 = (uint8_t)((value34 ^ 0xFF) + 1) | 0x80;
                                } else {
                                    a9 = 0;
                                }
                                RAM8(0x000C) = a9;
                                a_hi1 = a9;
                            }
                            if (1) {
                                uint8_t value35 = RAM8(0xE010 + x);
                                uint8_t value36 = RAM8(0x000C);
                                uint8_t a10;
                                if (((value35 & 0x80) ^ value36) != 0x80) {
                                    a10 = (value35 & 0x80) ^ value36;
                                } else {
                                    a10 = 0;
                                }
                                RAM8(0xE006 + x) = a10;
                                r->a = (a_hi1 << 8) | a10;
                                r->c = ((value35 & 0x80) ^ value36) >= 0x80;
                                r->v = value34 & 0x40;
                                RETURN_RTL(c);
                            }
                            uint8_t value37 = RAM8(0x000C);
                            RAM8(0xE007 + x) = value37;
                            r->a = (a_hi1 << 8) | value37;
                            r->c = 0;
                            r->v = value34 & 0x40;
                            RETURN_RTL(c);
                        }
                        RAM8(0x000F) = RAM8(0xE010 + x) & 0x80;
                        uint8_t value39 = RAM8(0x000C);
                        uint8_t a11;
                        if ((value39 & 0x0F) < 8) {
                            a11 = value39 & 0x0F;
                        } else {
                            a11 = (uint8_t)(((value39 & 0x0F) ^ 0x87) + 1) & 0x87;
                        }
                        uint8_t value40 = RAM8(0x000F);
                        uint8_t a12;
                        if ((a11 ^ value40) != 0x80) {
                            a12 = a11 ^ value40;
                        } else {
                            a12 = 0;
                        }
                        RAM8(0xE006 + x) = a12;
                        uint8_t value41 = RAM8(0x000C);
                        uint8_t a13;
                        if (value41 >> 4 < 8) {
                            a13 = value41 >> 4;
                        } else {
                            a13 = (uint8_t)(((value41 >> 4) ^ 0x87) + 1) & 0x87;
                        }
                        uint8_t a14;
                        if (a13 != 0x80) {
                            a14 = a13;
                        } else {
                            a14 = 0;
                        }
                        RAM8(0xE007 + x) = a14;
                        r->a = ((uint16_t)(value + 1) >> 8 << 8) | a14;
                        r->c = a13 >= 0x80;
                        RETURN_RTL(c);
                    }
                    if (0) {
                        uint8_t value42 = RAM8(0x005C);
                        if (!(value42 & 0x80)) {
                            RAM8(0x0000 + sp0) = 0xC0;
                            RAM8(0xE102 + x) = (uint8_t)(RAM8(0x000C) + 1);
                            uint8_t value44 = RAM8(0x000C);
                            RAM8(0xE101 + x) = value44;
                            RAM8(0xE103 + x) = (uint8_t)(value44 + 1);
                            RAM8(0xE100 + x) = ((RAM8(0x0000 + sp0) & 4) >> 2) | 0x80;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xD83A, 0xC1D90D); GUARD_JSR(c, sp_call, 0xD83A); } /* load_actor_fifteen_palette_colors_from_rom */
                            r->mf = 0;
                            r->xf = 0;
                            RETURN_RTL(c);
                        }
                        if (x < 0x0600) {
                            RAM8(0x0000 + sp0) = 0xC0;
                            RAM8(0xE102 + x) = (uint8_t)(RAM8(0x000C) + 1);
                            uint8_t value47 = RAM8(0x000C);
                            RAM8(0xE101 + x) = value47;
                            RAM8(0xE103 + x) = (uint8_t)(value47 + 1);
                            RAM8(0xE100 + x) = ((RAM8(0x0000 + sp0) & 4) >> 2) | 0x80;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xD83A, 0xC1D90D); GUARD_JSR(c, sp_call, 0xD83A); } /* load_actor_fifteen_palette_colors_from_rom */
                            r->mf = 0;
                            r->xf = 0;
                            RETURN_RTL(c);
                        }
                        RAM8(0xE100 + x) = 0xC0;
                        uint8_t value49 = RAM8(0x000C);
                        RAM8(0xE101 + x) = value49;
                        r->a = ((uint16_t)(value + 1) >> 8 << 8) | value49;
                        r->c = x >= 0x0600;
                        r->v = value42 & 0x40;
                        RETURN_RTL(c);
                    }
                    RAM8(0x0000 + sp0) = 0xC0;
                    uint8_t value50 = RAM8(0x000C);
                    RAM8(0xE106 + x) = (uint8_t)(value50 + 1);
                    uint8_t value51 = RAM8(0x000C);
                    RAM8(0xE105 + x) = value51;
                    RAM8(0xE107 + x) = (uint8_t)(value51 + 1);
                    uint8_t value52 = RAM8(0x0000 + sp0);
                    RAM8(0xE104 + x) = ((value52 & 4) >> 2) | 0x80;
                    RAM8(0xE047 + x) = 0;
                    r->a = ((uint16_t)(value + 1) >> 8 << 8) | RAM8(0x000C);
                    r->c = (value52 & 4) >> 1 & 0x01;
                    r->v = (((uint8_t)(value50 + 1) ^ 1) & (value50 ^ (uint8_t)(value50 + 1)) & 0x80) != 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD807, 0xC1859B); GUARD_JSR(c, sp_call, 0xD807); } /* copy_object_weapon_palette */
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTL(c);
                }
                if (a >= 0x8A) {
                    if (a != 0x8A) {
                        if (a != 0x8B) {
                            RAM8(0x0049) = 0x60;
                            r->a = ((uint16_t)(value + 1) >> 8 << 8) | 0x60;
                            r->c = a >= 0x8B;
                            RETURN_RTL(c);
                        }
                        RAM8(0x0049) = 0xE0;
                        r->a = ((uint16_t)(value + 1) >> 8 << 8) | 0xE0;
                        r->c = a >= 0x8B;
                        RETURN_RTL(c);
                    }
                    RAM8(0x0049) = 0;
                    r->a = (r->a & 0x00FF) | (((uint16_t)(value + 1) >> 8) << 8);
                    r->c = a >= 0x8A;
                    RETURN_RTL(c);
                }
                RAM8(0xE000 + x) = 0;
                RAM8(0xE043 + x) = 0;
                r->a = (r->a & 0x00FF) | (((uint16_t)(value + 1) >> 8) << 8);
                r->c = a >= 0x8A;
                RETURN_RTL(c);
            }
            uint8_t value54 = RAM8(0xE00E + x);
            RAM8(0xE00E + x) = value54 & 0x0F;
            r->a = (uint16_t)(value + 1) >> 8 << 8 | (value54 & 0x0F);
            r->c = a >= 0x88;
            RETURN_RTL(c);
        }
        if (a >= 0x84) {
            if (a >= 0x86) {
                uint8_t a15;
                if (a != 0x86) {
                    a15 = 0x20;
                } else {
                    a15 = 0x40;
                }
                uint8_t value55 = RAM8(0xE00E + x);
                RAM8(0xE00E + x) = a15 | value55;
                r->a = ((uint16_t)(value + 1) >> 8 << 8) | (a15 | value55);
                r->c = a >= 0x86;
                RETURN_RTL(c);
            }
            RAM8(0xE00E + x) = (uint8_t)(a - 0x83) ^ 3 | RAM8(0xE00E + x);
            RAM8(0xE039 + x) = 0x10;
            r->a = ((uint16_t)(value + 1) >> 8 << 8) | 0x10;
            r->c = a >= 0x83;
            r->v = ((a ^ 0x83) & (a ^ (uint8_t)(a - 0x83)) & 0x80) != 0;
            RETURN_RTL(c);
        }
        if (a >= 0x82) {
            RAM8(0xE104 + x) = 0;
            r->a = ((uint16_t)(value + 1) >> 8 << 8) | RAM8(0xE069 + x);
            r->c = a >= 0x82;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD61F, 0xC1859B); GUARD_JSR(c, sp_call, 0xD61F); } /* copy_object_weapon_palette */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        if (a != 0x80) {
            RAM8(0x0000 + sp0) = x >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
            uint16_t value58 = RAM16(0xE1E3 + x);
            RAM16_SET(0x000C, (value58 & 0xFF) << 1 << 1);
            uint16_t value59 = RAM16(0x000C);
            uint8_t value60 = BUS8(c, 0xD01004 + (uint16_t)(((value58 & 0xFF) << 1 << 1 << 1 << 1) - value59));
            RAM8(0xE069 + x) = value60;
            RAM8(0xE104 + x) = 0;
            r->a = ((uint16_t)(((value58 & 0xFF) << 1 << 1 << 1 << 1) - value59) >> 8 << 8) | value60;
            r->c = (value58 & 0xFF) << 1 << 1 << 1 << 1 >= value59;
            r->v = ((((value58 & 0xFF) << 1 << 1 << 1 << 1) ^ value59) & (((value58 & 0xFF) << 1 << 1 << 1 << 1) ^ (uint16_t)(((value58 & 0xFF) << 1 << 1 << 1 << 1) - value59)) & 0x8000) != 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD611, 0xC1859B); GUARD_JSR(c, sp_call, 0xD611); } /* copy_object_weapon_palette */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        uint8_t value61 = RAM8(0x005C);
        if (!(value61 & 0x80)) {
            r->c = a >= 0x80;
            r->v = value61 & 0x40;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD615, 0xC1D8F3); GUARD_JSR(c, sp_call, 0xD615); } /* restore_actor_cached_fifteen_palette_colors */
            r->mf = 0;
            r->xf = 0;
            RETURN_RTL(c);
        }
        if (x < 0x0600) {
            r->c = x >= 0x0600;
            r->v = value61 & 0x40;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD615, 0xC1D8F3); GUARD_JSR(c, sp_call, 0xD615); } /* restore_actor_cached_fifteen_palette_colors */
            r->mf = 0;
            r->xf = 0;
            RETURN_RTL(c);
        }
        RAM8(0xE100 + x) = a;
        r->a = (r->a & 0x00FF) | (((uint16_t)(value + 1) >> 8) << 8);
        r->c = x >= 0x0600;
        r->v = value61 & 0x40;
        RETURN_RTL(c);
    }
    if (a >= 0xAB) {
        RAM8(0xE036 + x) = (uint8_t)(a - 0xAB);
        RAM8(0xE037 + x) = (uint8_t)(a - 0xAB);
        r->a = ((uint16_t)(value + 1) >> 8 << 8) | (uint8_t)(a - 0xAB);
        r->c = a >= 0xAB;
        r->v = ((a ^ 0xAB) & (a ^ (uint8_t)(a - 0xAB)) & 0x80) != 0;
        RETURN_RTL(c);
    }
    RAM8(0x000F) = RAM8(0xE010 + x) & 0x80;
    uint8_t value63 = RAM8(0xC700 + (((((uint16_t)(value + 1) >> 8 << 8) | (uint8_t)(a - 0x8F)) & 0xFF) << 1 << 1));
    uint8_t a_hi3;
    if (value63 == 0x80) {
        a_hi3 = ((((uint16_t)(value + 1) >> 8 << 8) | (uint8_t)(a - 0x8F)) & 0xFF) << 1 << 1 >> 8;
    } else {
        uint8_t value64 = RAM8(0x000F);
        uint8_t a16;
        if ((value63 ^ value64) != 0x80) {
            a16 = value63 ^ value64;
        } else {
            a16 = 0;
        }
        RAM8(0xE006 + x) = a16;
        uint8_t value65 = RAM8(0xE013 + x);
        uint8_t a_hi2;
        if (value65 == 0) {
            a_hi2 = a16;
        } else {
            uint8_t a18;
            if (a16 == 0) {
                a18 = a16;
            } else {
                uint8_t a17;
                if (!(value65 & 0x80)) {
                    a17 = a16;
                } else {
                    a17 = a16 ^ 0x80;
                }
                a18 = a17;
            }
            RAM8(0xE007 + x) = a18;
            a_hi2 = (uint8_t)(value65 << 1);
        }
        a_hi3 = a_hi2;
    }
    uint8_t value66 = RAM8(0xC701 + (((((uint16_t)(value + 1) >> 8 << 8) | (uint8_t)(a - 0x8F)) & 0xFF) << 1 << 1));
    if (value66 != 0x80) {
        RAM8(0xE007 + x) = value66;
    }
    uint8_t value67 = RAM8(0xC702 + (((((uint16_t)(value + 1) >> 8 << 8) | (uint8_t)(a - 0x8F)) & 0xFF) << 1 << 1));
    if (value67 != 0x80) {
        RAM8(0xE008 + x) = value67;
    }
    r->a = (a_hi3 << 8) | value67;
    r->y = ((((uint16_t)(value + 1) >> 8 << 8) | (uint8_t)(a - 0x8F)) & 0xFF) << 1 << 1;
    r->c = value67 >= 0x80;
    r->v = ((a ^ 0x8F) & (a ^ (uint8_t)(a - 0x8F)) & 0x80) != 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1D5C0, SOM_RTL, "hand", advance_actor_animation_low_command_pointer, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 819, 410)

#include "som_hand_d.h"   /* literal instruction macros for the interior entries below (its JSR / JSL replace the generated forms from here on) */

/* Interior entries of this routine's byte range, called by other routines of the actor script engine (captures replayed on this file through ALIAS_ENTRIES in
 * capset.py):
 *   C1D6DC read_actor_command_byte_parameter_and_advance_script: A = command byte; reads the parameter at [$00]+1 into $0C, advances the low script pointer by 2,
 *                                                                 then continues as C1D6EF.
 *   C1D6EF dispatch_actor_commands_b0_and_above: A = command byte (B0..FF), $0C = its parameter, X = actor slot; commands E0 and up do nothing.
 * Written like the assembly (instruction-exact operations, flags included). */
static void actor_command_b0_and_above(SomCtx *c, int read_parameter)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (!read_parameter) goto L_C1D6EF;
    i_pha(c);
    a_ldy(r, 0x1);
    { uint8_t pv_; LDA_ILY8(c, 0x00, pv_); a_lda(r, pv_); }   /* LDA [$00],Y: an unmapped read returns the pointer's bank byte */
    STA(c, DP, 0x0c);
    i_rep(r, 0x20);
    LDA(c, DP, 0x00);
    i_inca(r);
    i_inca(r);
    STA(c, DP, 0x00);
    i_sep(r, 0x20);
    i_pla(c);
L_C1D6EF:;
    a_cmp(r, 0xc0);
    if (!r->c) goto L_C1D704;
    a_cmp(r, 0xd0);
    if (r->c) goto L_C1D6FA;
    goto L_C1D7DF;
L_C1D6FA:;
    a_cmp(r, 0xe0);
    if (r->c) goto L_C1D701;
    goto L_C1D83C;
L_C1D701:;
    RETURN_RTL(c);
L_C1D704:;
    a_cmp(r, 0xb8);
    if (!r->c) goto L_C1D70B;
    goto L_C1D7A2;
L_C1D70B:;
    a_cmp(r, 0xb4);
    if (r->c) goto L_C1D74B;
    a_cmp(r, 0xb2);
    if (r->c) goto L_C1D742;
    a_cmp(r, 0xb0);
    if (!r->z) goto L_C1D72F;
    BIT(c, DP, 0x5c);
    if (!r->n) goto L_C1D73B;
    a_cpx(r, 0x0600);
    if (!r->c) goto L_C1D73B;
    STA(c, ABX, 0xe100);
    STA(c, ABX, 0xe102);
    LDA(c, DP, 0x0c);
    STA(c, ABX, 0xe101);
    STA(c, ABX, 0xe103);
    RETURN_RTL(c);
L_C1D72F:;
    LDA(c, DP, 0x0c);
    STA(c, ABX, 0xe069);
    STZ(c, ABX, 0xe104);
    JSR(c, 0xd739, 0xC1859B);
    RETURN_RTL(c);
L_C1D73B:;
    STZ(c, ABX, 0xe100);
    JSR(c, 0xd740, 0xC1D90D);
    RETURN_RTL(c);
L_C1D742:;
    STZ(c, ABX, 0xe104);
    LDA(c, DP, 0x0c);
    JSR(c, 0xd749, 0xC1859B);
    RETURN_RTL(c);
L_C1D74B:;
    if (r->z) goto L_C1D760;
    a_cmp(r, 0xb6);
    if (r->c) goto L_C1D78D;
    LDA(c, DP, 0x0c);
    STA(c, ABS, 0x1057);
    LDA(c, DP, 0xe6);
    STA(c, ABS, 0x1058);
    a_lda(r, 0x04);
    TSB(c, DP, 0xe2);
    RETURN_RTL(c);
L_C1D760:;
    BIT(c, DP, 0x5c);
    if (!r->n) goto L_C1D772;
    a_cpx(r, 0x0600);
    if (!r->c) goto L_C1D772;
    LDA(c, DP, 0x0c);
    STA(c, ABX, 0xe101);
    a_lda(r, 0xb4);
    goto L_C1D789;
L_C1D772:;
    LDA(c, DP, 0x0c);
    i_pha(c);
    a_and(r, 0x0f);
    STA(c, ABX, 0xe103);
    i_pla(c);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    STA(c, ABX, 0xe101);
    CMP(c, ABX, 0xe103);
    if (r->c) goto L_C1D789;
    a_lda(r, 0xa0);
L_C1D789:;
    STA(c, ABX, 0xe100);
    RETURN_RTL(c);
L_C1D78D:;
    if (!r->z) goto L_C1D793;
    a_lda(r, 0x00);
    if (r->z) goto L_C1D795;
L_C1D793:;
    a_lda(r, 0x0f);
L_C1D795:;
    STA(c, DP, 0xe7);
    LDA(c, DP, 0x0c);
    STA(c, DP, 0xe4);
    STA(c, DP, 0xe5);
    a_lda(r, 0x01);
    TSB(c, DP, 0xe2);
    RETURN_RTL(c);
L_C1D7A2:;
    a_cmp(r, 0xb8);
    if (!r->z) goto L_C1D7A7;
    RETURN_RTL(c);
L_C1D7A7:;
    a_cmp(r, 0xbc);
    if (r->c) goto L_C1D7D7;
    a_cmp(r, 0xba);
    if (r->c) goto L_C1D7B9;
    LDA(c, DP, 0x0c);
    i_asla(r);
    i_asla(r);
    i_asla(r);
    i_asla(r);
    STA(c, ABX, 0xe047);
    RETURN_RTL(c);
L_C1D7B9:;
    if (!r->z) goto L_C1D7D6;
    LDA(c, DP, 0x0c);
    i_pha(c);
    a_and(r, 0x0f);
    i_deca(r);
    STA(c, ABX, 0xe107);
    i_pla(c);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    STA(c, ABX, 0xe105);
    CMP(c, ABX, 0xe107);
    if (r->c) goto L_C1D7D3;
    a_lda(r, 0xa0);
L_C1D7D3:;
    STA(c, ABX, 0xe104);
L_C1D7D6:;
    RETURN_RTL(c);
L_C1D7D7:;
    if (!r->z) goto L_C1D7DE;
    LDA(c, DP, 0x0c);
    STA(c, DP, 0x49);
    RETURN_RTL(c);
L_C1D7DE:;
    RETURN_RTL(c);
L_C1D7DF:;
    a_cmp(r, 0xc8);
    if (r->c) goto L_C1D809;
    i_pha(c);
    a_and(r, 0x03);
    i_inca(r);
    r->c = 0;
    ADC(c, DP, 0x0c);
    STA(c, ABX, 0xe106);
    LDA(c, DP, 0x0c);
    STA(c, ABX, 0xe105);
    i_inca(r);
    STA(c, ABX, 0xe107);
    i_pla(c);
    a_and(r, 0x04);
    i_lsra(r);
    i_lsra(r);
    a_ora(r, 0x80);
    STA(c, ABX, 0xe104);
    STZ(c, ABX, 0xe047);
    LDA(c, DP, 0x0c);
    JSR(c, 0xd807, 0xC1859B);
    RETURN_RTL(c);
L_C1D809:;
    BIT(c, DP, 0x5c);
    if (!r->n) goto L_C1D81B;
    a_cpx(r, 0x0600);
    if (!r->c) goto L_C1D81B;
    STA(c, ABX, 0xe100);
    LDA(c, DP, 0x0c);
    STA(c, ABX, 0xe101);
    RETURN_RTL(c);
L_C1D81B:;
    i_pha(c);
    a_and(r, 0x03);
    i_inca(r);
    r->c = 0;
    ADC(c, DP, 0x0c);
    STA(c, ABX, 0xe102);
    LDA(c, DP, 0x0c);
    STA(c, ABX, 0xe101);
    i_inca(r);
    STA(c, ABX, 0xe103);
    i_pla(c);
    a_and(r, 0x04);
    i_lsra(r);
    i_lsra(r);
    a_ora(r, 0x80);
    STA(c, ABX, 0xe100);
    JSR(c, 0xd83a, 0xC1D90D);
    RETURN_RTL(c);
L_C1D83C:;
    a_cmp(r, 0xd0);
    if (!r->z) goto L_C1D878;
    LDA(c, ABX, 0xe010);
    a_and(r, 0x80);
    STA(c, DP, 0x0f);
    LDA(c, DP, 0x0c);
    a_and(r, 0x0f);
    a_cmp(r, 0x08);
    if (!r->c) goto L_C1D854;
    a_eor(r, 0x87);
    i_inca(r);
    a_and(r, 0x87);
L_C1D854:;
    EOR(c, DP, 0x0f);
    a_cmp(r, 0x80);
    if (!r->z) goto L_C1D85C;
    a_lda(r, 0x00);
L_C1D85C:;
    STA(c, ABX, 0xe006);
    LDA(c, DP, 0x0c);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    a_cmp(r, 0x08);
    if (!r->c) goto L_C1D86E;
    a_eor(r, 0x87);
    i_inca(r);
    a_and(r, 0x87);
L_C1D86E:;
    a_cmp(r, 0x80);
    if (!r->z) goto L_C1D874;
    a_lda(r, 0x00);
L_C1D874:;
    STA(c, ABX, 0xe007);
    RETURN_RTL(c);
L_C1D878:;
    a_cmp(r, 0xd4);
    if (r->c) goto L_C1D8B8;
    a_cmp(r, 0xd3);
    if (r->z) goto L_C1D8B2;
    i_xba(r);
    i_xba(r);
    BIT(c, DP, 0x0c);
    if (!r->n) goto L_C1D897;
    i_xba(r);
    LDA(c, DP, 0x0c);
    a_eor(r, 0xff);
    i_inca(r);
    a_ora(r, 0x80);
    a_cmp(r, 0x80);
    if (!r->z) goto L_C1D894;
    a_lda(r, 0x00);
L_C1D894:;
    STA(c, DP, 0x0c);
    i_xba(r);
L_C1D897:;
    a_cmp(r, 0xd1);
    if (!r->z) goto L_C1D8A1;
    LDA(c, DP, 0x0c);
    STA(c, ABX, 0xe007);
    RETURN_RTL(c);
L_C1D8A1:;
    LDA(c, ABX, 0xe010);
    a_and(r, 0x80);
    EOR(c, DP, 0x0c);
    a_cmp(r, 0x80);
    if (!r->z) goto L_C1D8AE;
    a_lda(r, 0x00);
L_C1D8AE:;
    STA(c, ABX, 0xe006);
    RETURN_RTL(c);
L_C1D8B2:;
    LDA(c, DP, 0x0c);
    STA(c, ABX, 0xe008);
    RETURN_RTL(c);
L_C1D8B8:;
    if (!r->z) goto L_C1D8F1;
    LDY(c, ABX, 0xe05e);
    LDA(c, ABY, 0xe060);
    if (r->z) goto L_C1D8C6;
    a_cmp(r, 0x40);
    if (!r->z) goto L_C1D8F1;
L_C1D8C6:;
    i_rep(r, 0x20);
    LDA(c, ABX, 0xe002);
    STA(c, ABY, 0xe002);
    LDA(c, ABX, 0xe004);
    STA(c, ABY, 0xe004);
    a_lda(r, 0x0000);
    STA(c, ABY, 0xe006);
    i_sep(r, 0x20);
    LDA(c, DP, 0x0c);
    STA(c, ABY, 0xe011);
    a_lda(r, 0x40);
    STA(c, ABY, 0xe01c);
    a_lda(r, 0x80);
    STA(c, ABY, 0xe064);
    a_lda(r, 0xff);
    STA(c, ABY, 0xe030);
    RETURN_RTL(c);
L_C1D8F1:;
    RETURN_RTL(c);
}

static void read_actor_command_byte_parameter_and_advance_script(SomCtx *c) { actor_command_b0_and_above(c, 1); }
SOM_REGISTER(0xC1D6DC, SOM_RTL, "hand", read_actor_command_byte_parameter_and_advance_script, 0, L_ALL, 2, 1, 0, 535, 270)
static void dispatch_actor_commands_b0_and_above(SomCtx *c) { actor_command_b0_and_above(c, 0); }
SOM_REGISTER(0xC1D6EF, SOM_RTL, "hand", dispatch_actor_commands_b0_and_above, 0, L_ALL, 2, 1, 0, 516, 259)
