.setcpu "65816"
.segment "CODE"
.org $F531
map_control_0df531:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
