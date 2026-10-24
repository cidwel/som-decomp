.setcpu "65816"
.segment "CODE"
.org $C3E7
map_control_0ec3e7:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
