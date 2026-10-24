.setcpu "65816"
.segment "CODE"
.org $56A6
map_control_0e56a6:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
