.setcpu "65816"
.segment "CODE"
.org $D470
map_control_0fd470:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
