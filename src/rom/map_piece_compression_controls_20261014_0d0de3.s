.setcpu "65816"
.segment "CODE"
.org $0DE3
map_control_0d0de3:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
