.setcpu "65816"
.segment "CODE"
.org $F1BE
map_control_0ef1be:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
