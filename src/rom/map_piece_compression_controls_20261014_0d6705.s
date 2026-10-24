.setcpu "65816"
.segment "CODE"
.org $6705
map_control_0d6705:
    .byte $D1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
