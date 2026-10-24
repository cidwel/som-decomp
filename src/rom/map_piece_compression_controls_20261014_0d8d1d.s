.setcpu "65816"
.segment "CODE"
.org $8D1D
map_control_0d8d1d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
