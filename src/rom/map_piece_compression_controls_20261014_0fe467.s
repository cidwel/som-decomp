.setcpu "65816"
.segment "CODE"
.org $E467
map_control_0fe467:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
