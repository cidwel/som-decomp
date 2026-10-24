.setcpu "65816"
.segment "CODE"
.org $877B
map_control_0d877b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
