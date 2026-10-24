.setcpu "65816"
.segment "CODE"
.org $1B3B
map_control_0d1b3b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
