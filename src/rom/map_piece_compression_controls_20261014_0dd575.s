.setcpu "65816"
.segment "CODE"
.org $D575
map_control_0dd575:
    .byte $E8 ; backreference distance high bits
    .byte $62 ; distance low bit/count
