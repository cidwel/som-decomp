.setcpu "65816"
.segment "CODE"
.org $3C9C
map_control_0d3c9c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
