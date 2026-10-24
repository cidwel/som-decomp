.setcpu "65816"
.segment "CODE"
.org $13A2
map_control_0c13a2:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
