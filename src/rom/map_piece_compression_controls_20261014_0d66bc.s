.setcpu "65816"
.segment "CODE"
.org $66BC
map_control_0d66bc:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
