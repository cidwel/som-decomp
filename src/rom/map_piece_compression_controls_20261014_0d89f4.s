.setcpu "65816"
.segment "CODE"
.org $89F4
map_control_0d89f4:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
