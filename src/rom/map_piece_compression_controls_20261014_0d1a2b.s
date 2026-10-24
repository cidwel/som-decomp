.setcpu "65816"
.segment "CODE"
.org $1A2B
map_control_0d1a2b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
