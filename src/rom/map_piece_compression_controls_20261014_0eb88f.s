.setcpu "65816"
.segment "CODE"
.org $B88F
map_control_0eb88f:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
