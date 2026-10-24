.setcpu "65816"
.segment "CODE"
.org $E88D
map_control_0fe88d:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
