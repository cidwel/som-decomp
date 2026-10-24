.setcpu "65816"
.segment "CODE"
.org $40CB
map_control_0e40cb:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
