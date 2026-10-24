; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4556
divide_signed_scene_ratio_with_native_saturation:
    sta $32
    lda $30
    bpl divide_signed_scene_ratio_with_native_saturation_c64560
    .a16
    eor #$FFFF
    inc
divide_signed_scene_ratio_with_native_saturation_c64560:
    sta $36
    stz $34
    .i16
    ldx #$0018
    stz $38
divide_signed_scene_ratio_with_native_saturation_c64569:
    rol $34
    rol $36
    rol $38
    lda $38
    bcc divide_signed_scene_ratio_with_native_saturation_c6457a
    sbc $32
    sta $38
    sec
    bra divide_signed_scene_ratio_with_native_saturation_c64582
divide_signed_scene_ratio_with_native_saturation_c6457a:
    cmp $32
    bcc divide_signed_scene_ratio_with_native_saturation_c64582
    sbc $32
    sta $38
divide_signed_scene_ratio_with_native_saturation_c64582:
    dex
    bne divide_signed_scene_ratio_with_native_saturation_c64569
    lda $30
    bpl divide_signed_scene_ratio_with_native_saturation_c64591
    lda $34
    .a16
    eor #$FFFF
    inc
    bra divide_signed_scene_ratio_with_native_saturation_c6459b
divide_signed_scene_ratio_with_native_saturation_c64591:
    lda $34
    .a16
    cmp #$8000
    bcc divide_signed_scene_ratio_with_native_saturation_c6459b
    .a16
    lda #$7FFF
divide_signed_scene_ratio_with_native_saturation_c6459b:
    rts
