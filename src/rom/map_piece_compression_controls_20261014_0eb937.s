.setcpu "65816"
.segment "CODE"
.org $B937
map_control_0eb937:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
