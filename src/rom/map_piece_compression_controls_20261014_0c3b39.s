.setcpu "65816"
.segment "CODE"
.org $3B39
map_control_0c3b39:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
