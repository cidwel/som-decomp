.setcpu "65816"
.segment "CODE"
.org $75BE
map_control_0e75be:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
