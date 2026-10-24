.setcpu "65816"
.segment "CODE"
.org $DEAF
map_control_0ddeaf:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
