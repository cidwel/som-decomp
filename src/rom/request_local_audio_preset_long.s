; Recovered Secret of Mana USA routine; behaviour documented in docs/audio-native-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

expand_local_audio_preset_and_send_four_byte_request = $29D2

.segment "CODE"
.org $2B02
request_local_audio_preset_long:
    jsr expand_local_audio_preset_and_send_four_byte_request
    rtl
