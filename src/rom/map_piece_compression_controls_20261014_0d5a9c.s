.setcpu "65816"
.segment "CODE"
.org $5A9C
map_control_0d5a9c:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
