; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DC56
move_secondary_camera_horizontal:
    sep #$30
    lda $B9
    bne move_secondary_camera_horizontal_c0dc5d
    rts
move_secondary_camera_horizontal_c0dc5d:
    lda $84
    bmi move_secondary_camera_horizontal_c0dc7c
    rep #$20
    .a16
    and #$000F
    pha
    clc
    adc $AC
    cmp $C4
    bcc move_secondary_camera_horizontal_c0dc70
    sbc $C4
move_secondary_camera_horizontal_c0dc70:
    sta $AC
    pla
    clc
    adc $B4
    .a16
    and #$01FF
    sta $B4
    rts
move_secondary_camera_horizontal_c0dc7c:
    rep #$20
    .a16
    and #$000F
    sta $00
    lda $B4
    sec
    sbc $00
    .a16
    and #$01FF
    sta $B4
    lda $AC
    sec
    sbc $00
    bcs move_secondary_camera_horizontal_c0dc96
    adc $C4
move_secondary_camera_horizontal_c0dc96:
    sta $AC
    rts
