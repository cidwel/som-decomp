.setcpu "65816"
.segment "CODE"
.org $1790
map_control_0d1790:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
