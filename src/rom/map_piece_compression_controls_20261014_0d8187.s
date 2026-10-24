.setcpu "65816"
.segment "CODE"
.org $8187
map_control_0d8187:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
