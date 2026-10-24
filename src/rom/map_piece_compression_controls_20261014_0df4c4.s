.setcpu "65816"
.segment "CODE"
.org $F4C4
map_control_0df4c4:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
