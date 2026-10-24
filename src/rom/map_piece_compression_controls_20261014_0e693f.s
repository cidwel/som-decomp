.setcpu "65816"
.segment "CODE"
.org $693F
map_control_0e693f:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
