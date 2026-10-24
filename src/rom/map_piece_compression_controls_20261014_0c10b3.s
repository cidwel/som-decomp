.setcpu "65816"
.segment "CODE"
.org $10B3
map_control_0c10b3:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
