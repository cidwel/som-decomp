.setcpu "65816"
.segment "CODE"
.org $F19D
map_control_0ef19d:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
