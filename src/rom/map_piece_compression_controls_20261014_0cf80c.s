.setcpu "65816"
.segment "CODE"
.org $F80C
map_control_0cf80c:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
