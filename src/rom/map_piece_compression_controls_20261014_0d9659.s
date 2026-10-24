.setcpu "65816"
.segment "CODE"
.org $9659
map_control_0d9659:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
