#include "som_c.h"

/* C00844 collapse_dialogue_window_corner_pairs   [class B, 90 bytes, 32 instructions]
 * Source: src/rom/collapse_dialogue_window_corner_pairs.s
 * Documented in docs/event-dialogue-window-close.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void collapse_dialogue_window_corner_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA157) = RAM8(0xA166);
    uint8_t value2 = RAM8(0xA165);
    RAM8(0xA156) = value2;
    r->a = (a_hi << 8) | value2;
    JSR(c, 0x0852, 0xC00B36); /* erase_window_tile_pair_and_adjacent_right_pair */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM8(0xA166)++;
    RAM8(0xA164)--;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    bool carry3;
    bool zero4;
    bool negative4;
    bool overflow3;
    if (RAM8(0xA164) == 0) {
        RAM8(0xA15E)++;
        a3 = (uint8_t)a_all;
        a_hi3 = a_all >> 8;
        x3 = x_ret;
        y3 = y_ret;
        carry3 = carry_ret;
        zero4 = RAM8(0xA15E) == 0;
        negative4 = RAM8(0xA15E) & 0x80;
        overflow3 = overflow_ret;
    } else {
        uint8_t value3 = RAM8(0xA168);
        RAM8(0xA157) = value3;
        RAM8(0xA156)--;
        r->a = (a_all >> 8 << 8) | value3;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x0866, 0xC00B1D); /* erase_window_tile_pair_and_adjacent_left_pair */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        RAM8(0xA168)--;
        RAM8(0xA164)--;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool zero3;
        bool negative3;
        bool overflow2;
        if (RAM8(0xA164) == 0) {
            RAM8(0xA15E)++;
            a2 = (uint8_t)a_all2;
            a_hi2 = a_all2 >> 8;
            x2 = x_ret2;
            y2 = y_ret2;
            carry2 = carry_ret2;
            zero3 = RAM8(0xA15E) == 0;
            negative3 = RAM8(0xA15E) & 0x80;
            overflow2 = overflow_ret2;
        } else {
            RAM8(0xA157) = RAM8(0xA166);
            uint8_t value6 = RAM8(0xA165);
            RAM8(0xA156) = value6;
            r->a = (a_all2 >> 8 << 8) | value6;
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0x087D, 0xC00B36); /* erase_window_tile_pair_and_adjacent_right_pair */
            uint16_t a_all3 = r->a;
            uint16_t x_ret3 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            RAM8(0xA166)++;
            RAM8(0xA164)--;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            bool carry1;
            bool zero2;
            bool negative2;
            bool overflow1;
            if (RAM8(0xA164) == 0) {
                RAM8(0xA15E)++;
                a1 = (uint8_t)a_all3;
                a_hi1 = a_all3 >> 8;
                x1 = x_ret3;
                y1 = y_ret3;
                carry1 = carry_ret3;
                zero2 = RAM8(0xA15E) == 0;
                negative2 = RAM8(0xA15E) & 0x80;
                overflow1 = overflow_ret3;
            } else {
                uint8_t value7 = RAM8(0xA168);
                RAM8(0xA157) = value7;
                RAM8(0xA156)--;
                r->a = (a_all3 >> 8 << 8) | value7;
                r->mf = 1;
                r->xf = 0;
                JSR(c, 0x0891, 0xC00B1D); /* erase_window_tile_pair_and_adjacent_left_pair */
                uint16_t a_all4 = r->a;
                uint16_t x_ret4 = r->x;
                uint16_t y_ret4 = r->y;
                bool carry_ret4 = r->c;
                bool overflow_ret4 = r->v;
                RAM8(0xA168)--;
                RAM8(0xA164)--;
                bool zero1;
                bool negative1;
                if (RAM8(0xA164) != 0) {
                    zero1 = RAM8(0xA164) == 0;
                    negative1 = RAM8(0xA164) & 0x80;
                } else {
                    RAM8(0xA15E)++;
                    zero1 = RAM8(0xA15E) == 0;
                    negative1 = RAM8(0xA15E) & 0x80;
                }
                a1 = (uint8_t)a_all4;
                a_hi1 = a_all4 >> 8;
                x1 = x_ret4;
                y1 = y_ret4;
                carry1 = carry_ret4;
                zero2 = zero1;
                negative2 = negative1;
                overflow1 = overflow_ret4;
            }
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            carry2 = carry1;
            zero3 = zero2;
            negative3 = negative2;
            overflow2 = overflow1;
        }
        a3 = a2;
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
        carry3 = carry2;
        zero4 = zero3;
        negative4 = negative3;
        overflow3 = overflow2;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = x3;
    r->y = y3;
    r->c = carry3;
    r->z = zero4;
    r->n = negative4;
    r->v = overflow3;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00844, SOM_RTS, "gen", collapse_dialogue_window_corner_pairs, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 90, 32)
