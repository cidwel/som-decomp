.setcpu "65816"
.segment "CODE"
.org $FEAD
map_control_0efead:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
