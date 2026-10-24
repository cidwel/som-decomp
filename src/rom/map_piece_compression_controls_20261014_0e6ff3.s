.setcpu "65816"
.segment "CODE"
.org $6FF3
map_control_0e6ff3:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
