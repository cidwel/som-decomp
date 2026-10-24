#include "som_c.h"

/* C06C1D shrink_native_ring_until_category_transition_threshold   [class C, 286 bytes, 125 instructions]
 * Source: src/rom/shrink_native_ring_until_category_transition_threshold.s
 * Documented in docs/event-menu-ring-phase.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void shrink_native_ring_until_category_transition_threshold(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    if (a < 0x10) {
        r->c = a >= 0x10;
        r->z = a == 0x10;
        r->n = (uint16_t)(a - 0x10) & 0x8000;
        TAIL_CALL(c, 0xC06E9F, SOM_RTS); /* finish_native_ring_phase_or_rebuild_category_and_animate_palette */
    }
    RAM16_SET(0x181E, (uint16_t)(a + 0xFFF6));
    RAM16_SET(0x186C, RAM16(0x181C));
    RAM16_SET(0x186E, RAM16(0x181E));
    RAM16_SET(0x1824, 0x12);
    RAM16_SET(0x1832, 0x0848);
    uint8_t value3 = RAM8(0x1812);
    uint8_t a2;
    bool carry1;
    bool overflow1;
    if (value3 != 0) {
        RAM8(0x0001 + 0x0838) = 0xE8;
        RAM8(0x0005 + 0x0838) = 0xE8;
        a2 = 0xE8;
        carry1 = a + 0xFFF6 > 0xFFFF;
        overflow1 = ((a ^ (uint16_t)(a + 0xFFF6)) & ((uint16_t)(a + 0xFFF6) ^ 0xFFF6) & 0x8000) != 0;
    } else {
        uint8_t value4 = RAM8(0x1847);
        uint8_t a1;
        if ((uint8_t)(value4 - 1) != 0) {
            a1 = (uint8_t)(RAM8(0x181C) - RAM8(0x186E));
        } else {
            a1 = (uint8_t)(RAM8(0x181C) + RAM8(0x186E));
        }
        RAM8(0x0001 + 0x0838) = (uint8_t)(a1 - 8);
        RAM8(0x0005 + 0x0838) = (uint8_t)(a1 - 8);
        a2 = (uint8_t)((uint8_t)(a1 - 8) + 0x10);
        carry1 = (uint8_t)(a1 - 8) + 0x10 > 0xFF;
        overflow1 = (((uint8_t)(a1 - 8) ^ (uint8_t)((uint8_t)(a1 - 8) + 0x10)) & ((uint8_t)((uint8_t)(a1 - 8) + 0x10) ^ 0x10) & 0x80) != 0;
    }
    RAM8(0x0009 + 0x0838) = a2;
    RAM8(0x000D + 0x0838) = a2;
    if (RAM8(0x1812) != 0) {
        r->y = (uint8_t)y;
        r->c = carry1;
        r->mf = 1;
        r->xf = 1;
        JSR(c, 0x6D18, 0xC06D1C); /* project_and_publish_all_native_menu_ring_rows */
        r->mf = 0;
        r->xf = 0;
        TAIL_CALL(c, 0xC06E9F, SOM_RTS); /* finish_native_ring_phase_or_rebuild_category_and_animate_palette */
    }
    if (RAM8(0x1806) == 0) {
        r->y = (uint8_t)y;
        r->c = carry1;
        r->mf = 1;
        r->xf = 1;
        JSR(c, 0x6D18, 0xC06D1C); /* project_and_publish_all_native_menu_ring_rows */
        r->mf = 0;
        r->xf = 0;
        TAIL_CALL(c, 0xC06E9F, SOM_RTS); /* finish_native_ring_phase_or_rebuild_category_and_animate_palette */
    }
    uint8_t value11 = RAM8(0x1801);
    if ((value11 & 3) != 0) {
        r->y = (uint8_t)y;
        r->c = carry1;
        r->mf = 1;
        r->xf = 1;
        JSR(c, 0x6D18, 0xC06D1C); /* project_and_publish_all_native_menu_ring_rows */
        r->mf = 0;
        r->xf = 0;
        TAIL_CALL(c, 0xC06E9F, SOM_RTS); /* finish_native_ring_phase_or_rebuild_category_and_animate_palette */
    }
    r->a = 8 << 8 | (value11 & 3);
    r->y = (uint8_t)y;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0x6CD2, 0xC06D37); /* choose_next_native_menu_ring_row_with_directional_wrap */
    r->mf = 0; /* rep */
    r->xf = 0;
    uint16_t a_all4 = r->a;
    if (RAM8(0x1806) & 0x80) {
        uint16_t value13 = RAM16(0x0008 + ((a_all4 & 0xFF) << 1 << 1 << 1 << 1) + 0x18C0);
        if ((uint16_t)(value13 + 0x12) < 0x0400) {
            r->c = (uint16_t)(value13 + 0x12) >= 0x0400;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x6D18, 0xC06D1C); /* project_and_publish_all_native_menu_ring_rows */
            r->mf = 0;
            r->xf = 0;
            TAIL_CALL(c, 0xC06E9F, SOM_RTS); /* finish_native_ring_phase_or_rebuild_category_and_animate_palette */
        }
        RAM16_SET(0x1824, (uint16_t)(0x0400 - value13));
        if (RAM8(0x1848) != 0) {
            r->c = value13 <= 0x0400;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x6D59, 0xC06D1C); /* project_and_publish_all_native_menu_ring_rows */
            r->mf = 1; /* sep */
            uint16_t a_all6 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret5 = r->y;
            bool carry_ret6 = r->c;
            bool overflow_ret6 = r->v;
            uint8_t a_hi1 = a_all6 >> 8;
            uint16_t x1 = x_ret6;
            uint16_t y1 = y_ret5;
            bool carry2 = carry_ret6;
            bool overflow2 = overflow_ret6;
            bool first_pass = true;
            for (;;) {
                if (first_pass) {
                    uint8_t value15 = RAM8(0x1848);
                    uint8_t a3;
                    uint8_t a_hi2;
                    uint16_t x2;
                    uint16_t y2;
                    bool carry3;
                    bool zero1;
                    bool negative1;
                    bool overflow3;
                    if (value15 == 0) {
                        a3 = value15;
                        a_hi2 = a_hi1;
                        x2 = x1;
                        y2 = y1;
                        carry3 = carry2;
                        zero1 = value15 == 0;
                        negative1 = value15 & 0x80;
                        overflow3 = overflow2;
                    } else {
                        RAM8(0x1848)--;
                        uint8_t value16 = RAM8(0x1848);
                        r->a = (a_hi1 << 8) | value15;
                        r->x = x1;
                        r->y = y1;
                        r->c = carry2;
                        r->z = value16 == 0;
                        r->n = value16 & 0x80;
                        r->v = overflow2;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0;
                        r->dp = 0;
                        JSR(c, 0x6D66, 0xC0695E); /* wait_vblank_before_polling_native_menu_input */
                        r->mf = 1; /* sep */
                        uint16_t a_all7 = r->a;
                        uint16_t x_ret7 = r->x;
                        uint16_t y_ret6 = r->y;
                        bool carry_ret7 = r->c;
                        bool overflow_ret7 = r->v;
                        uint8_t value17 = RAM8(0x1801);
                        if ((value17 & 3) != 0) {
                            a_hi1 = a_all7 >> 8;
                            x1 = x_ret7;
                            y1 = y_ret6;
                            carry2 = carry_ret7;
                            overflow2 = overflow_ret7;
                            first_pass = false;
                            continue;
                        }
                        RAM8(0x1848) = 0;
                        a3 = value17;
                        a_hi2 = a_all7 >> 8;
                        x2 = x_ret7;
                        y2 = y_ret6;
                        carry3 = carry_ret7;
                        zero1 = (value17 & 3) == 0;
                        negative1 = value17 & 0x80;
                        overflow3 = overflow_ret7;
                    }
                    r->a = (a_hi2 << 8) | a3;
                    r->x = x2;
                    r->y = y2;
                    r->c = carry3;
                    r->z = zero1;
                    r->n = negative1;
                    r->v = overflow3;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0;
                    r->dp = 0;
                    RETURN_RTS(c);
                } else {
                    uint8_t value18 = RAM8(0x1848);
                    uint8_t a4;
                    uint8_t a_hi3;
                    uint16_t x3;
                    uint16_t y3;
                    bool carry4;
                    bool zero2;
                    bool negative2;
                    bool overflow4;
                    if (value18 == 0) {
                        a4 = value18;
                        a_hi3 = a_hi1;
                        x3 = x1;
                        y3 = y1;
                        carry4 = carry2;
                        zero2 = value18 == 0;
                        negative2 = value18 & 0x80;
                        overflow4 = overflow2;
                    } else {
                        RAM8(0x1848)--;
                        uint8_t value19 = RAM8(0x1848);
                        r->a = (a_hi1 << 8) | value18;
                        r->x = x1;
                        r->y = y1;
                        r->c = carry2;
                        r->z = value19 == 0;
                        r->n = value19 & 0x80;
                        r->v = overflow2;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0;
                        r->dp = 0;
                        JSR(c, 0x6D66, 0xC0695E); /* wait_vblank_before_polling_native_menu_input */
                        r->mf = 1; /* sep */
                        uint16_t a_all8 = r->a;
                        uint16_t x_ret8 = r->x;
                        uint16_t y_ret7 = r->y;
                        bool carry_ret8 = r->c;
                        bool overflow_ret8 = r->v;
                        uint8_t value20 = RAM8(0x1801);
                        if ((value20 & 3) != 0) {
                            a_hi1 = a_all8 >> 8;
                            x1 = x_ret8;
                            y1 = y_ret7;
                            carry2 = carry_ret8;
                            overflow2 = overflow_ret8;
                            continue;
                        }
                        RAM8(0x1848) = 0;
                        a4 = value20;
                        a_hi3 = a_all8 >> 8;
                        x3 = x_ret8;
                        y3 = y_ret7;
                        carry4 = carry_ret8;
                        zero2 = (value20 & 3) == 0;
                        negative2 = value20 & 0x80;
                        overflow4 = overflow_ret8;
                    }
                    r->a = (a_hi3 << 8) | a4;
                    r->x = x3;
                    r->y = y3;
                    r->c = carry4;
                    r->z = zero2;
                    r->n = negative2;
                    r->v = overflow4;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
            }
        }
        r->c = value13 <= 0x0400;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x6D18, 0xC06D1C); /* project_and_publish_all_native_menu_ring_rows */
        r->mf = 0;
        r->xf = 0;
        TAIL_CALL(c, 0xC06E9F, SOM_RTS); /* finish_native_ring_phase_or_rebuild_category_and_animate_palette */
    }
    uint16_t value21 = RAM16(0x0008 + ((a_all4 & 0xFF) << 1 << 1 << 1 << 1) + 0x18C0);
    if (((uint16_t)(value21 - 0x12) & 0xFC00) == 0) {
        r->c = value21 >= 0x12;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x6D18, 0xC06D1C); /* project_and_publish_all_native_menu_ring_rows */
        r->mf = 0;
        r->xf = 0;
        TAIL_CALL(c, 0xC06E9F, SOM_RTS); /* finish_native_ring_phase_or_rebuild_category_and_animate_palette */
    }
    RAM16_SET(0x1824, value21);
    if (RAM8(0x1848) != 0) {
        r->c = value21 >= 0x12;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x6D59, 0xC06D1C); /* project_and_publish_all_native_menu_ring_rows */
        r->mf = 1; /* sep */
        uint16_t a_all11 = r->a;
        uint16_t x_ret11 = r->x;
        uint16_t y_ret10 = r->y;
        bool carry_ret11 = r->c;
        bool overflow_ret11 = r->v;
        uint8_t a_hi4 = a_all11 >> 8;
        uint16_t x4 = x_ret11;
        uint16_t y4 = y_ret10;
        bool carry5 = carry_ret11;
        bool overflow5 = overflow_ret11;
        bool first_pass2 = true;
        for (;;) {
            if (first_pass2) {
                uint8_t value23 = RAM8(0x1848);
                uint8_t a5;
                uint8_t a_hi5;
                uint16_t x5;
                uint16_t y5;
                bool carry6;
                bool zero3;
                bool negative3;
                bool overflow6;
                if (value23 == 0) {
                    a5 = value23;
                    a_hi5 = a_hi4;
                    x5 = x4;
                    y5 = y4;
                    carry6 = carry5;
                    zero3 = value23 == 0;
                    negative3 = value23 & 0x80;
                    overflow6 = overflow5;
                } else {
                    RAM8(0x1848)--;
                    uint8_t value24 = RAM8(0x1848);
                    r->a = (a_hi4 << 8) | value23;
                    r->x = x4;
                    r->y = y4;
                    r->c = carry5;
                    r->z = value24 == 0;
                    r->n = value24 & 0x80;
                    r->v = overflow5;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0;
                    r->dp = 0;
                    JSR(c, 0x6D66, 0xC0695E); /* wait_vblank_before_polling_native_menu_input */
                    r->mf = 1; /* sep */
                    uint16_t a_all12 = r->a;
                    uint16_t x_ret12 = r->x;
                    uint16_t y_ret11 = r->y;
                    bool carry_ret12 = r->c;
                    bool overflow_ret12 = r->v;
                    uint8_t value25 = RAM8(0x1801);
                    if ((value25 & 3) != 0) {
                        a_hi4 = a_all12 >> 8;
                        x4 = x_ret12;
                        y4 = y_ret11;
                        carry5 = carry_ret12;
                        overflow5 = overflow_ret12;
                        first_pass2 = false;
                        continue;
                    }
                    RAM8(0x1848) = 0;
                    a5 = value25;
                    a_hi5 = a_all12 >> 8;
                    x5 = x_ret12;
                    y5 = y_ret11;
                    carry6 = carry_ret12;
                    zero3 = (value25 & 3) == 0;
                    negative3 = value25 & 0x80;
                    overflow6 = overflow_ret12;
                }
                r->a = (a_hi5 << 8) | a5;
                r->x = x5;
                r->y = y5;
                r->c = carry6;
                r->z = zero3;
                r->n = negative3;
                r->v = overflow6;
                r->mf = 1;
                r->xf = 0;
                r->db = 0;
                r->dp = 0;
                RETURN_RTS(c);
            } else {
                uint8_t value26 = RAM8(0x1848);
                uint8_t a6;
                uint8_t a_hi6;
                uint16_t x6;
                uint16_t y6;
                bool carry7;
                bool zero4;
                bool negative4;
                bool overflow7;
                if (value26 == 0) {
                    a6 = value26;
                    a_hi6 = a_hi4;
                    x6 = x4;
                    y6 = y4;
                    carry7 = carry5;
                    zero4 = value26 == 0;
                    negative4 = value26 & 0x80;
                    overflow7 = overflow5;
                } else {
                    RAM8(0x1848)--;
                    uint8_t value27 = RAM8(0x1848);
                    r->a = (a_hi4 << 8) | value26;
                    r->x = x4;
                    r->y = y4;
                    r->c = carry5;
                    r->z = value27 == 0;
                    r->n = value27 & 0x80;
                    r->v = overflow5;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0;
                    r->dp = 0;
                    JSR(c, 0x6D66, 0xC0695E); /* wait_vblank_before_polling_native_menu_input */
                    r->mf = 1; /* sep */
                    uint16_t a_all13 = r->a;
                    uint16_t x_ret13 = r->x;
                    uint16_t y_ret12 = r->y;
                    bool carry_ret13 = r->c;
                    bool overflow_ret13 = r->v;
                    uint8_t value28 = RAM8(0x1801);
                    if ((value28 & 3) != 0) {
                        a_hi4 = a_all13 >> 8;
                        x4 = x_ret13;
                        y4 = y_ret12;
                        carry5 = carry_ret13;
                        overflow5 = overflow_ret13;
                        continue;
                    }
                    RAM8(0x1848) = 0;
                    a6 = value28;
                    a_hi6 = a_all13 >> 8;
                    x6 = x_ret13;
                    y6 = y_ret12;
                    carry7 = carry_ret13;
                    zero4 = (value28 & 3) == 0;
                    negative4 = value28 & 0x80;
                    overflow7 = overflow_ret13;
                }
                r->a = (a_hi6 << 8) | a6;
                r->x = x6;
                r->y = y6;
                r->c = carry7;
                r->z = zero4;
                r->n = negative4;
                r->v = overflow7;
                r->mf = 1;
                r->xf = 0;
                r->db = 0;
                r->dp = 0;
                RETURN_RTS(c);
            }
        }
    }
    r->c = value21 >= 0x12;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x6D18, 0xC06D1C); /* project_and_publish_all_native_menu_ring_rows */
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL(c, 0xC06E9F, SOM_RTS); /* finish_native_ring_phase_or_rebuild_category_and_animate_palette */
}
SOM_REGISTER(0xC06C1D, SOM_RTS, "hand", shrink_native_ring_until_category_transition_threshold, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 343, 125)
