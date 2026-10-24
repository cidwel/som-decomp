.setcpu "65816"
.segment "CODE"
.org $B387
map_control_0fb387:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
