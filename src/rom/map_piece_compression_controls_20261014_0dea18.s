.setcpu "65816"
.segment "CODE"
.org $EA18
map_control_0dea18:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
