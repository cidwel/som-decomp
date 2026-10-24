.setcpu "65816"
.segment "CODE"
.org $8F7F
map_control_0e8f7f:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
