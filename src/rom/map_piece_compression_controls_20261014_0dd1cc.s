.setcpu "65816"
.segment "CODE"
.org $D1CC
map_control_0dd1cc:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
