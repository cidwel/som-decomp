.setcpu "65816"
.segment "CODE"
.org $F28F
map_control_0df28f:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
