.setcpu "65816"
.segment "CODE"
.org $518C
map_control_0e518c:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
