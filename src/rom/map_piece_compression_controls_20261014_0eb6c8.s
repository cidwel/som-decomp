.setcpu "65816"
.segment "CODE"
.org $B6C8
map_control_0eb6c8:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
