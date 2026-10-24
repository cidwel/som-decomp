.setcpu "65816"
.segment "CODE"
.org $DA73
map_control_0fda73:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
