.setcpu "65816"
.segment "CODE"
.org $97F3
map_control_0d97f3:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
