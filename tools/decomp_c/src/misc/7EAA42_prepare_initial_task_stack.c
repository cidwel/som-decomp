#include "som_c.h"
#include "som_hand.h"

/* 7EAA42 prepare_initial_task_stack   [class B, 53 bytes, 27 instructions]
 * Source: src/boot/prepare_initial_task_stack.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: Y.
 *
 * X is a task record and Y a descriptor.  The record's saved frame (at X + $F7..$FF) is filled with the entry point
 * minus one, the return address $AA21 and the descriptor's bank bytes.  The stores run with DB = $00, so the
 * addresses are bank-0 bus addresses: low RAM is WRAM, everything else is hardware or ROM.
 */
static void prepare_initial_task_stack(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;

    /* PHD, PHP, SEP #$20, PHB, LDA #$00, PHA, PLB */
    RAM8(sp0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = hand_p_byte(r);
    RAM8(sp0 - 3) = r->db;
    RAM8(sp0 - 4) = 0x00;
    r->db = 0x00;

    uint16_t entry, frame_end;
    uint8_t bank;
    BUS16_SET(c, 0x0000FAu + x, 0xAA21);
    BUS16_OK(c, 0x000000u + y, entry);
    BUS16_SET(c, 0x0000F7u + x, (uint16_t)(entry - 1));
    BUS16_OK(c, 0x000004u + y, frame_end);
    BUS16_SET(c, 0x0000FDu + x, (uint16_t)(frame_end - 1));
    BUS8_SET(c, 0x0000FCu + x, 0x7E);
    BUS8_OK(c, 0x000002u + y, bank);
    BUS8_SET(c, 0x0000F9u + x, bank);
    BUS8_SET(c, 0x0000FFu + x, bank);

    r->sp = sp0 - 4;
    hand_plb(c);
    hand_plp(c);
    hand_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAA42, SOM_RTS, "hand", prepare_initial_task_stack, 0, L_Y, 5, 0, 0, 53, 27)
