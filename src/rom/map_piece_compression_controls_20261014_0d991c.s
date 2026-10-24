.setcpu "65816"
.segment "CODE"
.org $991C
map_control_0d991c:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
