.setcpu "65816"
.segment "CODE"
.org $B6A1
map_control_0eb6a1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
