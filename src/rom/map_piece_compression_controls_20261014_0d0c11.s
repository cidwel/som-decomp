.setcpu "65816"
.segment "CODE"
.org $0C11
map_control_0d0c11:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
