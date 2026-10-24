; Typed dialogue table; docs/ui-native-dialogue-dispatch-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1A3E
native_dialogue_window_transfer_byte_counts:
    .word $00C0, $0100, $0100, $00C0
