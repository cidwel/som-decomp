.setcpu "65816"
.segment "CODE"
.org $6FE1
map_control_0e6fe1:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
