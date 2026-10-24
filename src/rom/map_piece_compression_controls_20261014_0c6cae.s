.setcpu "65816"
.segment "CODE"
.org $6CAE
map_control_0c6cae:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
