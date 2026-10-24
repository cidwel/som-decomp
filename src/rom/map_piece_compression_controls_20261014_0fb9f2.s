.setcpu "65816"
.segment "CODE"
.org $B9F2
map_control_0fb9f2:
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
