.setcpu "65816"
.segment "CODE"
.org $3F77
map_control_0f3f77:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
