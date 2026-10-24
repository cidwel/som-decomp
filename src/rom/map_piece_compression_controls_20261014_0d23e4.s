.setcpu "65816"
.segment "CODE"
.org $23E4
map_control_0d23e4:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
