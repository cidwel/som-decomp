.setcpu "65816"
.segment "CODE"
.org $26BC
map_control_0e26bc:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
