.setcpu "65816"
.segment "CODE"
.org $FCCE
map_control_0efcce:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
