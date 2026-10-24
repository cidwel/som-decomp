.setcpu "65816"
.segment "CODE"
.org $8F3F
map_control_0e8f3f:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
