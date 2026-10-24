; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-labels.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $66BF
derive_native_selected_actor_field_offset:
    rep #$20
    lda f:$0019FE
    .a16
    and #$00FF
    xba
    asl
    sta a:$A173
    lda a:$A175
    .a16
    and #$00FF
    clc
    adc a:$A173
    adc a:$A171
    tax
    .a16
    lda #$0000
    sep #$20
    rts
