.setcpu "65816"
.segment "CODE"
.org $9121
map_control_0e9121:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
