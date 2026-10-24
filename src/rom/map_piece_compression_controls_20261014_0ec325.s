.setcpu "65816"
.segment "CODE"
.org $C325
map_control_0ec325:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
