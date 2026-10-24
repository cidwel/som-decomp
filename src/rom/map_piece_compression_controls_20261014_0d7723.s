.setcpu "65816"
.segment "CODE"
.org $7723
map_control_0d7723:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
