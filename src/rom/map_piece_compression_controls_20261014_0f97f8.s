.setcpu "65816"
.segment "CODE"
.org $97F8
map_control_0f97f8:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
