.setcpu "65816"
.segment "CODE"
.org $16C4
map_control_0c16c4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
