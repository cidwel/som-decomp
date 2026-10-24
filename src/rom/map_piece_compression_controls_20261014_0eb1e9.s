.setcpu "65816"
.segment "CODE"
.org $B1E9
map_control_0eb1e9:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
