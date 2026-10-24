.setcpu "65816"
.segment "CODE"
.org $F5C4
map_control_0ef5c4:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
