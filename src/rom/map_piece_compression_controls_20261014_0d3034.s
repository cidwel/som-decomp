.setcpu "65816"
.segment "CODE"
.org $3034
map_control_0d3034:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
