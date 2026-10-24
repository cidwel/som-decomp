.setcpu "65816"
.segment "CODE"
.org $3C4C
map_control_0c3c4c:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
