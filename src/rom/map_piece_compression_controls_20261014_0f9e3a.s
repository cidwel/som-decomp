.setcpu "65816"
.segment "CODE"
.org $9E3A
map_control_0f9e3a:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
