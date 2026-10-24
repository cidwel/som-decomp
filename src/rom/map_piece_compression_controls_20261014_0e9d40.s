.setcpu "65816"
.segment "CODE"
.org $9D40
map_control_0e9d40:
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
