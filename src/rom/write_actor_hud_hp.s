; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

write_hud_decimal_number = $E390

.segment "CODE"
.org $E369
write_actor_hud_hp:
    rep #$20
    stz $08
    .a16
    and #$00FF
    .a16
    ora #$5B00
    sec
    .a16
    sbc #$0020
    sta a:$2116
    lda f:$7EE182,X
    jsr write_hud_decimal_number
    .a8
    lda #$12
    sta a:$2118
    dec $08
    stz $09
    rep #$20
    lda f:$7EE184,X
