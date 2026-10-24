.setcpu "65816"
.segment "CODE"
.org $96A2
map_control_0f96a2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
