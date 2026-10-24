.setcpu "65816"
.segment "CODE"
.org $2740
map_control_0d2740:
    .byte $E8 ; backreference distance high bits
    .byte $B1 ; distance low bit/count
