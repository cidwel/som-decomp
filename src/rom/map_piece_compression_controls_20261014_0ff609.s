.setcpu "65816"
.segment "CODE"
.org $F609
map_control_0ff609:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C4 ; same-value copy count/distance
