.setcpu "65816"
.segment "CODE"
.org $6357
map_control_0e6357:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
