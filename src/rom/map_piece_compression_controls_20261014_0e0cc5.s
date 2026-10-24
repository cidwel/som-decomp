.setcpu "65816"
.segment "CODE"
.org $0CC5
map_control_0e0cc5:
    .byte $D2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
