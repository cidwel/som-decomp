.setcpu "65816"
.segment "CODE"
.org $2E56
map_control_0c2e56:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $C2 ; same-value copy count/distance
