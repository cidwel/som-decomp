.setcpu "65816"
.segment "CODE"
.org $4F3E
map_control_0e4f3e:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
