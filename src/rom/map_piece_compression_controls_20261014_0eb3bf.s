.setcpu "65816"
.segment "CODE"
.org $B3BF
map_control_0eb3bf:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
