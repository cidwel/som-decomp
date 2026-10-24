#include "som_c.h"

/* 7EA4E9 detect_controller_interface   [class B, 138 bytes, 71 instructions]
 * Source: src/boot/detect_controller_interface.s
 * Documented in docs/boot.md
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: BYCV.
 *
 * Sets D to $4000 so that the byte offsets $16/$17 address the joypad ports $4016/$4017, strobes the port and
 * samples bit 1 of both ports up to eight times each, builds a two-bit result on the stack, shifts it into
 * bits 5-7 and, when it differs from the stored value at $0096 and $0097 is non-zero, queues a record.
 */

/* One polling loop: reads `port` up to eight times until bit 1 is clear; returns the last value masked with 2. */
static uint8_t poll_port_bit1(SomCtx *c, uint16_t port, uint16_t *y)
{
    uint8_t a;
    *y = 8;
    for (;;) {
        a = BUS8(c, port) & 2;
        if (a == 0) break;
        if (--*y == 0) break;
    }
    return a;
}

static void detect_controller_interface(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t entry_dp = r->dp;
    const uint16_t entry_a = r->a;

    /* PHD, PHP, REP #$30, SEP #$20 */
    RAM8(sp0) = entry_dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)entry_dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    const uint16_t slot = (uint16_t)(sp0 - 3); /* the PHA slot used for the result */
    r->sp = slot;
    r->mf = 1;
    r->xf = 0;

    /* LDA #$40, XBA, LDA #$00, TCD: D = $4000 (the joypad ports) */
    r->dp = 0x4000;
    BUS8_SET(c, 0x004201, 0xFF);
    BUS8_SET(c, 0x004016, 0xFF);

    uint16_t y;
    uint8_t a = poll_port_bit1(c, 0x4016, &y);
    uint8_t result = a;                                  /* PHA */
    a = poll_port_bit1(c, 0x4017, &y);
    result |= (uint8_t)(a << 1);
    BUS8_SET(c, 0x004016, 0);                            /* STZ $16 */
    a = poll_port_bit1(c, 0x4016, &y);
    if (a != 0) result &= (uint8_t)~a;                   /* the loop ran out: EOR #$FF, AND $01,S */
    a = poll_port_bit1(c, 0x4017, &y);
    if (a != 0) result &= (uint8_t)~(uint8_t)(a << 1);

    /* PLA, five ASLs, CMP $0096 */
    const uint8_t mask = (uint8_t)(result << 5);
    uint8_t a_hi = 0x40;
    const uint32_t flag_addr = ((uint32_t)r->db << 16) | 0x0096;
    const uint8_t stored = BUS8(c, flag_addr);
    uint8_t pending = 0;
    if (mask != stored) {
        BUS8_SET(c, flag_addr, mask);
        pending = BUS8(c, flag_addr + 1);
    }
    if (pending != 0) {
        r->a = (uint16_t)((a_hi << 8) | pending);
        r->y = y;
        r->c = mask >= stored;
        r->z = 0;
        r->n = pending & 0x80;
        r->sp = slot;
        JSR(c, 0xA557, 0x7EB1A9); /* allocate_eight_byte_record */
        const uint32_t record_bank = (uint32_t)r->db << 16;
        const uint16_t record = r->x;
        BUS8_SET(c, record_bank + 2 + record, 0xFE);
        BUS8_SET(c, record_bank + 4 + record, 3);
        BUS8_SET(c, record_bank + 5 + record, RAM8((uint16_t)(sp0 - 2))); /* LDA $01,S: the saved status byte */
        const uint8_t id = BUS8(c, record_bank + 0x97);
        r->a = (uint16_t)((r->a & 0xFF00) | id);
        r->z = id == 0;
        r->n = id & 0x80;
        JSR(c, 0xA56C, 0x7EB258); /* append_pending_record */
        a_hi = r->a >> 8;
        y = r->xf ? (uint8_t)r->y : r->y;
        if (!r->mf) a_hi = BUS16(c, ((uint32_t)r->db << 16) | 0x0096) >> 8; /* LDA $0096 in the width the callee left */
    }

    /* PLP, PLD, RTS */
    hand_plp(c);
    hand_pld(c);
    r->a = (uint16_t)((a_hi << 8) | (entry_a & 0xFF));
    r->y = y;
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA4E9, SOM_RTS, "hand", detect_controller_interface, 0, L_B | L_Y | L_C | L_V, 4, -1, 0, 138, 71)
