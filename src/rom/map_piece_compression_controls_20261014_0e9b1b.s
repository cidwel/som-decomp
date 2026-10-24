.setcpu "65816"
.segment "CODE"
.org $9B1B
map_control_0e9b1b:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
