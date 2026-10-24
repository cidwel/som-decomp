.setcpu "65816"
.segment "CODE"
.org $2725
map_control_0c2725:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
