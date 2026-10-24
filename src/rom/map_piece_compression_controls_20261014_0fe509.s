.setcpu "65816"
.segment "CODE"
.org $E509
map_control_0fe509:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
