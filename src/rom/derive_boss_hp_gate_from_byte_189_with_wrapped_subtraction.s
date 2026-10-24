; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-parent.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3372
derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction:
    lda a:$0189,X
    .a16
    and #$00FF
    sta $95
    .a16
    lda #$0064
    sec
    sbc $95
    lsr
    sta a:$002D,X
    rts
