.setcpu "65816"
.segment "CODE"
.org $20A2
map_control_0e20a2:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
