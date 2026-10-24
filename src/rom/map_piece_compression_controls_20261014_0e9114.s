.setcpu "65816"
.segment "CODE"
.org $9114
map_control_0e9114:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
