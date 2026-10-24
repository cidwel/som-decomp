.setcpu "65816"
.segment "CODE"
.org $1D81
map_control_0f1d81:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
