; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16

divide_signed_scene_ratio_with_native_saturation = $4556

.segment "CODE"
.org $44DB
compute_signed_mode_seven_transition_matrix:
    phb
    .a8
    lda #$C6
    pha
    plb
    rep #$20
    lda $44
    .a16
    and #$00FF
    clc
    .a16
    adc #$0012
    .a16
    cmp #$0048
    bcc compute_signed_mode_seven_transition_matrix_c644f3
    .a16
    sbc #$0048
compute_signed_mode_seven_transition_matrix_c644f3:
    asl
    tax
    lda a:$46EA,X
    sta $30
    lda $40
    jsr divide_signed_scene_ratio_with_native_saturation
    sep #$20
    sta f:$00211B
    xba
    sta f:$00211B
    rep #$20
    lda $42
    jsr divide_signed_scene_ratio_with_native_saturation
    sep #$20
    sta f:$00211E
    xba
    sta f:$00211E
    rep #$20
    lda $44
    .a16
    and #$00FF
    asl
    tax
    lda a:$46EA,X
    sta $30
    lda $40
    jsr divide_signed_scene_ratio_with_native_saturation
    sep #$20
    sta f:$00211C
    xba
    sta f:$00211C
    rep #$20
    lda $30
    .a16
    eor #$FFFF
    inc
    sta $30
    lda $42
    jsr divide_signed_scene_ratio_with_native_saturation
    sep #$20
    sta f:$00211D
    xba
    sta f:$00211D
    plb
    rts
