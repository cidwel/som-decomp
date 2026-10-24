; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8566
compute_scene_attribute_scroll_weights_with_multiplier:
    sep #$10
    rep #$20
    lda $F6
    .a16
    and #$03FC
    sta $F6
    .a16
    eor #$03FF
    lsr
    lsr
    sep #$20
    sta a:$4202
    .a8
    lda #$E0
    sta a:$4203
    nop
    nop
    nop
    nop
    lda a:$4217
    sta $BC
    .a8
    lda #$A0
    sta a:$4203
    nop
    nop
    nop
    nop
    lda a:$4217
    sta $BD
    rts
