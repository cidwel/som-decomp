.setcpu "65816"
.segment "CODE"
.org $178F
map_control_0f178f:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
