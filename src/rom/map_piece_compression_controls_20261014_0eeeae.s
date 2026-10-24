.setcpu "65816"
.segment "CODE"
.org $EEAE
map_control_0eeeae:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
