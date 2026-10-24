.setcpu "65816"
.segment "CODE"
.org $ADFA
map_control_0fadfa:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
