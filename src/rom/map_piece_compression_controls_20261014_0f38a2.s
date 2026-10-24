.setcpu "65816"
.segment "CODE"
.org $38A2
map_control_0f38a2:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
