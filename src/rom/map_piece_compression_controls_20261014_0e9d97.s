.setcpu "65816"
.segment "CODE"
.org $9D97
map_control_0e9d97:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
