.setcpu "65816"
.segment "CODE"
.org $D5F0
map_control_0dd5f0:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
