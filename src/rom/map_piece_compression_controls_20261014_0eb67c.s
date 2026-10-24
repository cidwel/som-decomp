.setcpu "65816"
.segment "CODE"
.org $B67C
map_control_0eb67c:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
