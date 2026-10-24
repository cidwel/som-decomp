.setcpu "65816"
.segment "CODE"
.org $66DE
map_control_0d66de:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
