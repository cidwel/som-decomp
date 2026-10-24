.setcpu "65816"
.segment "CODE"
.org $44BC
map_control_0e44bc:
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
