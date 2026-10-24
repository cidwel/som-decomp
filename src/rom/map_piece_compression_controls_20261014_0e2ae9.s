.setcpu "65816"
.segment "CODE"
.org $2AE9
map_control_0e2ae9:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
