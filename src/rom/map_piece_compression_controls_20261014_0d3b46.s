.setcpu "65816"
.segment "CODE"
.org $3B46
map_control_0d3b46:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
