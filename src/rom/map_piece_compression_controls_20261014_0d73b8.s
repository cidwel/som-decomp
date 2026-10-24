.setcpu "65816"
.segment "CODE"
.org $73B8
map_control_0d73b8:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
