.setcpu "65816"
.segment "CODE"
.org $F873
map_control_0ff873:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
