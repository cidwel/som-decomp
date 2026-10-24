.setcpu "65816"
.segment "CODE"
.org $C7F8
map_control_0dc7f8:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
