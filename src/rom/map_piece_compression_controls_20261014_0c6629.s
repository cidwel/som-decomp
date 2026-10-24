.setcpu "65816"
.segment "CODE"
.org $6629
map_control_0c6629:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
