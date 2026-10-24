.setcpu "65816"
.segment "CODE"
.org $EDB3
map_control_0eedb3:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
