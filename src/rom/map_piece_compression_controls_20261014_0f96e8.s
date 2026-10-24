.setcpu "65816"
.segment "CODE"
.org $96E8
map_control_0f96e8:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
