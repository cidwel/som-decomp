.setcpu "65816"
.segment "CODE"
.org $F5B3
map_control_0ef5b3:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
