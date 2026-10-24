.setcpu "65816"
.segment "CODE"
.org $6DB4
map_control_0d6db4:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
