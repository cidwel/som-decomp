; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0CE0
set_boss_animation_bank_low_byte_c7:
    sep #$20
    .a8
    lda #$C7
    sta a:$00A2,X
    rep #$20
    rts
