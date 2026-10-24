.setcpu "65816"
.segment "CODE"
.org $6DB5
map_control_0c6db5:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
