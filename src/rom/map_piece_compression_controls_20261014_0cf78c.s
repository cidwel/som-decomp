.setcpu "65816"
.segment "CODE"
.org $F78C
map_control_0cf78c:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
