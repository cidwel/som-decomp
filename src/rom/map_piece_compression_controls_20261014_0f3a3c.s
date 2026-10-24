.setcpu "65816"
.segment "CODE"
.org $3A3C
map_control_0f3a3c:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
