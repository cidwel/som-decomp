.setcpu "65816"
.segment "CODE"
.org $11ED
map_control_0c11ed:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
