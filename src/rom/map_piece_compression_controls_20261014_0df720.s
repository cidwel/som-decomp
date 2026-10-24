.setcpu "65816"
.segment "CODE"
.org $F720
map_control_0df720:
    .byte $E0 ; previous-row copy escape
    .byte $BE ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
