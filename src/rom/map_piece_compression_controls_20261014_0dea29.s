.setcpu "65816"
.segment "CODE"
.org $EA29
map_control_0dea29:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
