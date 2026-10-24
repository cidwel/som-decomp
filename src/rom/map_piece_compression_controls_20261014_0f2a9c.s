.setcpu "65816"
.segment "CODE"
.org $2A9C
map_control_0f2a9c:
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
