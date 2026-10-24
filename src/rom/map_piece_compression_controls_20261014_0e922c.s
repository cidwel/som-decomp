.setcpu "65816"
.segment "CODE"
.org $922C
map_control_0e922c:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
