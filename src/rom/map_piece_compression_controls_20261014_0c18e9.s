.setcpu "65816"
.segment "CODE"
.org $18E9
map_control_0c18e9:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
