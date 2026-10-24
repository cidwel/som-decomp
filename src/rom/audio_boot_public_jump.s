; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-audio-boot.md.
.setcpu "65816"
.smart
.a8
.i16

upload_six_spc_blocks_or_reset_ready_audio_metadata = $002C

.segment "CODE"
.org $0000
audio_boot_public_jump:
    jmp upload_six_spc_blocks_or_reset_ready_audio_metadata
