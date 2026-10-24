.setcpu "65816"
.segment "CODE"
.org $C154
map_control_0ec154:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
