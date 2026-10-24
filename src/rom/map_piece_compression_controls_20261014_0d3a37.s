.setcpu "65816"
.segment "CODE"
.org $3A37
map_control_0d3a37:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
