.setcpu "65816"
.segment "CODE"
.org $5585
map_control_0f5585:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
