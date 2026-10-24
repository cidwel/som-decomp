.setcpu "65816"
.segment "CODE"
.org $E89F
map_control_0fe89f:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
