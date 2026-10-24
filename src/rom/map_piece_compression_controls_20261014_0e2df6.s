.setcpu "65816"
.segment "CODE"
.org $2DF6
map_control_0e2df6:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
