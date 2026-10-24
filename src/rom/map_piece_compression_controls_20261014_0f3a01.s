.setcpu "65816"
.segment "CODE"
.org $3A01
map_control_0f3a01:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
