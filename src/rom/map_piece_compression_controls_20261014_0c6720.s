.setcpu "65816"
.segment "CODE"
.org $6720
map_control_0c6720:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
