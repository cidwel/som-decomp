.setcpu "65816"
.segment "CODE"
.org $4BA3
map_control_0d4ba3:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
