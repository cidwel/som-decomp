.setcpu "65816"
.segment "CODE"
.org $2DE9
map_control_0f2de9:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
