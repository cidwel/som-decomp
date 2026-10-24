.setcpu "65816"
.segment "CODE"
.org $5106
map_control_0e5106:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
