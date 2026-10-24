.setcpu "65816"
.segment "CODE"
.org $2ABF
map_control_0d2abf:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
