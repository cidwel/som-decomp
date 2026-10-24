.setcpu "65816"
.segment "CODE"
.org $CFA0
map_control_0dcfa0:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
