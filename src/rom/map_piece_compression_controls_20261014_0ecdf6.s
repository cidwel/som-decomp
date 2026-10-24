.setcpu "65816"
.segment "CODE"
.org $CDF6
map_control_0ecdf6:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
