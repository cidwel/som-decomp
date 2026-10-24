.setcpu "65816"
.segment "CODE"
.org $1D9F
map_control_0d1d9f:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
