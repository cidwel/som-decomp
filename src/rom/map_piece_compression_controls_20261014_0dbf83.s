.setcpu "65816"
.segment "CODE"
.org $BF83
map_control_0dbf83:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
