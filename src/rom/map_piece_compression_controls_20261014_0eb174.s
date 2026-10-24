.setcpu "65816"
.segment "CODE"
.org $B174
map_control_0eb174:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
