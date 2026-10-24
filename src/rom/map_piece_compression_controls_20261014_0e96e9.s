.setcpu "65816"
.segment "CODE"
.org $96E9
map_control_0e96e9:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
