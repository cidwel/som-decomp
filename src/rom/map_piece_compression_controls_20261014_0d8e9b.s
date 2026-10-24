.setcpu "65816"
.segment "CODE"
.org $8E9B
map_control_0d8e9b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
