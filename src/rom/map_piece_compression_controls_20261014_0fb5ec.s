.setcpu "65816"
.segment "CODE"
.org $B5EC
map_control_0fb5ec:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
