; Recovered Secret of Mana USA routine; behaviour documented in docs/audio-native-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

expand_local_audio_preset_and_send_four_byte_request = $29D2

.segment "CODE"
.org $1BA5
preserve_accumulator_byte_and_request_fixed_local_audio_presets:
    pha
    .a8
    lda #$06
    bra preserve_accumulator_byte_and_request_fixed_local_audio_presets_c01bb2
    pha
    .a8
    lda #$04
    bra preserve_accumulator_byte_and_request_fixed_local_audio_presets_c01bb2
    pha
    .a8
    lda #$05
preserve_accumulator_byte_and_request_fixed_local_audio_presets_c01bb2:
    jsr expand_local_audio_preset_and_send_four_byte_request
    pla
    rts
