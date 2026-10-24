.setcpu "65816"
.segment "CODE"
.org $784F
map_control_0d784f:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
