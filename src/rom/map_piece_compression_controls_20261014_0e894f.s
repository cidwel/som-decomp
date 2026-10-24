.setcpu "65816"
.segment "CODE"
.org $894F
map_control_0e894f:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
