.setcpu "65816"
.segment "CODE"
.org $EA9C
map_control_0eea9c:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
