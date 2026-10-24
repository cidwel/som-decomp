.setcpu "65816"
.segment "CODE"
.org $CAE0
map_control_0ecae0:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
