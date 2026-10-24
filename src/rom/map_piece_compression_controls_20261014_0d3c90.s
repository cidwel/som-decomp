.setcpu "65816"
.segment "CODE"
.org $3C90
map_control_0d3c90:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
