.setcpu "65816"
.segment "CODE"
.org $538F
map_control_0d538f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
