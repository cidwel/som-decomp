.setcpu "65816"
.segment "CODE"
.org $F567
map_control_0ff567:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
