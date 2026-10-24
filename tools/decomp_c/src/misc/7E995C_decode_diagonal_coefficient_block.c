#include "som_c.h"

/* 7E995C decode_diagonal_coefficient_block   [class B, 328 bytes, 133 instructions]
 * Source: src/boot/decode_diagonal_coefficient_block.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$00 D=any.  Callers read: AYCV.
 */
static void decode_diagonal_coefficient_block(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    RAM16_SET(0x0000 + dp, a);
    JSR(c, 0x9960, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all = r->a;
    uint16_t value = RAM16(0x0000 + dp);
    RAM16_SET(0x0000 + dp, (uint16_t)(a_all + value));
    r->a = (uint16_t)(a_all + value);
    r->c = a_all + value > 0xFFFF;
    r->z = (uint16_t)(a_all + value) == 0;
    r->n = (uint16_t)(a_all + value) & 0x8000;
    r->v = ((a_all ^ (uint16_t)(a_all + value)) & (value ^ (uint16_t)(a_all + value)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9968, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all2 = r->a;
    RAM16_SET(0x0002 + dp, a_all2);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x996D, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all3 = r->a;
    RAM16_SET(0x0010 + dp, a_all3);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9972, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all4 = r->a;
    RAM16_SET(0x0020 + dp, a_all4);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9977, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all5 = r->a;
    RAM16_SET(0x0012 + dp, a_all5);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x997C, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all6 = r->a;
    RAM16_SET(0x0004 + dp, a_all6);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9981, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all7 = r->a;
    RAM16_SET(0x0006 + dp, a_all7);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9986, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all8 = r->a;
    RAM16_SET(0x0014 + dp, a_all8);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x998B, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all9 = r->a;
    RAM16_SET(0x0022 + dp, a_all9);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9990, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all10 = r->a;
    RAM16_SET(0x0030 + dp, a_all10);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9995, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all11 = r->a;
    RAM16_SET(0x0040 + dp, a_all11);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x999A, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all12 = r->a;
    RAM16_SET(0x0032 + dp, a_all12);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x999F, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all13 = r->a;
    RAM16_SET(0x0024 + dp, a_all13);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99A4, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all14 = r->a;
    RAM16_SET(0x0016 + dp, a_all14);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99A9, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all15 = r->a;
    RAM16_SET(0x0008 + dp, a_all15);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99AE, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all16 = r->a;
    RAM16_SET(0x000A + dp, a_all16);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99B3, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all17 = r->a;
    RAM16_SET(0x0018 + dp, a_all17);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99B8, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all18 = r->a;
    RAM16_SET(0x0026 + dp, a_all18);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99BD, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all19 = r->a;
    RAM16_SET(0x0034 + dp, a_all19);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99C2, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all20 = r->a;
    RAM16_SET(0x0042 + dp, a_all20);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99C7, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all21 = r->a;
    RAM16_SET(0x0050 + dp, a_all21);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99CC, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all22 = r->a;
    RAM16_SET(0x0060 + dp, a_all22);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99D1, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all23 = r->a;
    RAM16_SET(0x0052 + dp, a_all23);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99D6, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all24 = r->a;
    RAM16_SET(0x0044 + dp, a_all24);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99DB, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all25 = r->a;
    RAM16_SET(0x0036 + dp, a_all25);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99E0, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all26 = r->a;
    RAM16_SET(0x0028 + dp, a_all26);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99E5, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all27 = r->a;
    RAM16_SET(0x001A + dp, a_all27);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99EA, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all28 = r->a;
    RAM16_SET(0x000C + dp, a_all28);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99EF, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all29 = r->a;
    RAM16_SET(0x000E + dp, a_all29);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99F4, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all30 = r->a;
    RAM16_SET(0x001C + dp, a_all30);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99F9, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all31 = r->a;
    RAM16_SET(0x002A + dp, a_all31);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x99FE, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all32 = r->a;
    RAM16_SET(0x0038 + dp, a_all32);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A03, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all33 = r->a;
    RAM16_SET(0x0046 + dp, a_all33);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A08, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all34 = r->a;
    RAM16_SET(0x0054 + dp, a_all34);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A0D, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all35 = r->a;
    RAM16_SET(0x0062 + dp, a_all35);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A12, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all36 = r->a;
    RAM16_SET(0x0070 + dp, a_all36);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A17, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all37 = r->a;
    RAM16_SET(0x0072 + dp, a_all37);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A1C, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all38 = r->a;
    RAM16_SET(0x0064 + dp, a_all38);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A21, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all39 = r->a;
    RAM16_SET(0x0056 + dp, a_all39);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A26, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all40 = r->a;
    RAM16_SET(0x0048 + dp, a_all40);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A2B, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all41 = r->a;
    RAM16_SET(0x003A + dp, a_all41);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A30, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all42 = r->a;
    RAM16_SET(0x002C + dp, a_all42);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A35, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all43 = r->a;
    RAM16_SET(0x001E + dp, a_all43);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A3A, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all44 = r->a;
    RAM16_SET(0x002E + dp, a_all44);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A3F, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all45 = r->a;
    RAM16_SET(0x003C + dp, a_all45);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A44, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all46 = r->a;
    RAM16_SET(0x004A + dp, a_all46);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A49, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all47 = r->a;
    RAM16_SET(0x0058 + dp, a_all47);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A4E, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all48 = r->a;
    RAM16_SET(0x0066 + dp, a_all48);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A53, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all49 = r->a;
    RAM16_SET(0x0074 + dp, a_all49);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A58, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all50 = r->a;
    RAM16_SET(0x0076 + dp, a_all50);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A5D, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all51 = r->a;
    RAM16_SET(0x0068 + dp, a_all51);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A62, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all52 = r->a;
    RAM16_SET(0x005A + dp, a_all52);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A67, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all53 = r->a;
    RAM16_SET(0x004C + dp, a_all53);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A6C, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all54 = r->a;
    RAM16_SET(0x003E + dp, a_all54);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A71, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all55 = r->a;
    RAM16_SET(0x004E + dp, a_all55);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A76, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all56 = r->a;
    RAM16_SET(0x005C + dp, a_all56);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A7B, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all57 = r->a;
    RAM16_SET(0x006A + dp, a_all57);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A80, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all58 = r->a;
    RAM16_SET(0x0078 + dp, a_all58);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A85, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all59 = r->a;
    RAM16_SET(0x007A + dp, a_all59);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A8A, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all60 = r->a;
    RAM16_SET(0x006C + dp, a_all60);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A8F, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all61 = r->a;
    RAM16_SET(0x005E + dp, a_all61);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A94, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all62 = r->a;
    RAM16_SET(0x006E + dp, a_all62);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A99, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all63 = r->a;
    RAM16_SET(0x007C + dp, a_all63);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A9E, 0x7EA1A7); /* decode_signed_delta_or_zero_run */
    uint16_t a_all64 = r->a;
    RAM16_SET(0x007E + dp, a_all64);
    r->a = RAM16(0x0000 + dp);
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E995C, SOM_RTS, "gen", decode_diagonal_coefficient_block, 0, L_A | L_Y | L_C | L_V, 1, 0, 0, 328, 133)
