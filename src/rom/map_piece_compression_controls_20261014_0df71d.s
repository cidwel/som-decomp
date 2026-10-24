.setcpu "65816"
.segment "CODE"
.org $F71D
map_control_0df71d:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
