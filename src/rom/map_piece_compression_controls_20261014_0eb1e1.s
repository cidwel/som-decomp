.setcpu "65816"
.segment "CODE"
.org $B1E1
map_control_0eb1e1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
