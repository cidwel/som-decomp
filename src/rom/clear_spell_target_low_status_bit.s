; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $992D
clear_spell_target_low_status_bit:
    ldy a:$00B2,X
    sep #$20
    .a8
    lda #$FE
    and a:$0190,Y
    sta a:$0190,Y
    rep #$20
    rts
