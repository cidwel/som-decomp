.setcpu "65816"
.segment "CODE"
.org $2B5F
map_control_0d2b5f:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
