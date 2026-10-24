.setcpu "65816"
.segment "CODE"
.org $73B4
map_control_0d73b4:
    .byte $E8 ; backreference distance high bits
    .byte $73 ; distance low bit/count
