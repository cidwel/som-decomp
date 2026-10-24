.setcpu "65816"
.segment "CODE"
.org $1D4F
map_control_0f1d4f:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
