.setcpu "65816"
.segment "CODE"
.org $A8C6
map_control_0ea8c6:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
