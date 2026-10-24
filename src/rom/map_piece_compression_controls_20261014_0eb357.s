.setcpu "65816"
.segment "CODE"
.org $B357
map_control_0eb357:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
