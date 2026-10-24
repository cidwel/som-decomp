.setcpu "65816"
.segment "CODE"
.org $2A2A
map_control_0d2a2a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
