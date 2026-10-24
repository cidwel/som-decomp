.setcpu "65816"
.segment "CODE"
.org $9580
map_control_0e9580:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
