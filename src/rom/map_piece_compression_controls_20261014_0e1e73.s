.setcpu "65816"
.segment "CODE"
.org $1E73
map_control_0e1e73:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
