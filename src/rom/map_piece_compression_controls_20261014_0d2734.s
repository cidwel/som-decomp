.setcpu "65816"
.segment "CODE"
.org $2734
map_control_0d2734:
    .byte $E8 ; backreference distance high bits
    .byte $B1 ; distance low bit/count
