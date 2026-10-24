.setcpu "65816"
.segment "CODE"
.org $0EC0
map_control_0e0ec0:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
