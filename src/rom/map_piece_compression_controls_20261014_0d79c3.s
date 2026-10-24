.setcpu "65816"
.segment "CODE"
.org $79C3
map_control_0d79c3:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
