.setcpu "65816"
.segment "CODE"
.org $E093
map_control_0fe093:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
