.setcpu "65816"
.segment "CODE"
.org $213B
map_control_0e213b:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
