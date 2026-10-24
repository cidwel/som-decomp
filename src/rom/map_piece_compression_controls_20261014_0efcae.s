.setcpu "65816"
.segment "CODE"
.org $FCAE
map_control_0efcae:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
