.setcpu "65816"
.segment "CODE"
.org $311B
map_control_0e311b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
