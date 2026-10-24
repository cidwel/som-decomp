.setcpu "65816"
.segment "CODE"
.org $4CF4
map_control_0d4cf4:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
