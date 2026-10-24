.setcpu "65816"
.segment "CODE"
.org $EEE7
map_control_0eeee7:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
