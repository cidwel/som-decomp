; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

clear_spell_target_low_status_bit = $992D

.segment "CODE"
.org $9FBD
clear_spell_status_and_mark_reciprocal_contacts:
    jsr clear_spell_target_low_status_bit
    ldy a:$00B2,X
    lda a:$00B0,X
    sec
    .a16
    sbc #$E600
    lsr
    xba
    tax
    sep #$20
    lda f:$C205F0,X
    ora a:$0059,Y
    sta a:$0059,Y
    rep #$20
    ldx $87
    lda a:$00B2,X
    sec
    .a16
    sbc #$E000
    lsr
    xba
    tax
    ldy $87
    sep #$20
    lda f:$C205F0,X
    ora a:$005A,Y
    sta a:$005A,Y
    rep #$20
    rts
