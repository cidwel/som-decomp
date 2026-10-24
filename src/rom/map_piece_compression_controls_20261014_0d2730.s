.setcpu "65816"
.segment "CODE"
.org $2730
map_control_0d2730:
    .byte $E8 ; backreference distance high bits
    .byte $B1 ; distance low bit/count
