; Typed dialogue table; docs/ui-native-dialogue-dispatch-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1A36
native_dialogue_window_transfer_vram_words:
    .word $65A0, $6700, $6980, $6B00
