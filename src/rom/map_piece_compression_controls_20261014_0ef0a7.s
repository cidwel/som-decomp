.setcpu "65816"
.segment "CODE"
.org $F0A7
map_control_0ef0a7:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
