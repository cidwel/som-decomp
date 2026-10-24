#include "som_c.h"
#include "som_hand.h"

/* 7EA6B7 select_input_interface_reader   [class C, 72 bytes, hand written]
 * Native boot input layer (code decompressed to 7E:A6B7).  X = 2 * reader index; the byte at $7F:0096 holds the
 * interface flags (bit 6 = a first table of readers is present, bit 7 = a second table is present).
 *
 *   if flags.bit6:  if X < 8:  call the reader at table1[X] ($A60D,X) and return
 *                   else X -= 6 (carry set for the SBC)
 *   if X != 0 and flags.bit7: call the reader at table2[X - 2] ($A6AF,X-2) and return
 *   otherwise the hardware joypad word is the answer: X <= 2 reads $4218,X (auto-joypad result 1 / 2), larger X gives 1.
 *
 * Both tables live in the decompressed code image and are read at run time.  PHD/PHP at the entry and PLP/PLD at the
 * exit are real stack bytes.  Entry: M=16, X=16 bit (the routine sets M=8 for the flag test), DB=$7F.
 */
static void select_input_interface_reader(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    RAM8(sp0) = r->dp >> 8; /* PHD */
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = (r->n << 7) | (r->v << 6) | (r->mf << 5) | (r->xf << 4) | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c; /* PHP */
    r->sp -= 3;
    r->mf = 1; /* REP #$30 / SEP #$20 */
    r->xf = 0;
    a_lda(r, RAM8(0x10096)); /* interface flags */
    a_biti(r, 0x40);
    if (!r->z) {
        a_cpx(r, 0x0008);
        if (!r->c) { /* X < 8 */
            JSR(c, 0xA6CB, 0x7E0000 | RAM16(0xA60D + r->x)); /* reader table 1 */
            goto done;
        }
        r->c = 1; /* SEC */
        r->mf = 0;
        r->a = r->x; /* TXA */
        zn(r, r->a, 0);
        a_sbc(r, 6);
        r->x = r->a; /* TAX */
        zn(r, r->x, 0);
        r->mf = 1;
    }
    a_cpx(r, 0x0000);
    if (!r->z) {
        a_biti(r, 0x80);
        if (!r->z) {
            r->x = (uint16_t)(r->x - 2); /* DEX, DEX */
            zn(r, r->x, 0);
            JSR(c, 0xA6E5, 0x7E0000 | RAM16(0xA6AF + r->x)); /* reader table 2 */
            goto done;
        }
    }
    r->mf = 0; /* REP #$20 */
    a_cpx(r, 0x0002);
    if (r->z || r->c) {
        if (r->z) a_lda(r, BUS16(c, 0x004218 + r->x)); /* joypad result of port X/2 */
        else a_lda(r, 1);
    } else {
        a_lda(r, BUS16(c, 0x004218 + r->x));
    }
    r->mf = 1; /* SEP #$20 */
done:
    r->sp += 3;
    som_pull_p(c, sp0 - 2); /* PLP */
    r->dp = RAM8(sp0 - 1) | (RAM8(sp0) << 8); /* PLD */
    r->z = r->dp == 0;
    r->n = r->dp & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA6B7, SOM_RTS, "hand", select_input_interface_reader, 0, L_ALL, 16, 0, 0, 72, 38)
