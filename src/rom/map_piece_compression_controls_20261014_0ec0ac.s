.setcpu "65816"
.segment "CODE"
.org $C0AC
map_control_0ec0ac:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
