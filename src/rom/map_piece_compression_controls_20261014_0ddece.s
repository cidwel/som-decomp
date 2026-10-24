.setcpu "65816"
.segment "CODE"
.org $DECE
map_control_0ddece:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
