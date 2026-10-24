.setcpu "65816"
.segment "CODE"
.org $7999
map_control_0e7999:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
