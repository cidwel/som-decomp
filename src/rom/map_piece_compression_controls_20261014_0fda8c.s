.setcpu "65816"
.segment "CODE"
.org $DA8C
map_control_0fda8c:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
