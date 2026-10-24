.setcpu "65816"
.segment "CODE"
.org $EA8A
map_control_0dea8a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
