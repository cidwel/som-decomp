.setcpu "65816"
.segment "CODE"
.org $6470
map_control_0c6470:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
