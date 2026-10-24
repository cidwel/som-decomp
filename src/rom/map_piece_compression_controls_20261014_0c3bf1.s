.setcpu "65816"
.segment "CODE"
.org $3BF1
map_control_0c3bf1:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
