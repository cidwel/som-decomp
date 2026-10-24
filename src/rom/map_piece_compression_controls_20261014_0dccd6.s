.setcpu "65816"
.segment "CODE"
.org $CCD6
map_control_0dccd6:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
