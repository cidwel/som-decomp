.setcpu "65816"
.segment "CODE"
.org $4C01
map_control_0d4c01:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
