.setcpu "65816"
.segment "CODE"
.org $1D58
map_control_0f1d58:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
