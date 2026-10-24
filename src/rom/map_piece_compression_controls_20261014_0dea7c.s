.setcpu "65816"
.segment "CODE"
.org $EA7C
map_control_0dea7c:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
