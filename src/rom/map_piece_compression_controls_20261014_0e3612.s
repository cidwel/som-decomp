.setcpu "65816"
.segment "CODE"
.org $3612
map_control_0e3612:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
