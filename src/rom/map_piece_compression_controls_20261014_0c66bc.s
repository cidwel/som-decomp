.setcpu "65816"
.segment "CODE"
.org $66BC
map_control_0c66bc:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
