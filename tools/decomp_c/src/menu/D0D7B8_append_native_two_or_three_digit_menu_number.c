#include "som_c.h"
#include "som_hand_b.h"

/* D0D7B8 append_native_two_or_three_digit_menu_number   [class C, 83 bytes, 39 instructions]
 * Source: src/rom/append_native_two_or_three_digit_menu_number.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
/* Flag effects of the memory-test instructions on the 8-bit accumulator. */
static void tsb_1802(SomCtx *c, uint8_t mask)
{
    uint8_t *ram = c->wram;
    c->cpu.z = (RAM8(0x1802) & mask) == 0;
    RAM8(0x1802) |= mask;
}

/* D0D7FD: turn the digit in A into a character at the text pointer X (a blank for a leading zero). */
static void write_digit_character(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    r->mf = 1; /* SEP #$20 */
    i_pha(c);
    hand_lda8(r, 0x10);
    uint8_t state = RAM8(0x1802);
    r->z = (state & 0x10) == 0; /* BIT $1802 also copies bits 7 and 6 into N and V */
    r->n = state >> 7;
    r->v = (state >> 6) & 1;
    uint8_t digit = RAM8(r->sp + 1);
    if ((state & 0x10) == 0) {
        hand_lda8(r, digit);
        if (digit != 0) {
            hand_lda8(r, 0x10);
            tsb_1802(c, 0x10); /* the first non-zero digit ends the leading-zero run */
        } else {
            hand_lda8(r, 0x80);
            RAM8(r->sp + 1) = 0x80;
        }
    } else {
        hand_lda8(r, digit);
    }
    i_pla(c);
    r->z = (r->a & 0x80) == 0; /* BIT #$80 */
    uint8_t character = (uint8_t)r->a;
    if ((character & 0x80) == 0) {
        r->c = 0;
        character = hand_adc8(r, character, 0xB5);
    }
    BUS8_SET(c, (uint16_t)(r->dp + r->x), character);
    r->x++;
    hand_nz16(r, r->x);
}

/* D0D7F9: divide Y by A through the hardware divider and write the quotient digit. */
static void divide_and_write_digit(SomCtx *c, uint16_t return_pc)
{
    Cpu *r = &c->cpu;
    push16(c, return_pc); /* JSR D7F9 */
    JSL(c, 0xD7FC, 0xD0D7E2); /* divide_menu_number_using_snes_arithmetic_registers */
    if (c->unwound) return;
    write_digit_character(c);
    r->sp += 2; /* RTS */
}

static void append_native_two_or_three_digit_menu_number(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->y = r->a; /* TAY */
    hand_nz16(r, r->y);
    r->mf = 1; /* SEP #$20 */
    hand_lda8(r, 0x10);
    tsb_1802(c, 0x10);
    uint8_t category = RAM8(0x1809);
    hand_lda8(r, category);
    hand_cmp16(r, category, 1);
    if (category != 1) {
        hand_lda8(r, 0x10);
        r->z = (RAM8(0x1802) & 0x10) == 0; /* TRB $1802 */
        RAM8(0x1802) &= (uint8_t)~0x10;
        hand_lda8(r, 0x64);
        divide_and_write_digit(c, 0xD7D0);
        if (c->fail || c->unwound) return;
    }
    r->mf = 1; /* SEP #$20 */
    hand_lda8(r, 0x0A);
    divide_and_write_digit(c, 0xD7D7);
    if (c->fail || c->unwound) return;
    hand_lda8(r, 0x10);
    tsb_1802(c, 0x10);
    hand_lda8(r, BUS8(c, 0x004216)); /* the remainder is the last digit */
    write_digit_character(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D7B8, SOM_RTS, "hand", append_native_two_or_three_digit_menu_number, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 106, 39)
