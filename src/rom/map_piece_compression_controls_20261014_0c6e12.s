.setcpu "65816"
.segment "CODE"
.org $6E12
map_control_0c6e12:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
