.setcpu "65816"
.segment "CODE"
.org $84CC
map_control_0e84cc:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
