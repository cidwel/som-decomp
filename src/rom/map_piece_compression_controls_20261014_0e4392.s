.setcpu "65816"
.segment "CODE"
.org $4392
map_control_0e4392:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
