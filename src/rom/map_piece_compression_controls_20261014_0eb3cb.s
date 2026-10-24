.setcpu "65816"
.segment "CODE"
.org $B3CB
map_control_0eb3cb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
