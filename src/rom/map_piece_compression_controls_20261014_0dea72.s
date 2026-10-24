.setcpu "65816"
.segment "CODE"
.org $EA72
map_control_0dea72:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
