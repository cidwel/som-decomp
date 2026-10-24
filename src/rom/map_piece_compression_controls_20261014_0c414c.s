.setcpu "65816"
.segment "CODE"
.org $414C
map_control_0c414c:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
