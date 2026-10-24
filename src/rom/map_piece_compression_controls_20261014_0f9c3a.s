.setcpu "65816"
.segment "CODE"
.org $9C3A
map_control_0f9c3a:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
