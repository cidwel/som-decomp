.setcpu "65816"
.segment "CODE"
.org $BA5B
map_control_0fba5b:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
