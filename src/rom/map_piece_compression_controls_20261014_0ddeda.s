.setcpu "65816"
.segment "CODE"
.org $DEDA
map_control_0ddeda:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
