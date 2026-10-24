.setcpu "65816"
.segment "CODE"
.org $1A85
map_control_0d1a85:
    .byte $E8 ; backreference distance high bits
    .byte $B6 ; distance low bit/count
