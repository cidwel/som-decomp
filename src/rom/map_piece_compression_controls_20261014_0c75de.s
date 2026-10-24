.setcpu "65816"
.segment "CODE"
.org $75DE
map_control_0c75de:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
