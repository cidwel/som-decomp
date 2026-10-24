.setcpu "65816"
.segment "CODE"
.org $404A
map_control_0d404a:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
