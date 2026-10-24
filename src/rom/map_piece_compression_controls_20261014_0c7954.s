.setcpu "65816"
.segment "CODE"
.org $7954
map_control_0c7954:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
