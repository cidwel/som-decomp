.setcpu "65816"
.segment "CODE"
.org $1D4C
map_control_0e1d4c:
    .byte $E0 ; previous-row copy escape
    .byte $73 ; row-distance/count
