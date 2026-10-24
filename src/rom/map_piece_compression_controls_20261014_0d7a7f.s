.setcpu "65816"
.segment "CODE"
.org $7A7F
map_control_0d7a7f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
