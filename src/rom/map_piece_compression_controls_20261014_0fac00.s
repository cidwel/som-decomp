.setcpu "65816"
.segment "CODE"
.org $AC00
map_control_0fac00:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
