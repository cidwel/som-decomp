.setcpu "65816"
.segment "CODE"
.org $AB93
map_control_0dab93:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
