.setcpu "65816"
.segment "CODE"
.org $720F
map_control_0d720f:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
