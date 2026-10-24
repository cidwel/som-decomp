.setcpu "65816"
.segment "CODE"
.org $16AC
map_control_0c16ac:
    .byte $F2 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
