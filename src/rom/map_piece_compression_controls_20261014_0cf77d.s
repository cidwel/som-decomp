.setcpu "65816"
.segment "CODE"
.org $F77D
map_control_0cf77d:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
