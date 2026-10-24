.setcpu "65816"
.segment "CODE"
.org $CAD9
map_control_0ecad9:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
