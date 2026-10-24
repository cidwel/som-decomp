.setcpu "65816"
.segment "CODE"
.org $7A8D
map_control_0c7a8d:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
