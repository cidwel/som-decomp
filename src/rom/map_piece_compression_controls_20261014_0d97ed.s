.setcpu "65816"
.segment "CODE"
.org $97ED
map_control_0d97ed:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
