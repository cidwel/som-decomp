.setcpu "65816"
.segment "CODE"
.org $5607
map_control_0f5607:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
