.setcpu "65816"
.segment "CODE"
.org $5FE1
map_control_0d5fe1:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
