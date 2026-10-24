.setcpu "65816"
.segment "CODE"
.org $1353
map_control_0e1353:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
