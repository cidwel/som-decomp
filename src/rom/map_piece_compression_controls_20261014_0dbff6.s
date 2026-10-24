.setcpu "65816"
.segment "CODE"
.org $BFF6
map_control_0dbff6:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $F1 ; progressive-copy count
