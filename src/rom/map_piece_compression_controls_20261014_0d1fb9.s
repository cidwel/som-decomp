.setcpu "65816"
.segment "CODE"
.org $1FB9
map_control_0d1fb9:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
