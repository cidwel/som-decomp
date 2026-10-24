.setcpu "65816"
.segment "CODE"
.org $EA3A
map_control_0dea3a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
