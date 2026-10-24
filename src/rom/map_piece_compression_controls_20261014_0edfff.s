.setcpu "65816"
.segment "CODE"
.org $DFFF
map_control_0edfff:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
