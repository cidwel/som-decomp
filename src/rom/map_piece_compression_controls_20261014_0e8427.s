.setcpu "65816"
.segment "CODE"
.org $8427
map_control_0e8427:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
