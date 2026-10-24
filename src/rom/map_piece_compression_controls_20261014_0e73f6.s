.setcpu "65816"
.segment "CODE"
.org $73F6
map_control_0e73f6:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
