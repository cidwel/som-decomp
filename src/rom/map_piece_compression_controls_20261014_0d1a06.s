.setcpu "65816"
.segment "CODE"
.org $1A06
map_control_0d1a06:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
