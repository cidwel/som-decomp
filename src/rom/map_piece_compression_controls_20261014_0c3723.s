.setcpu "65816"
.segment "CODE"
.org $3723
map_control_0c3723:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
