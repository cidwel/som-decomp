.setcpu "65816"
.segment "CODE"
.org $CE44
map_control_0fce44:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
