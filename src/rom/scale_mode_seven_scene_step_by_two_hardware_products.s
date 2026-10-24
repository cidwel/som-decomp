; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $45D3
scale_mode_seven_scene_step_by_two_hardware_products:
    phx
    lda $33
    sta a:$4202
    lda $30
    sta a:$4203
    nop
    nop
    nop
    rep #$20
    lda a:$4216
    tax
    sep #$20
    lda $31
    sta a:$4203
    nop
    nop
    nop
    stx $30
    lda a:$4216
    clc
    adc $31
    sta $31
    lda a:$4217
    .a8
    adc #$00
    sta $32
    plx
    rts
