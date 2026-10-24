.setcpu "65816"
.segment "CODE"
.org $1D6F
map_control_0e1d6f:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
