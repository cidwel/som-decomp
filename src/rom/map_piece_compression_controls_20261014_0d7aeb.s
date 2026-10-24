.setcpu "65816"
.segment "CODE"
.org $7AEB
map_control_0d7aeb:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
