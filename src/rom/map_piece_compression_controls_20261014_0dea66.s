.setcpu "65816"
.segment "CODE"
.org $EA66
map_control_0dea66:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
