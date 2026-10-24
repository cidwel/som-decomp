.setcpu "65816"
.segment "CODE"
.org $3A8D
map_control_0e3a8d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
