; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $98DA
activate_spell_child_and_clear_fractional_height:
    .a16
    lda #$0001
    sta a:$0000,X
    stz a:$0029,X
    stz a:$0030,X
    stz a:$0064,X
    stz a:$0066,X
    sep #$20
    .a8
    lda #$01
    sta a:$000B,X
    rep #$20
    rts
