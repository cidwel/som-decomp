.setcpu "65816"
.segment "CODE"
.org $D39F
map_control_0ed39f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
