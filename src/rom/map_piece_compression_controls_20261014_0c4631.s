.setcpu "65816"
.segment "CODE"
.org $4631
map_control_0c4631:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
