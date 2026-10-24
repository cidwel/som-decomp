.setcpu "65816"
.segment "CODE"
.org $CFA4
map_control_0dcfa4:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
