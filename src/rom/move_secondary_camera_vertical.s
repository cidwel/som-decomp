; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DC99
move_secondary_camera_vertical:
    sep #$30
    lda $B9
    bne move_secondary_camera_vertical_c0dca0
    rts
move_secondary_camera_vertical_c0dca0:
    lda $86
    bmi move_secondary_camera_vertical_c0dcbf
    rep #$20
    .a16
    and #$000F
    pha
    clc
    adc $AE
    cmp $C6
    bcc move_secondary_camera_vertical_c0dcb3
    sbc $C6
move_secondary_camera_vertical_c0dcb3:
    sta $AE
    pla
    clc
    adc $B6
    .a16
    and #$01FF
    sta $B6
    rts
move_secondary_camera_vertical_c0dcbf:
    rep #$20
    .a16
    and #$000F
    sta $00
    lda $B6
    sec
    sbc $00
    .a16
    and #$01FF
    sta $B6
    lda $AE
    sec
    sbc $00
    bcs move_secondary_camera_vertical_c0dcd9
    adc $C6
move_secondary_camera_vertical_c0dcd9:
    sta $AE
    rts
