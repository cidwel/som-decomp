.setcpu "65816"
.segment "CODE"
.org $2AB1
map_control_0c2ab1:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
