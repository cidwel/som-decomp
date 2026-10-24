.setcpu "65816"
.segment "CODE"
.org $1342
map_control_0d1342:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
