; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AFA9
compute_scene_curve_square_over_one_hundred_forty_four:
    sta a:$4202
    sta a:$4203
    nop
    nop
    nop
    nop
    lda a:$4216
    sta a:$4204
    lda a:$4217
    sta a:$4205
    .a8
    lda #$90
    sta a:$4206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda a:$4214
    rts
