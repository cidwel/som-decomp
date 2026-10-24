.setcpu "65816"
.segment "CODE"
.org $127F
map_control_0d127f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
