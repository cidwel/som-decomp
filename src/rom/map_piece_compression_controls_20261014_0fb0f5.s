.setcpu "65816"
.segment "CODE"
.org $B0F5
map_control_0fb0f5:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
