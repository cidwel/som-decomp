.setcpu "65816"
.segment "CODE"
.org $935C
map_control_0e935c:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
