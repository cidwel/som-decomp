.setcpu "65816"
.segment "CODE"
.org $96D4
map_control_0f96d4:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
