.setcpu "65816"
.segment "CODE"
.org $660F
map_control_0d660f:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
