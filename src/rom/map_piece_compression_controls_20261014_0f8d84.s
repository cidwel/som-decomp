.setcpu "65816"
.segment "CODE"
.org $8D84
map_control_0f8d84:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
