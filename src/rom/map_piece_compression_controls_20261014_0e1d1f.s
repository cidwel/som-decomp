.setcpu "65816"
.segment "CODE"
.org $1D1F
map_control_0e1d1f:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
