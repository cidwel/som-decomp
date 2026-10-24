.setcpu "65816"
.segment "CODE"
.org $F88E
map_control_0ff88e:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
