.setcpu "65816"
.segment "CODE"
.org $9C1A
map_control_0f9c1a:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
