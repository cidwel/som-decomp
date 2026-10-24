.setcpu "65816"
.segment "CODE"
.org $255E
map_control_0e255e:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
