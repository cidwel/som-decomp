.setcpu "65816"
.segment "CODE"
.org $770F
map_control_0e770f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
