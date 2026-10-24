.setcpu "65816"
.segment "CODE"
.org $6DC8
map_control_0e6dc8:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
