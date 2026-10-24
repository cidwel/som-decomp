.setcpu "65816"
.segment "CODE"
.org $3455
map_control_0e3455:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
