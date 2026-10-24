.setcpu "65816"
.segment "CODE"
.org $852B
map_control_0c852b:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
