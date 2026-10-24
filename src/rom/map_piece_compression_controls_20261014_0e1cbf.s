.setcpu "65816"
.segment "CODE"
.org $1CBF
map_control_0e1cbf:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
