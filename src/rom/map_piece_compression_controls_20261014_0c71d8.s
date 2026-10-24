.setcpu "65816"
.segment "CODE"
.org $71D8
map_control_0c71d8:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
