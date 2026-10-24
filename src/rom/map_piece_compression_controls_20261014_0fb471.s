.setcpu "65816"
.segment "CODE"
.org $B471
map_control_0fb471:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
