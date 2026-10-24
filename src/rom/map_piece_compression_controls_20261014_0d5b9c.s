.setcpu "65816"
.segment "CODE"
.org $5B9C
map_control_0d5b9c:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
