.setcpu "65816"
.segment "CODE"
.org $6D6F
map_control_0e6d6f:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
