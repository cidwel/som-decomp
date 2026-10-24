.setcpu "65816"
.segment "CODE"
.org $40C2
map_control_0e40c2:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
