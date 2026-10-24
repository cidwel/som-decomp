.setcpu "65816"
.segment "CODE"
.org $ABF2
map_control_0fabf2:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
