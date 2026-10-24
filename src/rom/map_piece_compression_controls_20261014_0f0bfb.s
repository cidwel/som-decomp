.setcpu "65816"
.segment "CODE"
.org $0BFB
map_control_0f0bfb:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
