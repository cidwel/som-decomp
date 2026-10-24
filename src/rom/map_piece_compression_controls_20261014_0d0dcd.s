.setcpu "65816"
.segment "CODE"
.org $0DCD
map_control_0d0dcd:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
