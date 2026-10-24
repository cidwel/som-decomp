.setcpu "65816"
.segment "CODE"
.org $EBD7
map_control_0debd7:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
