.setcpu "65816"
.segment "CODE"
.org $3868
map_control_0f3868:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
