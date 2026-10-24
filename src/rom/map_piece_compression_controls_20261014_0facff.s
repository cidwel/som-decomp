.setcpu "65816"
.segment "CODE"
.org $ACFF
map_control_0facff:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
