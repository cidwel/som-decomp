.setcpu "65816"
.segment "CODE"
.org $DFA4
map_control_0ddfa4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
