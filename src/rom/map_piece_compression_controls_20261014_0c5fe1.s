.setcpu "65816"
.segment "CODE"
.org $5FE1
map_control_0c5fe1:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
