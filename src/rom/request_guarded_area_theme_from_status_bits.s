; Recovered Secret of Mana USA routine; behaviour documented in docs/audio-native-callers.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $A914
request_guarded_area_theme_from_status_bits:
    sep #$20
    lda $8C
    bne request_guarded_area_theme_from_status_bits_c2a942
    rep #$10
    bit $E3
    bmi request_guarded_area_theme_from_status_bits_c2a932
    bvs request_guarded_area_theme_from_status_bits_c2a92a
    .i16
    ldx #$0101
    .i16
    ldy #$FF09
    bra request_guarded_area_theme_from_status_bits_c2a938
request_guarded_area_theme_from_status_bits_c2a92a:
    .i16
    ldx #$0301
    .i16
    ldy #$FF0B
    bra request_guarded_area_theme_from_status_bits_c2a938
request_guarded_area_theme_from_status_bits_c2a932:
    .i16
    ldx #$0201
    .i16
    ldy #$FF0D
request_guarded_area_theme_from_status_bits_c2a938:
    stx a:$1E00
    sty a:$1E02
    jsl f:audio_command_sender_public_jump
request_guarded_area_theme_from_status_bits_c2a942:
    rtl
