#include "som_c.h"
#include "som_hand_d.h"

/* C75CDC sum_native_save_payload_bytes_into_sixteen_bit_checksum   [class A, 36 bytes, 16 instructions]
 * Source: src/rom/sum_native_save_payload_bytes_into_sixteen_bit_checksum.s
 * Documented in docs/ui-native-loaded-game-save-validation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYV.
 */
static void sum_native_save_payload_bytes_into_sixteen_bit_checksum(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_phx(c);
    i_rep(r, 0x20);
    a_lda(r, 0x02B8);
    RAM16_SET(0xA171, r->a); /* bytes left */
    RAM16_SET(0xA173, 0); /* checksum */
    do {
        a_lda(r, BUS16(c, (0x306003 + r->x) & 0xFFFFFF)); /* payload in SRAM; the word read touches the next byte as well */
        if (c->fail) return;
        a_and(r, 0x00FF);
        r->c = 0;
        a_adc(r, RAM16(0xA173));
        RAM16_SET(0xA173, r->a);
        i_inx(r);
        RAM16_SET(0xA171, m_dec(r, RAM16(0xA171)));
    } while (!r->z);
    i_sep(r, 0x20);
    i_plx(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75CDC, SOM_RTS, "hand", sum_native_save_payload_bytes_into_sixteen_bit_checksum, 0, L_X | L_Y | L_V, 2, 1, 0, 36, 16)
