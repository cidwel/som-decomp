.setcpu "65816"
.segment "CODE"
.org $18C9
map_control_0d18c9:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
