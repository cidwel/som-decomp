.setcpu "65816"
.segment "CODE"
.org $798E
map_control_0c798e:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
