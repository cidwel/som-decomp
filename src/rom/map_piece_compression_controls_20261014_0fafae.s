.setcpu "65816"
.segment "CODE"
.org $AFAE
map_control_0fafae:
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
