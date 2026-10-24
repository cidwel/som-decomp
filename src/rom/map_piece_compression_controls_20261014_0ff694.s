.setcpu "65816"
.segment "CODE"
.org $F694
map_control_0ff694:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
