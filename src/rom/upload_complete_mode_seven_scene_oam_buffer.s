; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $46C5
upload_complete_mode_seven_scene_oam_buffer:
    stz a:$2102
    stz a:$2103
    .a8
    lda #$00
    sta a:$4300
    .a8
    lda #$04
    sta a:$4301
    .i16
    ldx #$15E0
    stx a:$4302
    stz a:$4304
    .i16
    ldx #$0220
    stx a:$4305
    .a8
    lda #$01
    sta a:$420B
    rtl
