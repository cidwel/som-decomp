.setcpu "65816"
.segment "CODE"
.org $DEAD
map_control_0edead:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
