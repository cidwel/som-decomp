.setcpu "65816"
.segment "CODE"
.org $1D58
map_control_0d1d58:
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
