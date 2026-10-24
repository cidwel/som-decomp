.setcpu "65816"
.segment "CODE"
.org $1D35
map_control_0e1d35:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
