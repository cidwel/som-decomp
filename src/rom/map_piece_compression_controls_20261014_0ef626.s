.setcpu "65816"
.segment "CODE"
.org $F626
map_control_0ef626:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
