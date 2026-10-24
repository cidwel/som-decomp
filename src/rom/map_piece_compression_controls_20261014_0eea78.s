.setcpu "65816"
.segment "CODE"
.org $EA78
map_control_0eea78:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
