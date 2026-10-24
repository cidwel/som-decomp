.setcpu "65816"
.segment "CODE"
.org $ADBA
map_control_0fadba:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
