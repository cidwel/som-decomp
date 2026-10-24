.setcpu "65816"
.segment "CODE"
.org $3405
map_control_0d3405:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
