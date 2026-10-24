.setcpu "65816"
.segment "CODE"
.org $2A0C
map_control_0d2a0c:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
